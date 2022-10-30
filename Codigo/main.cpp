#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <typeinfo>
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
    int input;
    cout<<"Input Student Id:\n";
    while (!(cin>>input)) {
        cout << "Invalid Student Id" << endl; //executes
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout<<"Input Student Id:\n";
    }
    cout<<"Select Options:\n 1: Check all Students\n";
    while (!(cin>>input)) {
        cout << "Invalid Option" << endl; //executes
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout<<"Select Options:\n 1: Check all Students\n";
    }
    switch (input) {

        case 1:
            vector<Student> Students;
            BST<Student> bst = BST<Student>(Student());
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
                }
                else{
                    map<string,string> tempCourses{{UcCode, ClassCode}};
                    Students.push_back(Student(intStudentCode,StudentName,tempCourses));
                }
            }
            print(Students);
            fout.close();
            break;
    }


    return 0;
}
