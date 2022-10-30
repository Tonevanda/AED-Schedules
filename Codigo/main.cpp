#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <typeinfo>
#include "student.h"
#include "binarySearchTree.h"
#include "BSTudents.h"

void print(vector<Student> Students){
    for(auto it:Students){
        cout<<it.getStudentCode()<<" "<<it.getStudentName()<<" ";
        for (const auto& [UcCode, ClassCode] : it.getCourses()){
            cout << UcCode << " " << ClassCode << " ";
        }
        cout<<'\n';
    }
}

int main() {
    BSTudents students = BSTudents(); // inicializa BST de students
    students.insertStudents(); // insere todos os students

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
            print(students);
            break;
    }


    return 0;
}
