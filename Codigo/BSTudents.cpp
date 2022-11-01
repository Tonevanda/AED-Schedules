#include "BSTudents.h"
#include "UCTurma.h"
#include "TurmaH.h"
#include <fstream>
#include <sstream>

void BSTudents::insertStudents(GestaoHor *h) {
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
        Student test = students.find(student);
        h->addAluno(UcCode, ClassCode);

        if(!students.isEmpty() && student == test){
            students.remove(test);
            test.addCourse(ucturma);
            students.insert(test);
        }
        else{
            student.addCourse(ucturma); // inserir UC e Turma no student
            students.insert(student); // inserir student na BST de estudantes
        }
    }
    fout.close();
}

bool BSTudents::addUC(int id, string uc, string turma, GestaoHor *h) {
    Student student = Student(id, "");
    student = students.find(student);

    TurmaH turmah = TurmaH(uc, turma);
    turmah = h->getHorarios().find(turmah);
    if(!h->addAluno(turmah)){
        return false;
    }

    students.remove(student);
    student.addCourse(uc, turma);
    students.insert(student);
    return true;

}
void BSTudents::removeUC(int id, std::string uc, GestaoHor* h) {
    Student student = Student(id, "");
    student = students.find(student);

    BST<UCTurma> uct = student.getCourses();
    UCTurma temp = UCTurma(uc, "");
    temp = uct.find(temp);
    students.remove(student);
    student.removeCourse(temp);
    students.insert(student);

    TurmaH turma = TurmaH(uc, temp.getTurma());
    turma = h->getHorarios().find(turma);
    h->removeAluno(turma);
}
bool BSTudents::changeTurma(int id, std::string oldUc, std::string oldTurma, string novaTurma, GestaoHor *h) {
    if(addUC(id, oldUc, novaTurma, h)){
        removeUC(id, oldUc, h);
    }
}

string BSTudents::getStudentName(int id) const {
    Student student = Student(id, "");
    return students.find(student).getStudentName();
}
BST<UCTurma> BSTudents::getStudentUCTurma(int id) const {
    Student student = Student(id, "");
    student = students.find(student);
    return student.getCourses();
}
string BSTudents::getStudentUCs(int id) const{
    Student student = Student(id, "");
    student = students.find(student);
    BST<UCTurma> UCT = student.getCourses();
    ostringstream out;

    BSTItrIn<UCTurma> it = BSTItrIn<UCTurma> (UCT);
    while(!it.isAtEnd()){
        out << it.retrieve().getUC();
        it.advance();
    }
    return out.str();
}
string BSTudents::getStudentUCTs(int id) const{
    Student student = Student(id, "");
    student = students.find(student);
    BST<UCTurma> UCT = student.getCourses();
    ostringstream out;

    BSTItrIn<UCTurma> it = BSTItrIn<UCTurma> (UCT);
    while(!it.isAtEnd()){
        out << it.retrieve().getUC() << "," << it.retrieve().getTurma() << ",";
        it.advance();
    }
    return out.str();
}

void BSTudents::showStudentUCs(int id) {
    Student student = Student(id, "");
    student = students.find(student);
    BST<UCTurma> UCT = student.getCourses();

    BSTItrIn<UCTurma> it = BSTItrIn<UCTurma> (UCT);
    while(!it.isAtEnd()){
        cout << it.retrieve().getUC() << "\n";
        it.advance();
    }
}
void BSTudents::showStudentClasses(int id) {
    Student student = Student(id, "");
    student = students.find(student);
    BST<UCTurma> UCT = student.getCourses();

    BSTItrIn<UCTurma> it = BSTItrIn<UCTurma> (UCT);
    while(!it.isAtEnd()){
        cout << it.retrieve().getTurma() << "\n";
        it.advance();
    }
}
void BSTudents::showStudentUCTurma(int id) {
    Student student = Student(id, "");
    student = students.find(student);
    BST<UCTurma> UCT = student.getCourses();

    BSTItrIn<UCTurma> it = BSTItrIn<UCTurma> (UCT);
    while(!it.isAtEnd()){
        cout << it.retrieve().getUC() << " " << it.retrieve().getTurma() << " ";
        it.advance();
    }
}
void BSTudents::showStudentHorario(int id, BST<TurmaH> h){
    Student student = Student(id, "");
    student = students.find(student);
    BST<UCTurma> uct = student.getCourses();
    BSTItrIn<UCTurma> it = BSTItrIn<UCTurma>(uct);
    while(!it.isAtEnd()){
        TurmaH hor = TurmaH(it.retrieve().getUC(), it.retrieve().getTurma());
        TurmaH temp = h.find(hor);
        cout << it.retrieve().getUC() << ", " << it.retrieve().getTurma() << ": \n";
        temp.showHorario();
        cout << "\n";
        it.advance();
    }

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
        int id = it.retrieve().getStudentCode();
        BST<UCTurma> UCT = BST<UCTurma> (it.retrieve().getCourses());
        cout << id << " "  << it.retrieve().getStudentName() << " ";
        showStudentUCTurma(id);
        cout << "\n";
        it.advance();
    }
}
