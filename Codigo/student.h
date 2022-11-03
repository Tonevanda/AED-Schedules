//
// Created by tomas e João e Tiago on 15/10/2022.
//
#ifndef CODIGO_STUDENT_H
#define CODIGO_STUDENT_H
#include <string>
#include <vector>
#include <list>
#include <map>
#include "UCTurma.h"
#include "TurmaH.h"
#include "binarySearchTree.h"

using namespace std;

class Student{
private:
    int StudentCode;
    string StudentName;
    vector<UCTurma> Courses;
    //BST<UCTurma> Courses = BST<UCTurma>(UCTurma());  //(UcCode,ClassCode)
public:
    Student();
    Student(int StudentCode, string StudentName);

    void addCourse(string UC, string Turma);
    void addCourse(UCTurma course);
    void removeCourse(UCTurma course);
    void clearCourse();

    int getStudentCode() const;
    string getStudentName() const;
    vector<UCTurma> getCourses() const;


    void showAllHorarios();

    bool operator<(const Student& s2) const;
    bool operator>(const Student& s2) const;
    bool operator==(const Student& s2) const;
    bool operator!=(const Student& s2) const;
};


#endif //CODIGO_STUDENT_H
