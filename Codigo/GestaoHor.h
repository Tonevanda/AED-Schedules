//
// Created by Tiago Cruz on 31/10/2022.
//

#ifndef CODIGO_GESTAOHOR_H
#define CODIGO_GESTAOHOR_H

#include "binarySearchTree.h"
#include "TurmaH.h"

class GestaoHor{
private:
    BST<TurmaH>horarios = BST<TurmaH>(TurmaH());
public:
    /**
     * Construtor nulo da classe GestaoHor
     * Time-complexity -> O(1)
     */
    GestaoHor() {};

    /**
     * Lê o ficheiro e insere as turmas lidas na BST correspondente
     * Time-complexity -> O(nlog(n))
     */
    void insertTurmas();
    /**
     * Lê os horários das UCs do ficheiro e insere na BST correspondente
     * Time-complexity -> O(nlog(n))
     */
    void insertSchedule();
    /**
     * Verifica se o código de UC inserido existe na BST
     * Time-complexity -> O(n)
     * @param UcCode
     * @return
     */
    bool isValidUC(string UcCode);
    /**
     * Verifica se o código de turma inserido existe na BST
     * Time-complexity -> O(log(n))
     */
    bool isValidTurma(string UcCode, string classCode);
    /**
     * Retorna a BST com os horários da turma
     * Time-complexity -> O(1)
     * @return
     */
    BST<TurmaH> getHorarios() const;
    /**
     * Adiciona um aluno a uma TurmaH (UC e turma respetiva) e atualiza a BST correspondente
     * Time-complexity -> O(log(n))
     * @param turma
     * @return
     */
    bool addAluno(TurmaH turma);
    /**
     * Adiciona um aluno a uma UC e turma respetiva e atualiza a BST correspondente
     * Time-complexity -> O(log(n))
     * @param UcCode
     * @param ClassCode
     * @return
     */
    bool addAluno(string UcCode, string ClassCode);
    /**
     * Remove um aluno de uma TurmaH (UC e turma respetiva) e atualiza a BST correspondente
     * Time-complexity -> O(log(n))
     * @param turma
     */
    void removeAluno(TurmaH turma);
    /**
     * Remove um aluno de uma UC e turma respetiva e atualiza a BST correspondente
     * Time-complexity -> O(log(n))
     * @param UcCode
     * @param ClassCode
     */
    void removeAluno(string UcCode, string ClassCode);
    /**
     * Verifica se o pedido para mudar de turma é válido
     * Time-complexity -> O(nlog(n))
     * @param turma
     * @param Courses
     * @param oldTurma
     * @return
     */
    bool canChangeTurma(TurmaH turma, vector<UCTurma> Courses, TurmaH oldTurma = TurmaH());
    /**
     * Verifica se o pedido para mudar de turma é válido (parâmetros alternativos)
     * Time-complexity -> O(log(n))
     * @param UcCode
     * @param ClassCode
     * @param Courses
     * @param oldClassCode
     * @return
     */
    bool canChangeTurma(string UcCode, string ClassCode, vector<UCTurma> Courses, string oldClassCode = "");
    /**
     * Retorna o número de alunos da turma com menos alunos
     * Time-complexity -> O(n)
     * @param UcCode
     * @return
     */
    int findMinAlunos(string UcCode);
    /**
     * Printa todas as UCs num dado ano
     * Time-complexity -> O(n)
     * @param year
     */
    void showAllUCinYear(char year);
    /**
     * Printa o número de alunos inscritos numa cadeira
     * Time-complexity -> O(n)
     * @param UcCode
     */
    void shownAlunosUC(string UcCode);
    /**
     * Printa o número de alunos inscritos numa turma de uma cadeira
     * Time-complexity -> O(log(n))
     * @param UcCode
     * @param ClassCode
     */
    void shownAlunos(string UcCode, string ClassCode);
    /**
     * Printa o dia da semana, horário de início e fim (formato hh:mm) e tipo (T, TP e PL) de uma UC de uma turma
     * Time-complexity -> O(n)
     * @param UcCode
     * @param ClassCode
     */
    void showUCTHorario(string UcCode, string ClassCode);
    /**
     * Printa a UC, turma, e o seu respetivo horário
     * Time-complexity -> O(n)
     */
    void showUCTandHorario();
};

#endif //CODIGO_GESTAOHOR_H
