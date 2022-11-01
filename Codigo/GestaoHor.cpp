//
// Created by Tiago Cruz on 31/10/2022.
//

#include "GestaoHor.h"
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>

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

BST<TurmaH> GestaoHor::getHorarios() const{
    return horarios;
}

bool GestaoHor::addAluno(TurmaH turma) {
    turma = horarios.find(turma);
    if(turma.getnAlunos()>= 30) return false;
    horarios.remove(turma);
    turma.addAluno();
    horarios.insert(turma);
    return true;
}

bool GestaoHor::addAluno(std::string UcCode, std::string ClassCode) {
    TurmaH temp = TurmaH(UcCode, ClassCode);
    temp = horarios.find(temp);
    if(temp.getnAlunos()>= 30) return false;
    horarios.remove(temp);
    temp.addAluno();
    horarios.insert(temp);
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
/* Para mudar de turma ig
    int nAlunoAtual = temp.getnAlunos();

    BSTItrIn<TurmaH> it = BSTItrIn<TurmaH>(horarios);
    while(it.retrieve().getCodUc() != UcCode){
        it.advance();
    }
    while (it.retrieve().getCodUc() == UcCode){
        if(it.retrieve().getnAlunos()-nAlunoAtual >= 4)
    }
 */

void GestaoHor::shownAlunosUC(string UcCode){
    TurmaH temp = TurmaH(UcCode, "");
    temp = horarios.find(temp);
    //...
}
void GestaoHor::shownAlunos(std::string UcCode, std::string ClassCode) {
    TurmaH temp = TurmaH(UcCode, ClassCode);
    TurmaH finder = horarios.find(temp);
    cout << "A cadeira " << UcCode << " da turma " << ClassCode << " tem: " << finder.getnAlunos() << " alunos.\n";
}
void GestaoHor::showUCTHorario(string UcCode, string ClassCode) {
    TurmaH turma = TurmaH(UcCode, ClassCode);
    turma = horarios.find(turma);
    BST<Slot> hor = turma.getHorario();
    BSTItrIn<Slot> it = BSTItrIn<Slot> (hor);
    while(!it.isAtEnd()){
        cout << it.retrieve().getDiaDaSemana() << " " << it.retrieve().getHorarioInicio() << " " << it.retrieve().getHorarioFim() << " " << it.retrieve().getTipo() << "\n";
        it.advance();
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