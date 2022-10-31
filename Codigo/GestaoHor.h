//
// Created by Tiago Cruz on 31/10/2022.
//

#ifndef CODIGO_GESTAOHOR_H
#define CODIGO_GESTAOHOR_H

#include "binarySearchTree.h"
#include "TurmaH.h"

class GestaoHor{
private:
    BST<TurmaH>horarios = BST<TurmaH>(TurmaH());
public:
    GestaoHor() {};
    void insertSchedule();

    void showUCTHorario(string UcCode, string ClassCode);

    void showUCTandHorario();
};

#endif //CODIGO_GESTAOHOR_H
