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

bool UCTurma::operator<(const UCTurma &s2) const {
    return codUC < s2.codUC;
}

bool UCTurma::operator>(const UCTurma &s2) const {
    return codUC > s2.codUC;
}

bool UCTurma::operator==(const UCTurma &s2) const {
    return codUC == s2.codUC;
}

bool UCTurma::operator!=(const UCTurma &s2) const {
    return codUC != s2.codUC;
}

