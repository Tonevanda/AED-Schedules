//
// Created by tomas on 30/10/2022.
//

#include "UCTurma.h"
/**
 * Construtor da classe UCTurma constituído por uma UC e a sua respetiva turma
 * @param codeUC
 * @param codeTurma
 */
UCTurma::UCTurma(string codeUC, string codeTurma){
    this->codUC = codeUC;
    this->codTurma = codeTurma;
}
/**
 * Muda a turma a atual para a turma inserida
 * @param novaTurma
 */
void UCTurma::mudarTurma(string novaTurma) {
    codTurma = novaTurma;
}
/**
 * Retorna a UC
 * @return
 */
string UCTurma::getUC() const {
    return codUC;
}
/**
 * Retorna a turma
 * @return
 */
string UCTurma::getTurma() const {
    return codTurma;
}

/**
 * Override ao operador <. Verifica se o código da UC é menor que o código da UC2
 * @param s2
 * @return
 */
bool UCTurma::operator<(const UCTurma &s2) const {
    return codUC < s2.codUC;
}
/**
 * Override ao operador >. Verifica se o código da UC é maior que o código da UC2
 * @param s2
 * @return
 */
bool UCTurma::operator>(const UCTurma &s2) const {
    return codUC > s2.codUC;
}
/**
 * Override ao operador ==. Verifica se o código da UC é igual ao código da UC2
 * @param s2
 * @return
 */
bool UCTurma::operator==(const UCTurma &s2) const {
    return codUC == s2.codUC;
}
/**
 * Override ao operador !=. Verifica se o código da UC é diferente do código da UC2
 * @param s2
 * @return
 */
bool UCTurma::operator!=(const UCTurma &s2) const {
    return codUC != s2.codUC;
}

