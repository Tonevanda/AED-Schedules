//
// Created by tomas on 15/10/2022.
//

#include "student.h"
Student::Student() {
    NULL;
}
Student::Student(int StudentCode, string StudentName, map<string,string> Courses){
    this->StudentCode=StudentCode;
    this->StudentName=StudentName;
    this->Courses=Courses;
}
/*
Student::Student(int StudentCode, string StudentName, vector<string> UcCode, vector<string> ClassCode){
    this->StudentCode=StudentCode;
    this->StudentName=StudentName;
    this->UcCode=UcCode;
    this->ClassCode=ClassCode;
}*/
int Student::getstudentCode(){
    return StudentCode;
}
string Student::getStudentName(){
    return StudentName;
}
map<string,string> Student::getCourses(){
    return Courses;
}
string Student::getClassCode(string UcCode) {
    return Courses[UcCode];
}
void Student::setClasses(map<string,string> Courses){
    this->Courses=Courses;
}
/*
vector<string> Student::getUcCode(){
    return UcCode;
}
vector<string> Student::getClassCode(){
    return ClassCode;
}
void Student::setUcCode_ClassCode(vector<string> UcCode,vector<string> ClassCode){
    this->UcCode=UcCode;
    this->ClassCode=ClassCode;
}
void Student::setIndividual_UcCode_ClassCode(string sUcCode,string eUcCode,string ClassCode){
    int pos=0;
    for(string indent:this->UcCode){
        if(indent==sUcCode){
            indent=eUcCode;
            this->ClassCode[pos]=ClassCode;
        }
        pos++;
    }
}
void Student::setIndividual_ClassCode(string UcCode,string ClassCode){
    int pos=0;
    for(string indent:this->UcCode){
        if(indent==UcCode){
            this->ClassCode[pos]=ClassCode;
        }
        pos++;
    }

}
*/

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