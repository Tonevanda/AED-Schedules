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

    BST<TurmaH> getHorarios() const;

    void insertTurmas();
    void insertSchedule();

    bool addAluno(TurmaH turma);
    bool addAluno(string UcCode, string ClassCode);
    void removeAluno(TurmaH turma);
    void removeAluno(string UcCode, string ClassCode);
    bool canChangeTurma(TurmaH turma);
    bool canChangeTurma(string UcCode, string ClassCode);

    int findMinAlunos(string UcCode);

    void shownAlunosUC(string UcCode);
    void shownAlunos(string UcCode, string ClassCode);
    void showUCTHorario(string UcCode, string ClassCode);

    void showUCTandHorario();
};

#endif //CODIGO_GESTAOHOR_H
