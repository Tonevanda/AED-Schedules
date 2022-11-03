//
// Created by tomas on 15/10/2022.
//

#include "student.h"
#include "binarySearchTree.h"
#include <Algorithm>
/**
 * Construtor vazio da classe Student
 */
Student::Student() {
    NULL;
}
/**
 * Construtor da classe Student constituído pelo ID e nome do estudante
 */
Student::Student(int StudentCode, string StudentName){
    this->StudentCode=StudentCode;
    this->StudentName=StudentName;
}
/**
 * Adiciona ao estudante uma UC e a sua respetiva turma
 * @param UC
 * @param Turma
 */
void Student::addCourse(string UC, string Turma){
    UCTurma temp = UCTurma(UC, Turma);
    Courses.push_back(temp);
    sort(Courses.begin(), Courses.end());
}
/**
 * Adiciona ao estudante uma UCTurma (UC e respetiva turma)
 * @param course
 */
void Student::addCourse (UCTurma course){
    Courses.push_back(course);
    sort(Courses.begin(), Courses.end());
    //Courses.insert(course);
}
/**
 * Remove ao estudante uma UCTurma (UC e respetiva turma)
 * @param course
 */
void Student::removeCourse(UCTurma course) {
    for(auto it = Courses.begin(); it != Courses.end(); it++){
        if(*it == course) Courses.erase(it);
    }
}
/**
 * Remove todas as UCTurmas (UC e respetiva turma) do estudante
 */
void Student::clearCourse() {
    Courses.clear();
}
/**
 * Retorna o ID do estudante
 * @return
 */
int Student::getStudentCode() const{
    return StudentCode;
}
/**
 * Retorna o nome do estudante
 * @return
 */
string Student::getStudentName() const{
    return StudentName;
}
/**
 * Retorna um vetor com todas as UCTurmas (UC e respetiva turma) do estudante
 * @return
 */
vector<UCTurma> Student::getCourses() const{
    return Courses;
}

/**
 * Printa o horário completo do estudante (Dia da semana, Hora de início e fim, UC e respetiva turma)
 */
void Student::showAllHorarios() {
    for(auto it:Courses){
        string uc = it.getUC();
        string turma = it.getTurma();
        TurmaH turmaH = TurmaH(uc,turma);
        turmaH.showHorario();
    }
}
/**
 * Override ao operador <. Verifica se o ID do estudante é menor que o ID do estudante2
 * @param s2
 * @return
 */
bool Student::operator<(const Student &s2) const {
    return StudentCode < s2.StudentCode;
}
/**
 * Override ao operador >. Verifica se o ID do estudante é maior que o ID do estudante2
 */
bool Student::operator>(const Student &s2) const {
    return StudentCode > s2.StudentCode;
}
/**
 * Override ao operador ==. Verifica se o ID do estudante é igual ao ID do estudante2
 * @param s2
 * @return
 */
bool Student::operator==(const Student &s2) const {
    return StudentCode == s2.StudentCode;
}
/**
 * Override ao operador !=. Verifica se o ID do estudante é diferente do ID do estudante2
 * @param s2
 * @return
 */
bool Student::operator!=(const Student &s2) const {
    return StudentCode != s2.StudentCode;
}