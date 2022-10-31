#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <typeinfo>
#include "student.h"
#include "binarySearchTree.h"
#include "BSTudents.h"
#include "GestaoHor.h"

int main() {
    BSTudents students = BSTudents(); // inicializa BST de students
    students.insertStudents(); // insere todos os students
    GestaoHor h = GestaoHor();
    h.insertSchedule();

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
            students.showAllStudents();
            break;
        case 2:
            students.showStudentClasses(202071557);
            break;
        case 3:
            h.showUCTandHorario();
            break;
        case 4:
            students.showStudentHorario(202071557, h.getHorarios());
            break;
    }


    return 0;
}
