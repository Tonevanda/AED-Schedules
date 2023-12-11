#include "BSTudents.h"
#include "UCTurma.h"
#include "TurmaH.h"
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <Set>
/**
 * Encontra turma x num vetor de turmas arr com binary search
 * Time-complexity -> O(log(n))
 * @param arr
 * @param x
 * @return
 */
int find(vector<UCTurma>arr, UCTurma x){
    int low=0;
    int high=arr.size();
    while(low != high){
        int mid = (low + high)/2;
        if (x == arr[mid]) return mid;
        else if (x > arr[mid]) low = mid + 1;
        else  high = mid - 1;
    }
    return 0;
}

void BSTudents::output(){
    BSTItrIn<Student> it = BSTItrIn<Student> (students);
    ofstream output;
    output.open("../output.csv");
    output<<"StudentCode,StudentName,UcCode,ClassCode\n";
    while(!it.isAtEnd()){
        for(auto it2:it.retrieve().getCourses()){
            output << it.retrieve().getStudentCode()<<","<<it.retrieve().getStudentName()<<","<<it2.getUC()<<","<<it2.getTurma()<< "\n";
        }
        it.advance();
    }
    output.close();
}

void BSTudents::insertStudents(GestaoHor *h,string file) {
    ifstream fout;
    file="../"+file;
    fout.open(file);
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

    removeUC(id, Uc, oldTurma, *&h);
    if(!addUC(id, Uc, novaTurma, *&h)){
        addUC(id, Uc, oldTurma, h);
        return false;
    }
    return true;
}

void BSTudents::removeAllUC(int id, GestaoHor *h) {
    Student student = Student(id, "");
    student = students.find(student);
    students.remove(student);
    student.clearCourse();
    students.insert(student);
}

int BSTudents::getStudentId(string name) const {
    BSTItrIn<Student> it = BSTItrIn<Student>(students);
    while (!it.isAtEnd()) {
        Student student = it.retrieve();
        if (name == student.getStudentName()) {
            return student.getStudentCode();
        }
        it.advance();
    }
    return 0;
}

string BSTudents::getStudentName(int id) const {
    Student student = Student(id, "");
    return students.find(student).getStudentName();
}

void BSTudents::showStudentUCHor(int id, string ucCode, BST<TurmaH> h){
    Student student = Student(id, "");
    student = students.find(student);
    vector<UCTurma> UCT = student.getCourses();
    UCTurma temp = UCTurma(ucCode, "");
    int pos = find(UCT,temp);
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

void BSTudents::showStudentUCTurma(int id) {
    Student student = Student(id, "");
    student = students.find(student);
    vector<UCTurma> UCT = student.getCourses();
    for (auto it: UCT) {
        cout << it.getUC() << " in class " << it.getTurma() << "\n";
    }
}

void BSTudents::showStudentHorario(int id, BST<TurmaH> h){
    Student student = Student(id, "");
    student = students.find(student);
    vector<UCTurma> UCT = student.getCourses();
    for (auto it: UCT) {
        TurmaH hor = TurmaH(it.getUC(), it.getTurma());
        TurmaH temp = h.find(hor);
        cout << it.getUC() << " in class " << it.getTurma() << ": \n";
        temp.showHorario();
        cout << "\n";
    }
}

void BSTudents::showAllStudentsinUC(string uc){
    BSTItrIn<Student> it = BSTItrIn<Student>(students);
    while(!it.isAtEnd()){
        vector<UCTurma> uct = it.retrieve().getCourses();
        for(auto k: uct){
            if(k.getUC() == uc) cout << it.retrieve().getStudentCode() << "---" << it.retrieve().getStudentName() << "\n";
        }
        it.advance();
    }
}

void BSTudents::showAllStudentsinTurma(string turma){
    bool flag = false;
    BSTItrIn<Student> it = BSTItrIn<Student>(students);
    while(!it.isAtEnd()){
        vector<UCTurma> uct = it.retrieve().getCourses();
        for(auto k: uct){
            if(k.getTurma() == turma) {
                cout << it.retrieve().getStudentCode() << "---" << it.retrieve().getStudentName() << "\n";
                flag = true;
            }
            if(flag == true){
                flag = false;
                break;
            }
        }
        it.advance();
    }
}

void BSTudents::showAllStudentsinUCTurma(std::string uc, std::string turma) {
    BSTItrIn<Student> it = BSTItrIn<Student>(students);
    while(!it.isAtEnd()){
        vector<UCTurma> uct = it.retrieve().getCourses();
        for(auto k: uct){
            if(k.getUC() == uc && k.getTurma() == turma) cout << it.retrieve().getStudentCode() << "---" << it.retrieve().getStudentName() << "\n";
        }
        it.advance();
    }
}

void BSTudents::showAllStudentsinYear(char year){
    bool flag = false;
    BSTItrIn<Student> it = BSTItrIn<Student>(students);
    while(!it.isAtEnd()){
        vector<UCTurma> uct = it.retrieve().getCourses();
        for(auto k: uct){
            if(k.getTurma()[0] == year) {
                cout << it.retrieve().getStudentCode() << "---" << it.retrieve().getStudentName() << "\n";
                flag = true;
            }
            if(flag == true){
                flag = false;
                break;
            }
        }
        it.advance();
    }
}

void BSTudents::showStudentsNUCs(int n) {
    BSTItrIn<Student> it = BSTItrIn<Student> (students);
    while(!it.isAtEnd()){
        if(it.retrieve().getCourses().size() >= n){
            cout << it.retrieve().getStudentCode() << "---" << it.retrieve().getStudentName() << "\n";
        }
        it.advance();
    }
}

void BSTudents::shownStudentsNUCs(int n) {
    BSTItrIn<Student> it = BSTItrIn<Student> (students);
    int count = 0;
    while(!it.isAtEnd()){
        if(it.retrieve().getCourses().size() >= n){
            count++;
        }
        it.advance();
    }
    cout << "There are " << count << " students with more than " << n << " UCs!\n";
}

void BSTudents::showAllStudentCodes() {
    BSTItrIn<Student> it = BSTItrIn<Student> (students);
    while(!it.isAtEnd()){
        cout << "Student: " << it.retrieve().getStudentCode() << ", " << it.retrieve().getStudentName() << "\n";
        it.advance();
    }
}

void BSTudents::showAllStudentsCodesReverse() {
    set<pair<int, string>> sete;
    BSTItrIn<Student> it = BSTItrIn<Student> (students);
    while(!it.isAtEnd()){
        pair<int, string> par = {it.retrieve().getStudentCode(), it.retrieve().getStudentName()};
        sete.insert(par);
        it.advance();
    }
    for(auto iter = sete.rbegin(); iter != sete.rend(); iter++){
        cout << "Student: " << iter->first << ", " << iter->second <<"\n";
    }
}

void BSTudents::showAllStudentNames() {
    set<pair<string, int>> sete;
    BSTItrIn<Student> it = BSTItrIn<Student> (students);
    while(!it.isAtEnd()){
        pair<string, int> par = {it.retrieve().getStudentName(), it.retrieve().getStudentCode()};
        sete.insert(par);
        it.advance();
    }
    for(auto iter: sete){
        cout << "Student: " << iter.first << ", " << iter.second <<"\n";
    }
}

void BSTudents::showAllStudentsNamesReverse() {
    set<pair<string, int>> sete;
    BSTItrIn<Student> it = BSTItrIn<Student> (students);
    while(!it.isAtEnd()){
        pair<string, int> par = {it.retrieve().getStudentName(), it.retrieve().getStudentCode()};
        sete.insert(par);
        it.advance();
    }
    for(auto iter = sete.rbegin(); iter != sete.rend(); iter++){
        cout << "Student: " << iter->first << ", " << iter->second <<"\n";
    }
}

