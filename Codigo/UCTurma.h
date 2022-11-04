//
// Created by tomas on 30/10/2022.
//
#ifndef CODIGO_UCTURMA_H
#define CODIGO_UCTURMA_H
#include <string>
#include <list>
#include "binarySearchTree.h"
#include "Slot.h"
#include "TurmaH.h"
using namespace std;



class UCTurma {
private:
    string codUC;
    string codTurma;
public:
    /**
     * Construtor nulo da classe UCTurma
     */
    UCTurma() {NULL;};
    /**
     * Construtor da classe UCTurma constituído por uma UC e a sua respetiva turma
     * Time-complexity -> O(1)
     * @param codeUC
     * @param codeTurma
     */
    UCTurma(string codeUC, string codeTurma);
    /**
     * Muda a turma a atual para a turma inserida
     * Time-complexity -> O(1)
     * @param novaTurma
     */
    void mudarTurma(string novaTurma);
    /**
     * Retorna a UC
     * Time-complexity -> O(1)
     * @return
     */
    string getUC() const;
    /**
     * Retorna a turma
     * Time-complexity -> O(1)
     * @return
     */
    string getTurma() const;
    /**
     * Override ao operador <. Verifica se o código da UC é menor que o código da UC2
     * Time-complexity -> O(1)
     * @param s2
     * @return
     */
    bool operator<(const UCTurma& s2) const;
    /**
     * Override ao operador >. Verifica se o código da UC é maior que o código da UC2
     * Time-complexity -> O(1)
     * @param s2
     * @return
     */
    bool operator>(const UCTurma& s2) const;
    /**
     * Override ao operador ==. Verifica se o código da UC é igual ao código da UC2
     * Time-complexity -> O(1)
     * @param s2
     * @return
     */
    bool operator==(const UCTurma& s2) const;
    /**
     * Override ao operador !=. Verifica se o código da UC é diferente do código da UC2
     * Time-complexity -> O(1)
     * @param s2
     * @return
     */
    bool operator!=(const UCTurma& s2) const;
};


#endif //CODIGO_UCTURMA_H
