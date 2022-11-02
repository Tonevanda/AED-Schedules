#include "BSTudents.h"
#include "UCTurma.h"
#include "TurmaH.h"
#include <fstream>
#include <sstream>
#include <algorithm>

int find(vector<UCTurma>arr, UCTurma x){
    int low=0;
    int high=arr.size();
    while(low != high){
        int mid = (low + high)/2;
        if (x == arr[mid]) return mid;
        else if (x > arr[mid]) low = mid + 1;
        else  high = mid - 1;
    }
}


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

bool BSTudents::idValid(int id) {
    Student student = Student(id, "");
    student = students.find(student);
    if(student.getStudentName() == "") return false;
    return true;
}

bool BSTudents::addUC(int id, string uc, string turma, GestaoHor *h) {
    Student student = Student(id, "");
    student = students.find(student);

    TurmaH turmah = TurmaH(uc, turma);
    turmah = h->getHorarios().find(turmah);

    if(!h->canChangeTurma(turmah, student.getCourses())){
        return false;
    }

    h->addAluno(turmah);
    students.remove(student);
    student.addCourse(uc, turma);
    students.insert(student);
    return true;

}

void BSTudents::removeUC(int id, std::string uc, GestaoHor* h) {
    Student student = Student(id, "");
    student = students.find(student);

    vector<UCTurma> uct = student.getCourses();
    UCTurma temp = UCTurma(uc, "");
    int pos=find(uct,temp);
    temp = uct[pos];

    students.remove(student);
    student.removeCourse(temp);
    students.insert(student);

    TurmaH turma = TurmaH(uc, temp.getTurma());
    turma = h->getHorarios().find(turma);
    h->removeAluno(turma);
}
void BSTudents::removeUC(int id, std::string uc, string oldTurma, GestaoHor* h) {
    Student student = Student(id, "");
    student = students.find(student);

    vector<UCTurma> uct = student.getCourses();
    UCTurma temp = UCTurma(uc, oldTurma);
    int pos=find(uct,temp);
    temp = uct[pos];
    students.remove(student);
    student.removeCourse(temp);
    students.insert(student);

    TurmaH turma = TurmaH(uc, oldTurma);
    turma = h->getHorarios().find(turma);
    h->removeAluno(turma);
}
bool BSTudents::changeTurma(int id, std::string Uc, string novaTurma, GestaoHor *h) {
    Student student = Student(id, "");
    student = students.find(student);
    vector<UCTurma> uct = student.getCourses();
    UCTurma temp = UCTurma(Uc, "");
    int pos=find(uct,temp);
    temp = uct[pos];
    string oldTurma = temp.getTurma();

    if(addUC(id, Uc, novaTurma, h)){
        removeUC(id, Uc, oldTurma, h);
        return true;
    }
    return false;
}

string BSTudents::getStudentName(int id) const {
    Student student = Student(id, "");
    return students.find(student).getStudentName();
}
vector<UCTurma> BSTudents::getStudentUCTurma(int id) const {
    Student student = Student(id, "");
    student = students.find(student);
    return student.getCourses();
}
string BSTudents::getStudentUCs(int id) const{
    Student student = Student(id, "");
    student = students.find(student);
    vector<UCTurma> UCT = student.getCourses();
    ostringstream out;
    for(auto it:UCT){
        out << it.getUC();
    }
    /*
    BSTItrIn<UCTurma> it = BSTItrIn<UCTurma> (UCT);
    while(!it.isAtEnd()){
        out << it.retrieve().getUC();
        it.advance();
    }*/
    return out.str();
}
string BSTudents::getStudentUCTs(int id) const{
    Student student = Student(id, "");
    student = students.find(student);
    vector<UCTurma> UCT = student.getCourses();
    ostringstream out;
    for(auto it:UCT){
        out << it.getUC()<< "," << it.getTurma() << ",";;
    }
    /*
    BSTItrIn<UCTurma> it = BSTItrIn<UCTurma> (UCT);
    while(!it.isAtEnd()){
        out << it.retrieve().getUC() << "," << it.retrieve().getTurma() << ",";
        it.advance();
    }*/
    return out.str();
}

void BSTudents::showStudentUCHor(int id, string ucCode, BST<TurmaH> h){
    Student student = Student(id, "");
    student = students.find(student);
    vector<UCTurma> UCT = student.getCourses();
    UCTurma temp = UCTurma(ucCode, "");
    int pos=find(UCT,temp);
    temp = UCT[pos];

    TurmaH turmah = TurmaH(temp.getUC(), temp.getTurma());
    turmah = h.find(turmah);
    turmah.showHorario();
}

void BSTudents::showStudentUCs(int id) {
    Student student = Student(id, "");
    student = students.find(student);
    vector<UCTurma> UCT = student.getCourses();
    for (auto it: UCT) {
        cout << it.getUC()<<"\n";
    }
}
void BSTudents::showStudentClasses(int id) {
    Student student = Student(id, "");
    student = students.find(student);
    vector<UCTurma> UCT = student.getCourses();
    for (auto it: UCT) {
        cout << it.getTurma()<<"\n";
    }

}
void BSTudents::showStudentUCTurma(int id) {
    Student student = Student(id, "");
    student = students.find(student);
    vector<UCTurma> UCT = student.getCourses();
    for (auto it: UCT) {
        cout << it.getUC() << " " << it.getTurma() << " ";
    }
}
void BSTudents::showStudentHorario(int id, BST<TurmaH> h){
    Student student = Student(id, "");
    student = students.find(student);
    vector<UCTurma> UCT = student.getCourses();
    for (auto it: UCT) {
        TurmaH hor = TurmaH(it.getUC(), it.getTurma());
        TurmaH temp = h.find(hor);
        cout << it.getUC() << ", " << it.getTurma() << ": \n";
        temp.showHorario();
        cout << "\n";
    }
    /*
    BSTItrIn<UCTurma> it = BSTItrIn<UCTurma>(uct);
    while(!it.isAtEnd()){
        TurmaH hor = TurmaH(it.retrieve().getUC(), it.retrieve().getTurma());
        TurmaH temp = h.find(hor);
        cout << it.retrieve().getUC() << ", " << it.retrieve().getTurma() << ": \n";
        temp.showHorario();
        cout << "\n";
        it.advance();
    }
    */
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
        vector<UCTurma> UCT = it.retrieve().getCourses();
        cout << id << " "  << it.retrieve().getStudentName() << " ";
        showStudentUCTurma(id);
        cout << "\n";
        it.advance();
    }
}

