//
// Created by Tiago Cruz on 31/10/2022.
//

#include "GestaoHor.h"
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
/**
 * Lê o ficheiro e insere as turmas lidas na BST correspondente
 * Time-complexity -> O(nlog(n))
 */
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
/**
 * Lê os horários das UCs do ficheiro e insere na BST correspondente
 * Time-complexity -> O(nlog(n))
 */
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
/**
 * Verifica se o código de UC inserido existe na BST
 * Time-complexity -> O(n)
 * @param UcCode
 * @return
 */
bool GestaoHor::isValidUC(string UcCode) {
    BSTItrIn<TurmaH> it = horarios;
    while(!it.isAtEnd()){
        if(it.retrieve().getCodUc()==UcCode) return true;
        it.advance();
    }
    return false;
}
/**
 * Verifica se o código de turma inserido existe na BST
 * Time-complexity -> O(log(n))
 */
bool GestaoHor::isValidTurma(string UcCode, string classCode){
    //if(!isValidUC(UcCode)) return false;
    TurmaH turmah = TurmaH(UcCode, classCode);
    turmah = horarios.find(turmah);
    if(turmah.getCodUc() == "") return false;
    return true;
}
/**
 * Retorna a BST com os horários da turma
 * Time-complexity -> O(1)
 * @return
 */
BST<TurmaH> GestaoHor::getHorarios() const{
    return horarios;
}
/**
 * Adiciona um aluno a uma TurmaH (UC e turma respetiva) e atualiza a BST correspondente
 * Time-complexity -> O(log(n))
 * @param turma
 * @return
 */
bool GestaoHor::addAluno(TurmaH turma) {
    turma = horarios.find(turma);
    horarios.remove(turma);
    turma.addAluno();
    horarios.insert(turma);
    return true;
}
/**
 * Adiciona um aluno a uma UC e turma respetiva e atualiza a BST correspondente
 * Time-complexity -> O(log(n))
 * @param UcCode
 * @param ClassCode
 * @return
 */
bool GestaoHor::addAluno(std::string UcCode, std::string ClassCode) {
    TurmaH turma = TurmaH(UcCode, ClassCode);
    turma = horarios.find(turma);
    horarios.remove(turma);
    turma.addAluno();
    horarios.insert(turma);
    return true;
}
/**
 * Remove um aluno de uma TurmaH (UC e turma respetiva) e atualiza a BST correspondente
 * Time-complexity -> O(log(n))
 * @param turma
 */
void GestaoHor::removeAluno(TurmaH turma) {
    turma = horarios.find(turma);
    horarios.remove(turma);
    turma.removeAluno();
    horarios.insert(turma);
}
/**
 * Remove um aluno de uma UC e turma respetiva e atualiza a BST correspondente
 * Time-complexity -> O(log(n))
 * @param UcCode
 * @param ClassCode
 */
void GestaoHor::removeAluno(std::string UcCode, std::string ClassCode) {
    TurmaH temp = TurmaH(UcCode, ClassCode);
    temp = horarios.find(temp);
    horarios.remove(temp);
    temp.removeAluno();
    horarios.insert(temp);
}
/**
 * Verifica se o pedido para mudar de turma é válido
 * Time-complexity -> O(nlog(n))
 * @param turma
 * @param Courses
 * @param oldTurma
 * @return
 */
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
/**
 * Verifica se o pedido para mudar de turma é válido (parâmetros alternativos)
 * Time-complexity -> O(log(n))
 * @param UcCode
 * @param ClassCode
 * @param Courses
 * @param oldClassCode
 * @return
 */
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
/**
 * Retorna o número de alunos da turma com menos alunos
 * Time-complexity -> O(n)
 * @param UcCode
 * @return
 */
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
/**
 * Printa todas as UCs num dado ano
 * Time-complexity -> O(n)
 * @param year
 */
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
/**
 * Printa o número de alunos inscritos numa cadeira
 * Time-complexity -> O(n)
 * @param UcCode
 */
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
/**
 * Printa o número de alunos inscritos numa turma de uma cadeira
 * Time-complexity -> O(log(n))
 * @param UcCode
 * @param ClassCode
 */
void GestaoHor::shownAlunos(std::string UcCode, std::string ClassCode) {
    TurmaH temp = TurmaH(UcCode, ClassCode);
    TurmaH finder = horarios.find(temp);
    cout << "The UC " << UcCode << " of the class " << ClassCode << " has: " << finder.getnAlunos() << " students.\n";
}
/**
 * Printa o dia da semana, horário de início e fim (formato hh:mm) e tipo (T, TP e PL) de uma UC de uma turma
 * Time-complexity -> O(n)
 * @param UcCode
 * @param ClassCode
 */
void GestaoHor::showUCTHorario(string UcCode, string ClassCode) {
    TurmaH turma = TurmaH(UcCode, ClassCode);
    turma = horarios.find(turma);
    vector<Slot> hor = turma.getHorario();

    for(auto it: hor){
        cout << it.getDiaDaSemana() << " " << it.getHorarioInicio() << " " << it.getHorarioFim() << " " << it.getTipo() << "\n";
    }
}
/**
 * Printa a UC, turma, e o seu respetivo horário
 * Time-complexity -> O(n)
 */
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