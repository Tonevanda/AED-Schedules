//
// Created by tomas on 30/10/2022.
//
#ifndef CODIGO_UCTURMA_H
#define CODIGO_UCTURMA_H
#include <string>
#include "binarySearchTree.h"
using namespace std;



class UCTurma {
private:
    string codUC;
    string codTurma;
    //List<slot>horaUCTurma
public:
    UCTurma() {NULL;};
    UCTurma(string codeUC, string codeTurma);

    void mudarTurma(string novaTurma);

    string getUC() const;
    string getTurma() const;

};


#endif //CODIGO_UCTURMA_H
