//
// Created by Tiago Cruz on 31/10/2022.
//

#include "GestaoHor.h"
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>

void GestaoHor::insertTurmas() {
    ifstream fout;
    fout.open("../classes_per_uc.csv");
    string tempstream, UcCode, ClassCode;
    getline (fout, tempstream);

    while(getline(fout, tempstream)){
        stringstream it_stream(tempstream);
        getline(it_stream, UcCode, ',');
        getline(it_stream, ClassCode, '\r');
        TurmaH turma = TurmaH(UcCode, ClassCode);
        horarios.insert(turma);
    }
    fout.close();
}

void GestaoHor::insertSchedule() {
    ifstream fout;
    double horaInicio, duracao;
    fout.open("../classes.csv");
    string tempstream, ClassCode, UcCode, diaDaSemana, sHoraInicio, sDuracao, tipo;
    size_t sz;
    getline (fout, tempstream);

    while (getline (fout, tempstream)) {
        stringstream it_stream(tempstream);
        getline(it_stream, ClassCode, ',');
        getline(it_stream, UcCode, ',');
        getline(it_stream, diaDaSemana, ',');
        getline(it_stream, sHoraInicio, ',');
        getline(it_stream, sDuracao, ',');
        getline(it_stream, tipo, '\r');
        horaInicio = stod(sHoraInicio, &sz);
        duracao = stod(sDuracao, &sz);
        double horaFim = horaInicio + duracao;
        TurmaH horario = TurmaH(UcCode, ClassCode);
        Slot slot = Slot(diaDaSemana, horaInicio, horaFim, tipo);
        TurmaH test = horarios.find(horario);

        if (!horarios.isEmpty() && horario == test) {
            horarios.remove(test);
            test.addSlot(slot);
            horarios.insert(test);
        } else {
            horario.addSlot(slot);
            horarios.insert(horario);
        }
    }
    fout.close();
}

bool GestaoHor::isValidUC(string UcCode) {
    BSTItrIn<TurmaH> it = horarios;
    while(!it.isAtEnd()){
        if(it.retrieve().getCodUc()==UcCode) return true;
        it.advance();
    }
    return false;
}

bool GestaoHor::isValidTurma(string UcCode, string classCode){
    //if(!isValidUC(UcCode)) return false;
    TurmaH turmah = TurmaH(UcCode, classCode);
    turmah = horarios.find(turmah);
    if(turmah.getCodUc() == "") return false;
    return true;
}

BST<TurmaH> GestaoHor::getHorarios() const{
    return horarios;
}

bool GestaoHor::addAluno(TurmaH turma) {
    turma = horarios.find(turma);
    horarios.remove(turma);
    turma.addAluno();
    horarios.insert(turma);
    return true;
}

bool GestaoHor::addAluno(std::string UcCode, std::string ClassCode) {
    TurmaH turma = TurmaH(UcCode, ClassCode);
    turma = horarios.find(turma);
    horarios.remove(turma);
    turma.addAluno();
    horarios.insert(turma);
    return true;
}

void GestaoHor::removeAluno(TurmaH turma) {
    turma = horarios.find(turma);
    horarios.remove(turma);
    turma.removeAluno();
    horarios.insert(turma);
}

void GestaoHor::removeAluno(std::string UcCode, std::string ClassCode) {
    TurmaH temp = TurmaH(UcCode, ClassCode);
    temp = horarios.find(temp);
    horarios.remove(temp);
    temp.removeAluno();
    horarios.insert(temp);
}

bool GestaoHor::canChangeTurma(TurmaH turma, vector<UCTurma> Courses, TurmaH oldTurma) {
    turma = horarios.find(turma);
    int oldTurmaAlunos = INT_MAX;
    if (oldTurma != TurmaH()) {
        oldTurma = horarios.find(oldTurma);
        oldTurmaAlunos = oldTurma.getnAlunos();
    }

    if(turma.getnAlunos()>= 30){
        cout << "Class is full\n";
        return false;
    }
    else if(turma.getnAlunos()+1 - findMinAlunos(turma.getCodUc()) >= 4 || turma.getnAlunos()+1 - oldTurmaAlunos-1 >= 4){
        cout << "You cannot join this class since it would cause an imbalance of students between the classes\n";
        return false;
    }

    for(auto it: Courses){
        TurmaH temp = TurmaH(it.getUC(), it.getTurma()); // Temp = TurmaH(UcCode, ClassCode, 0, Vector<Slot> vazio)
        temp = horarios.find(temp); // Encontra em horarios o objeto com UcCode / ClassCode igual -> temp = (UcCode, ClassCode, nAlunos, Vector<Slot> preenchido)
        for(auto horario_antigo: temp.getHorario()){
            if (horario_antigo.getTipo() != "T"){
                for(auto horNovo : turma.getHorario()){
                    if(horNovo.getDiaDaSemana() == horario_antigo.getDiaDaSemana() && horNovo.getTipo() != "T"){
                        if(horario_antigo.getHorarioInicio() < horNovo.getHorarioFim() && horario_antigo.getHorarioInicio()>=horNovo.getHorarioInicio()){ //10.50 < 11:50 && 10.50 >= 9:50
                            cout << "You cannot change classes since the schedules would overlap\n";
                            return false;
                        }
                    }
                }
            }
        }


    }

    return true;
}

bool GestaoHor::canChangeTurma(string UcCode, string ClassCode,vector<UCTurma> Courses, string oldClassCode) {
    TurmaH turma = TurmaH(UcCode, ClassCode);
    TurmaH oldTurma = TurmaH(UcCode, oldClassCode);
    turma = horarios.find(turma);
    int oldTurmaAlunos = INT_MAX;
    if (oldTurma != TurmaH()) {
        oldTurma = horarios.find(oldTurma);
        oldTurmaAlunos = oldTurma.getnAlunos();
    }

    if(turma.getnAlunos()>= 30){
        cout << "Class is full\n";
        return false;
    }
    else if(turma.getnAlunos()+1 - findMinAlunos(turma.getCodUc()) >= 4 || turma.getnAlunos()+1 - oldTurmaAlunos-1 >= 4){
        cout << "You cannot join this class since it would cause an imbalance of students between the classes\n";
        return false;
    }

    for(auto it: Courses){
        TurmaH temp = TurmaH(it.getUC(), it.getTurma()); // Temp = TurmaH(UcCode, ClassCode, 0, Vector<Slot> vazio)
        temp = horarios.find(temp); // Encontra em horarios o objeto com UcCode / ClassCode igual -> temp = (UcCode, ClassCode, nAlunos, Vector<Slot> preenchido)
        for(auto horario_antigo: temp.getHorario()){
            if (horario_antigo.getTipo() != "T"){
                for(auto horNovo : turma.getHorario()){
                    if(horNovo.getDiaDaSemana() == horario_antigo.getDiaDaSemana() && horNovo.getTipo() != "T"){
                        if(horario_antigo.getHorarioInicio() < horNovo.getHorarioFim() && horario_antigo.getHorarioInicio()>=horNovo.getHorarioInicio()){ //10.50 < 11:50 && 10.50 >= 9:50
                            cout << "You cannot change classes since the schedules would overlap\n";
                            return false;
                        }
                    }
                }
            }
        }


    }
    return true;
}

int GestaoHor::findMinAlunos(std::string UcCode) {
    int min = INT_MAX;

    BSTItrIn<TurmaH> it = horarios;
    while(!it.isAtEnd()){
        if(it.retrieve().getCodUc()==UcCode){
            if(it.retrieve().getnAlunos()<min) min = it.retrieve().getnAlunos();
        }
        it.advance();
    }
    return min;
}

void GestaoHor::showAllUCinYear(char year) {
    bool flag = false;
    string codUc;
    BSTItrIn<TurmaH> it = BSTItrIn<TurmaH>(horarios);
    while(!it.isAtEnd()) {
        if (it.retrieve().getCodTurma()[0] == year) {
            codUc = it.retrieve().getCodUc();
            cout << codUc << "\n";
        }
        while (it.retrieve().getCodUc() == codUc) {
            it.advance();
            flag = true;
        }
        if (!flag) {
            it.advance();
        }
        flag = false;
    }
}

void GestaoHor::shownAlunosUC(string UcCode){
    BSTItrIn<TurmaH> it = horarios;
    int val = 0;
    while(!it.isAtEnd()){
        if(it.retrieve().getCodUc() == UcCode){
            val += it.retrieve().getnAlunos();
        }
        it.advance();
    }
    cout << "There are " << val << " students in " << UcCode << "\n";
}

void GestaoHor::shownAlunos(std::string UcCode, std::string ClassCode) {
    TurmaH temp = TurmaH(UcCode, ClassCode);
    TurmaH finder = horarios.find(temp);
    cout << "The UC " << UcCode << " of the class " << ClassCode << " has: " << finder.getnAlunos() << " students.\n";
}

void GestaoHor::showUCTHorario(string UcCode, string ClassCode) {
    TurmaH turma = TurmaH(UcCode, ClassCode);
    turma = horarios.find(turma);
    vector<Slot> hor = turma.getHorario();

    for(auto it: hor){
        cout << it.getDiaDaSemana() << " " << it.getHorarioInicio() << " " << it.getHorarioFim() << " " << it.getTipo() << "\n";
    }
}

void GestaoHor::showUCTandHorario() {
    BSTItrIn<TurmaH> it = BSTItrIn<TurmaH> (horarios);
    while(!it.isAtEnd()) {
        string codUc = it.retrieve().getCodUc();
        string codTurma = it.retrieve().getCodTurma();
        cout << codUc << " " << codTurma << ":\n";
        showUCTHorario(codUc, codTurma);
        cout << "\n";
        it.advance();
    }
}