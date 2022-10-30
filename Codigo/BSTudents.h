//
// Created by Tiago Cruz on 30/10/2022.
//

#ifndef MAIN_CPP_BSTUDENTS_H
#define MAIN_CPP_BSTUDENTS_H
#include "student.h"
#include "binarySearchTree.h"

class BSTudents{
private:
    BST<Student>students = BST<Student>(Student());
public:
    BSTudents() {NULL;};
    void insertStudents();
    void showAllStudents();
};

#endif //MAIN_CPP_BSTUDENTS_H
