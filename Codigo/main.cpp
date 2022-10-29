#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "student.h"
#include "binarySearchTree.h"

void print(vector<Student> Students){
    for(auto it:Students){
        cout<<it.getstudentCode()<<" "<<it.getStudentName()<<" ";
        for (const auto& [UcCode, ClassCode] : it.getCourses()){
            cout << UcCode << " " << ClassCode << " ";
        }
        cout<<'\n';
    }
}
int main() {
    vector<Student> Students;
    BST<Student> bst = BST<Student>(Student());
    Student();
    ifstream fout;
    fout.open("../students_classes.csv");
    string tempstream,StudentCode,StudentName,UcCode,ClassCode;
    getline (fout, tempstream);
    while (getline (fout, tempstream)) {
        stringstream it_stream(tempstream);
        getline(it_stream,StudentCode,',');
        getline(it_stream,StudentName,',');
        getline(it_stream,UcCode,',');
        getline(it_stream,ClassCode,'\r');
        int intStudentCode=stoi(StudentCode, nullptr,10);
        if(!Students.empty() && Students.back().getstudentCode()==intStudentCode){
            map<string,string> tempCourses=Students.back().getCourses();
            tempCourses[UcCode]=ClassCode;
            Students.back().setClasses(tempCourses);
            //cout << StudentCode<<" "<<StudentName<<" "<<Students.back().getUcCode().back()<<" "<<Students.back().getClassCode().back()<<'\n';
        }
        else{
            map<string,string> tempCourses{{UcCode, ClassCode}};
            Students.push_back(Student(intStudentCode,StudentName,tempCourses));
        }
        //cout << Students.back().getstudentCode()<<" "<<Students.back().getStudentName()<<" "<<Students.back().getUcCode().front()<<" "<<Students.back().getClassCode().front()<<'\n';
    }
    print(Students);
    fout.close();
    return 0;
}
