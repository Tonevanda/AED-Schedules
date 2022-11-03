//
// Created by Tiago Cruz on 30/10/2022.
//

#ifndef MAIN_CPP_BSTUDENTS_H
#define MAIN_CPP_BSTUDENTS_H
#include "student.h"
#include "binarySearchTree.h"
#include "GestaoHor.h"

class BSTudents{
private:
    BST<Student>students = BST<Student>(Student());
public:
    BSTudents() {NULL;};
    void insertStudents(GestaoHor *h);

    bool idValid(int id);

    bool addUC(int id, string uc, string turma, GestaoHor* h);
    void removeUC(int id, string uc, GestaoHor *h);
    void removeUC(int id, string uc, string oldTurma, GestaoHor *h);
    bool changeTurma(int id, string Uc, string NovaTurma, GestaoHor* h);
    void removeAllUC(int id, GestaoHor *h);

    int getStudentId(string name) const;
    string getStudentName(int id) const;
    vector<UCTurma> getStudentUCTurma(int id) const;
    string getStudentUCs(int id) const;
    string getStudentUCTs(int id) const;

    void showStudentUCHor(int id, string ucCode, BST<TurmaH> h);

    void showStudentUCs(int id);
    void showStudentClasses(int id);
    void showStudentUCTurma(int id);
    void showStudentHorario(int id, BST<TurmaH> h);

    void showAllStudentsinUC(string uc);
    void showAllStudentsinTurma(string turma);
    void showAllStudentsinUCTurma(string uc, string turma);
    void showAllStudentsinYear(char year);

    void showAllStudentCodes();
    void showAllStudentNames();
    void showAllUC();
    void showAllClasses();
    void showAllStudents();
};

#endif //MAIN_CPP_BSTUDENTS_H