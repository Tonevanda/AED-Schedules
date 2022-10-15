//
// Created by tomas e João e Tiago on 15/10/2022.
//

#include <string>
#include <vector>

using namespace std;
#ifndef CODIGO_STUDENT_H
#define CODIGO_STUDENT_H


class Student{
private:
    int StudentCode;
    string StudentName;
    vector<string> UcCode;
    vector<string> ClassCode;
public:
    Student(int StudentCode, string StudentName, vector<string> UcCode, vector<string> ClassCode);
    int getstudentCode();
    string getStudentName();
    vector<string> getUcCode();
    vector<string> getClassCode();
    void setUcCode_ClassCode(vector<string> UcCode,vector<string> ClassCode);
    void setIndividual_UcCode_ClassCode(string sUcCode,string eUcCode,string ClassCode);
    void setIndividual_ClassCode(string UcCode,string ClassCode);
};


#endif //CODIGO_STUDENT_H
