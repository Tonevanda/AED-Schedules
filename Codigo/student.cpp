//
// Created by tomas on 15/10/2022.
//

#include "student.h"
#include "binarySearchTree.h"

Student::Student() {
    NULL;
}
Student::Student(int StudentCode, string StudentName){
    this->StudentCode=StudentCode;
    this->StudentName=StudentName;
}

void Student::addCourse (UCTurma course){
    Courses.insert(course);
}

int Student::getStudentCode() const{
    return StudentCode;
}
string Student::getStudentName() const{
    return StudentName;
}

BST<UCTurma> Student::getCourses() const{
    return Courses;
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