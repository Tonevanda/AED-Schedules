//
// Created by tomas e João e Tiago on 15/10/2022.
//
#ifndef CODIGO_STUDENT_H
#define CODIGO_STUDENT_H
#include <string>
#include <vector>
#include <map>
#include "UCTurma.h"
#include "binarySearchTree.h"
using namespace std;

class Student{
private:
    int StudentCode;
    string StudentName;
    BST<UCTurma> Courses = BST<UCTurma>(UCTurma());  //(UcCode,ClassCode)
public:
    Student();
    Student(int StudentCode, string StudentName);
    void addCourse(UCTurma course);

    int getStudentCode() const;
    string getStudentName() const;
    BST<UCTurma> getCourses() const;

    bool operator<(const Student& s2) const;
    bool operator>(const Student& s2) const;
    bool operator==(const Student& s2) const;
    bool operator!=(const Student& s2) const;
};


#endif //CODIGO_STUDENT_H
