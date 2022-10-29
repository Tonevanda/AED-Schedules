#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "student.h"
int main() {
    vector<Student> Students;
    ifstream fout;
    fout.open("../students_classes.csv"/*, ios::out | ios::app*/);
    string temp;
    string StudentCode;
    string StudentName;
    string UcCode;
    string ClassCode;
    getline (fout, temp);
    while (getline (fout, temp)) {
        stringstream it_stream(temp);
        getline(it_stream,StudentCode,',');
        getline(it_stream,StudentName,',');
        getline(it_stream,UcCode,',');
        getline(it_stream,ClassCode,'\r');
        vector<string> UcCodetemp;
        UcCodetemp.push_back(UcCode);
        vector<string> ClassCodetemp;
        ClassCodetemp.push_back(ClassCode);
        Students.push_back(Student(stoi(StudentCode, nullptr,10),StudentName,UcCodetemp,ClassCodetemp));
        cout << Students.back().getstudentCode()<<" "<<Students.back().getStudentName()<<" "<<Students.back().getUcCode().front()<<" "<<Students.back().getClassCode().front()<<'\n';
    }
    fout.close();
    return 0;
}
