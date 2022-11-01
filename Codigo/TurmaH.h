//
// Created by tomas on 30/10/2022.
//
#ifndef CODIGO_TURMAH_H
#define CODIGO_TURMAH_H
#include <string>
#include "binarySearchTree.h"
#include "UCTurma.h"
#include "Slot.h"
using namespace std;

class TurmaH {
private:
    string codUC;
    string codTurma;
    int nAlunos;
    vector<Slot> horario;
public:
    TurmaH() {};
    TurmaH(string codUC, string codTurma);

    string getCodUc() const;
    string getCodTurma() const;
    int getnAlunos() const;
    vector<Slot> getHorario() const;

    void addSlot(Slot slot);
    void addAluno();
    void removeAluno();

    void showHorario();

    bool operator<(const TurmaH& s2) const;
    bool operator>(const TurmaH& s2) const;
    bool operator==(const TurmaH& s2) const;
    bool operator!=(const TurmaH& s2) const;
};


#endif //CODIGO_TURMAH_H
