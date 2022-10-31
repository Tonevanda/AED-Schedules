//
// Created by tomas on 30/10/2022.
//

#include "TurmaH.h"

TurmaH::TurmaH(std::string codUC, std::string codTurma) {
    this->codUC = codUC;
    this->codTurma = codTurma;
}

string TurmaH::getCodUc() const {
    return codUC;
}
string TurmaH::getCodTurma() const {
    return codTurma;
}
BST<Slot> TurmaH::getHorario() const {
    return horario;
}

void TurmaH::addSlot(Slot slot) {
    horario.insert(slot);
}

void TurmaH::showHorario() {
    BSTItrIn<Slot> it = BSTItrIn<Slot> (horario);
    while(!it.isAtEnd()){
        cout << it.retrieve().getDiaDaSemana() << " | " << it.retrieve().getHorarioInicio() << " -> " << it.retrieve().getHorarioFim() << " | " << it.retrieve().getTipo() << "\n";
        it.advance();
    }
}

bool TurmaH::operator<(const TurmaH &s2) const {
    if(codUC == s2.codUC){
        return codTurma < s2.codTurma;
    }
    return codUC < s2.codUC;
}

bool TurmaH::operator>(const TurmaH &s2) const {
    if(codUC == s2.codUC){
        return codTurma > s2.codTurma;
    }
    return codUC > s2.codUC;
}

bool TurmaH::operator==(const TurmaH &s2) const {
    if(codUC == s2.codUC){
        return codTurma == s2.codTurma;
    }
    return codUC == s2.codUC;
}

bool TurmaH::operator!=(const TurmaH &s2) const {
    if(codUC == s2.codUC){
        return codTurma != s2.codTurma;
    }
    return codUC != s2.codUC;
}