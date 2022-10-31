#include "BSTudents.h"
#include "UCTurma.h"
#include <fstream>
#include <sstream>

void BSTudents::insertStudents() {
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
        Student student = Student(intStudentCode,StudentName);
        UCTurma ucturma = UCTurma(UcCode, ClassCode);

        if(!students.isEmpty() && student == students.find(student)){
            student.addCourse(ucturma);
        }
        else{
            student.addCourse(ucturma); // inserir UC e Turma no student
            students.insert(student); // inserir student na BST de estudantes
        }
    }
    fout.close();
}

string BSTudents::getStudentName(int id) {
    Student s = Student(id, "");
    return students.find(s).getStudentName();
}

void BSTudents::showAllStudentCodes() {
    BSTItrIn<Student> it = BSTItrIn<Student> (students);
    while(!it.isAtEnd()){
        cout << it.retrieve().getStudentCode() << "\n";
        it.advance();
    }
}

void BSTudents::showAllStudentNames() {
    BSTItrIn<Student> it = BSTItrIn<Student> (students);
    while(!it.isAtEnd()){
        cout << it.retrieve().getStudentName() << "\n";
        it.advance();
    }
}

void BSTudents::showAllStudents() {
    BSTItrIn<Student> it = BSTItrIn<Student> (students);
    while(!it.isAtEnd()){
        cout << it.retrieve().getStudentCode() << it.retrieve().getStudentName() << "\n";
        it.advance();
    }
}
