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
        horaInicio = stod(sDuracao, &sz);
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