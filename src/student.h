//
// Created by tomas e João e Tiago on 15/10/2022.
//
#ifndef CODIGO_STUDENT_H
#define CODIGO_STUDENT_H
#include <string>
#include <vector>
#include <list>
#include <map>
#include "UCTurma.h"
#include "TurmaH.h"
#include "binarySearchTree.h"

using namespace std;

class Student{
private:
    int StudentCode;
    string StudentName;
    vector<UCTurma> Courses;
    //BST<UCTurma> Courses = BST<UCTurma>(UCTurma());  //(UcCode,ClassCode)
public:
    /**
     * Construtor nulo da classe Student
     * @note Time-complexity -> O(1)
     */
    Student();
    /**
     * Construtor da classe Student constituído pelo ID e nome do estudante
     * @note Time-complexity -> O(1)
     */
    Student(int StudentCode, string StudentName);
    /**
     * Adiciona ao estudante uma UC e a sua respetiva turma
     * @note Time-complexity -> O(nlog(n))
     * @param UC
     * @param Turma
     */
    void addCourse(string UC, string Turma);
    /**
     * Adiciona ao estudante uma UCTurma (UC e respetiva turma)
     * @note Time-complexity -> O(nlog(n))
     * @param course
     */
    void addCourse(UCTurma course);
    /**
     * Remove ao estudante uma UCTurma (UC e respetiva turma)
     * @note Time-complexity -> O(n)
     * @param course
     */
    void removeCourse(UCTurma course);
    /**
     * Remove todas as UCTurmas (UC e respetiva turma) do estudante
     * @note Time-complexity -> O(n)
     */
    void clearCourse();
    /**
     * Retorna o ID do estudante
     * @note Time-complexity -> O(1)
     * @return ID do estudante
     */
    int getStudentCode() const;
    /**
     * Retorna o nome do estudante
     * @note Time-complexity -> O(1)
     * @return nome do estudante
     */
    string getStudentName() const;
    /**
     * Retorna um vetor com todas as UCTurmas (UC e respetiva turma) do estudante
     * @note Time-complexity -> O(1)
     * @return vetor com UCTurmas
     */
    vector<UCTurma> getCourses() const;
    /**
     * Override ao operador <. Verifica se o ID do estudante é menor que o ID do estudante2
     * @note Time-complexity -> O(1)
     * @param s2
     * @return
     */
    bool operator<(const Student& s2) const;
    /**
     * Override ao operador >. Verifica se o ID do estudante é maior que o ID do estudante2
     * @note Time-complexity -> O(1)
     */
    bool operator>(const Student& s2) const;
    /**
     * Override ao operador ==. Verifica se o ID do estudante é igual ao ID do estudante2
     * @note Time-complexity -> O(1)
     * @param s2
     * @return
     */
    bool operator==(const Student& s2) const;
    /**
     * Override ao operador !=. Verifica se o ID do estudante é diferente do ID do estudante2
     * @note Time-complexity -> O(1)
     * @param s2
     * @return
     */
    bool operator!=(const Student& s2) const;
};


#endif //CODIGO_STUDENT_H
