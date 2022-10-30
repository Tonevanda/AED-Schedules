//
// Created by tomas on 30/10/2022.
//

#include "UCTurma.h"

UCTurma::UCTurma(string codeUC, string codeTurma){
    this->codUC = codeUC;
    this->codTurma = codeTurma;
}

void UCTurma::mudarTurma(string novaTurma) {
    codTurma = novaTurma;
}

string UCTurma::getUC() const {
    return codUC;
}
string UCTurma::getTurma() const {
    return codTurma;
}

