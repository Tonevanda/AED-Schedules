//
// Created by tomas on 15/10/2022.
//

#include "student.h"
#include "binarySearchTree.h"
#include <Algorithm>

Student::Student() {
    NULL;
}

Student::Student(int StudentCode, string StudentName){
    this->StudentCode=StudentCode;
    this->StudentName=StudentName;
}

void Student::addCourse(string UC, string Turma){
    UCTurma temp = UCTurma(UC, Turma);
    Courses.push_back(temp);
    sort(Courses.begin(), Courses.end());
}

void Student::addCourse (UCTurma course){
    Courses.push_back(course);
    sort(Courses.begin(), Courses.end());
    //Courses.insert(course);
}

void Student::removeCourse(UCTurma course) {
    for(auto it = Courses.begin(); it != Courses.end(); it++){
        if(*it == course) {
            Courses.erase(it);
            break;
        }
    }
}

void Student::clearCourse() {
    Courses.clear();
}

int Student::getStudentCode() const{
    return StudentCode;
}

string Student::getStudentName() const{
    return StudentName;
}

vector<UCTurma> Student::getCourses() const{
    return Courses;
}

void Student::showAllHorarios() {
    for(auto it:Courses){
        string uc = it.getUC();
        string turma = it.getTurma();
        TurmaH turmaH = TurmaH(uc,turma);
        turmaH.showHorario();
    }
}

bool Student::operator<(const Student &s2) const {
    return StudentCode < s2.StudentCode;
}

bool Student::operator>(const Student &s2) const {
    return StudentCode > s2.StudentCode;
}

bool Student::operator==(const Student &s2) const {
    return StudentCode == s2.StudentCode;
}

bool Student::operator!=(const Student &s2) const {
    return StudentCode != s2.StudentCode;
}