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
        int iniciomin=00;
        int finalmin=00;
        int inicioint=(int)(it.retrieve().getHorarioInicio()*10);
        if (inicioint%10!=0){iniciomin=30;}
        inicioint/=10;
        int finalint=(int)(it.retrieve().getHorarioFim()*10);
        if (finalint%10!=0){finalmin=30;}
        finalint/=10;
        string iniciomins,finalmins;
        if(iniciomin==0){iniciomins="00";}
        else{iniciomins= to_string(iniciomin);}
        if(finalmin==0){finalmins="00";}
        else{finalmins= to_string(finalmin);}
        cout << it.retrieve().getDiaDaSemana() << " | " << inicioint <<":"<< iniciomins << " -> " << finalint <<":"<< finalmins << " | " << it.retrieve().getTipo() << "\n";
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