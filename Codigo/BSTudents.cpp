#include "BSTudents.h"
#include "UCTurma.h"
#include "TurmaH.h"
#include <fstream>
#include <sstream>
#include <algorithm>
/**
 * Encontra turma x num vetor de turmas arr com binary search
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

/**
 * Lê os dados do ficheiro e insere os dados dos estudantes na BST correspondente
 * @param h
 */
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
/**
 * Verifica se o ID passado como input existe na BST de estudantes
 * @param id
 * @return
 */
bool BSTudents::idValid(int id) {
    Student student = Student(id, "");
    student = students.find(student);
    if(student.getStudentName() == "") return false;
    return true;
}
/**
 * Adiciona uma UC a um estudante e atualiza os seus dados na BST
 * @param id
 * @param uc
 * @param turma
 * @param h
 * @return
 */
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
/**
 * Remove uma UC de um estudante e atualiza os seus dados na BST
 * @param id
 * @param uc
 * @param h
 */
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
/**
 * Igual à função anterior mas desta vez utiliza também a turma antiga como parametro
 * @param id
 * @param uc
 * @param oldTurma
 * @param h
 */
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
/**
 * Muda a turma de um estudante e atualiza os seus dados na BST
 * @param id
 * @param Uc
 * @param novaTurma
 * @param h
 * @return
 */
bool BSTudents::changeTurma(int id, std::string Uc, string novaTurma, GestaoHor *h) {
    Student student = Student(id, "");
    student = students.find(student);
    vector<UCTurma> uct = student.getCourses();
    UCTurma temp = UCTurma(Uc, "");
    int pos=find(uct,temp);
    temp = uct[pos];
    string oldTurma = temp.getTurma();

    if(addUC(id, Uc, novaTurma, *&h)){
        removeUC(id, Uc, oldTurma, *&h);
        return true;
    }
    return false;
}
/**
 * Remove todas as UCs de um estudante e atualiza os seus dados na BST
 * @param id
 * @param uc
 * @param h
 */
void BSTudents::removeAllUC(int id, GestaoHor *h) {
    Student student = Student(id, "");
    student = students.find(student);
    students.remove(student);
    student.clearCourse();
    students.insert(student);
}
/**
 * Itera sobre a BST de estudantes e retorna o ID correspondente ao nome inserido
 * @param name
 * @return
 */
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
/**
 * Retorna o nome do aluno correspondente ao ID inserido
 * @param id
 * @return
 */
string BSTudents::getStudentName(int id) const {
    Student student = Student(id, "");
    return students.find(student).getStudentName();
}
/**
 * Retorna um vetor com as UCTurmas (UC e turma correspondente) do aluno correspondente ao ID inserido
 * @param id
 * @return
 */
vector<UCTurma> BSTudents::getStudentUCTurma(int id) const {
    Student student = Student(id, "");
    student = students.find(student);
    return student.getCourses();
}
/**
 * Retorna uma string com todas as UCs em que o aluno correspondente ao ID inserido está inscrito
 * @param id
 * @return
 */
string BSTudents::getStudentUCs(int id) const{
    Student student = Student(id, "");
    student = students.find(student);
    vector<UCTurma> UCT = student.getCourses();
    ostringstream out;
    for(auto it:UCT){
        out << it.getUC();
    }
    return out.str();
}
/**
 * Retorna uma string com todas as UCs e turmas correspondentes nas quais o estudante correspondente
 * ao ID inserido está inscrito
 * @param id
 * @return
 */
string BSTudents::getStudentUCTs(int id) const{
    Student student = Student(id, "");
    student = students.find(student);
    vector<UCTurma> UCT = student.getCourses();
    ostringstream out;
    for(auto it:UCT){
        out << it.getUC()<< "," << it.getTurma() << ",";;
    }
    return out.str();
}
/**
 * Printa o horario de uma UC e o seu tipo (T, TP ou PL)
 * @param id
 * @param ucCode
 * @param h
 */
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
/**
 * Printa todas as UCs de um estudante correspondente ao ID inserido
 * @param id
 */
void BSTudents::showStudentUCs(int id) {
    Student student = Student(id, "");
    student = students.find(student);
    vector<UCTurma> UCT = student.getCourses();
    for (auto it: UCT) {
        cout << it.getUC()<<"\n";
    }
}
/**
 * Printa todas as turmas de um estudante correspondente ao ID inserido
 * @param id
 */
void BSTudents::showStudentClasses(int id) {
    Student student = Student(id, "");
    student = students.find(student);
    vector<UCTurma> UCT = student.getCourses();
    for (auto it: UCT) {
        cout << it.getTurma()<<"\n";
    }

}
/**
 * Printa todas as UCs e turmas correspondentes de um estudante correspondente ao ID inserido
 * @param id
 */
void BSTudents::showStudentUCTurma(int id) {
    Student student = Student(id, "");
    student = students.find(student);
    vector<UCTurma> UCT = student.getCourses();
    for (auto it: UCT) {
        cout << it.getUC() << " " << it.getTurma() << " ";
    }
}
/**
 * Printa o horário completo do estudante correspondente ao ID inserido
 * @param id
 * @param h
 */
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
}
/**
 * Printa todos os estudantes (ID e nome) inscritos na UC inserida
 * @param uc
 */
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
/**
 * Printa todos os estudantes (ID e nome) inscritos na turma inserida
 * @param turma
 */
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
/**
 * Printa todos os estudantes (ID e nome) inscritos na UC e turma inseridas
 * @param uc
 * @param turma
 */
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
/**
 * Printa todos os estudantes (ID e nome) matriculados no ano inserido
 * @param year
 */
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
/**
 * Printa o ID de todos os estudantes
 */
void BSTudents::showAllStudentCodes() {
    BSTItrIn<Student> it = BSTItrIn<Student> (students);
    while(!it.isAtEnd()){
        cout << "Student: " << it.retrieve().getStudentCode() << ", " << it.retrieve().getStudentName();
        it.advance();
    }
}
/**
 * Printa o nome de todos os estudantes
 */
void BSTudents::showAllStudentNames() {
    Set<string> sete;
    BSTItrIn<Student> it = BSTItrIn<Student> (students);
    while(!it.isAtEnd()){
        sete.insert
        cout << it.retrieve().getStudentName() << "\n";
        it.advance();
    }
}
/**
 * Printa todos os estudantes (ID e nome) e as suas respetivas UCs e turmas
 */
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

