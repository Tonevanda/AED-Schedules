//
// Created by Tiago Cruz on 30/10/2022.
//

#ifndef MAIN_CPP_BSTUDENTS_H
#define MAIN_CPP_BSTUDENTS_H
#include "student.h"
#include "binarySearchTree.h"
#include "GestaoHor.h"

class BSTudents{
private:
    BST<Student>students = BST<Student>(Student());
public:
    /**
     * Construtor nulo da classe BSTudents
     * @note Time-complexity -> O(1)
     */
    BSTudents() {NULL;};
    /**
     * Lê os dados do ficheiro e insere os dados dos estudantes na BST correspondente
     * @note Time-complexity -> O(nlog(n))
     * @param h
     */
    void insertStudents(GestaoHor *h,string file);
    /**
     * Escreve no ficheiro output os dados atualizados dos estudantes (com as novas UCs e turmas)
     * @note Time-complexity -> O(n^2)
     */
    void output();
    /**
     * Verifica se o ID passado como input existe na BST de estudantes
     * @note Time-complexity -> O(log(n))
     * @param id
     * @return True se o ID existir, False se não existir
     */
    bool idValid(int id);
    /**
     * Adiciona uma UC a um estudante e atualiza os seus dados na BST
     * @note Time-complexity -> O(log(n))
     * @param id
     * @param uc
     * @param turma
     * @param h
     * @return True se conseguir adicionar a UC ao estudante, False se não conseguir
     */
    bool addUC(int id, string uc, string turma, GestaoHor* h);
    /**
     * Remove uma UC de um estudante e atualiza os seus dados na BST
     * @note Time-complexity -> O(log(n))
     * @param id
     * @param uc
     * @param h
     */
    void removeUC(int id, string uc, GestaoHor *h);
    /**
     * Remove uma UC de um estudante e atualiza os seus dados na BST
     * @note Time-complexity -> O(log(n))
     * @param id
     * @param uc
     * @param oldTurma
     * @param h
     */
    void removeUC(int id, string uc, string oldTurma, GestaoHor *h);
    /**
     * Muda a turma de um estudante e atualiza os seus dados na BST
     * @note Time-complexity -> O(log(n))
     * @param id
     * @param Uc
     * @param novaTurma
     * @param h
     * @return True se a mudança foi possível, False se não foi possível
     */
    bool changeTurma(int id, string Uc, string NovaTurma, GestaoHor* h);
    /**
     * Remove todas as UCs de um estudante e atualiza os seus dados na BST
     * @note Time-complexity -> O(n)
     * @param id
     * @param uc
     * @param h
     */
    void removeAllUC(int id, GestaoHor *h);
    /**
     * Itera sobre a BST de estudantes e retorna o ID correspondente ao nome inserido
     * @note Time-complexity -> O(n)
     * @param name
     * @return ID do estudante
     */
    int getStudentId(string name) const;
    /**
     * Retorna o nome do aluno correspondente ao ID inserido
     * @note Time-complexity -> O(log(n))
     * @param id
     * @return Nome do estudante
     */
    string getStudentName(int id) const;
    /**
     * Printa o horario de uma UC e o seu tipo (T, TP ou PL)
     * @note Time-complexity -> O(log(n))
     * @param id
     * @param ucCode
     * @param h
     */
    void showStudentUCHor(int id, string ucCode, BST<TurmaH> h);
    /**
     * Printa todas as UCs de um estudante correspondente ao ID inserido
     * @note Time-complexity -> O(n)
     * @param id
     */
    void showStudentUCs(int id);
    /**
     * Printa todas as UCs e turmas correspondentes de um estudante correspondente ao ID inserido
     * @note Time-complexity -> O(n)
     * @param id
     */
    void showStudentUCTurma(int id);
    /**
     * Printa o horário completo do estudante correspondente ao ID inserido
     * @note Time-complexity -> O(nlog(n))
     * @param id
     * @param h
     */
    void showStudentHorario(int id, BST<TurmaH> h);
    /**
     * Printa todos os estudantes (ID e nome) inscritos na UC inserida
     * @note Time-complexity -> O(n^2)
     * @param uc
     */
    void showAllStudentsinUC(string uc);
    /**
     * Printa todos os estudantes (ID e nome) inscritos na turma inserida
     * @note Time-complexity -> O(n^2)
     * @param turma
     */
    void showAllStudentsinTurma(string turma);
    /**
     * Printa todos os estudantes (ID e nome) inscritos na UC e turma inseridas
     * @note Time-complexity -> O(n^2)
     * @param uc
     * @param turma
     */
    void showAllStudentsinUCTurma(string uc, string turma);
    /**
     * Printa todos os estudantes (ID e nome) matriculados no ano inserido
     * @note Time-complexity -> O(n^2)
     * @param year
     */
    void showAllStudentsinYear(char year);
    /**
     * Printa todos os estudantes com mais de n UCs
     * @note Time-complexity -> O(n)
     * @param n
     */
    void showStudentsNUCs(int n);
    /**
     * Printa o numero de estudantes com mais de n UCs
     * @note Time-complexity -> O(n)
     * @param n
     */
    void shownStudentsNUCs(int n);

    /**
     * Printa o ID e nome de todos os estudantes organizado pelo ID
     * @note Time-complexity -> O(n)
     */
    void showAllStudentCodes();
    /**
     * Printa o ID e nome de todos os estudantes organizado pelo ID de forma inversa
     * @note Time-complexity -> O(nlog(n))
     */
    void showAllStudentsCodesReverse();
    /**
     * Printa o ID e nome de todos os estudantes organizado pelo nome
     * @note Time-complexity -> O(nlog(n))
     */
    void showAllStudentNames();
    /**
     * Printa o ID e nome de todos os estudantes organizado pelo nome de forma inversa
     * @note Time-complexity -> O(nlog(n))
     */
    void showAllStudentsNamesReverse();
    /**
     * Printa todos os estudantes (ID e nome) e as suas respetivas UCs e turmas
     * @note Time-complexity -> O(n^2)
     */
    void showAllStudents();
    void showAllUC();
    void showAllClasses();
};

#endif //MAIN_CPP_BSTUDENTS_H