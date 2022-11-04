//
// Created by tomas on 30/10/2022.
//
#ifndef CODIGO_TURMAH_H
#define CODIGO_TURMAH_H
#include <string>
#include "binarySearchTree.h"
#include "UCTurma.h"
#include "Slot.h"
using namespace std;

class TurmaH {
private:
    string codUC;
    string codTurma;
    int nAlunos;
    vector<Slot> horario;
public:
    /**
     * Construtor nulo da classe TurmaH
     * Time-complexity -> O(1)
     */
    TurmaH() {};
    /**
     * Construtor da classe TurmaH constituído por uma UC, a sua respetiva turma e o número de alunos inscritos
     * nessa UC nessa turma
     * Time-complexity -> O(1)
     * @param codUC
     * @param codTurma
     */
    TurmaH(string codUC, string codTurma);
    /**
     * Retorna o código da UC
     * Time-complexity -> O(1)
     * @return
     */
    string getCodUc() const;
    /**
     * Retorna o código da turma
     * Time-complexity -> O(1)
     */
    string getCodTurma() const;
    /**
     * Retorna o número de alunos presentemente inscritos nessa UC nessa turma
     * Time-complexity -> O(1)
     * @return
     */
    int getnAlunos() const;
    /**
     * Retorna um vetor com o horário de cada UC
     * Time-complexity -> O(1)
     * @return
     */
    vector<Slot> getHorario() const;
    /**
     * Adiciona um slot de aulas ao horário
     * Time-complexity -> O(nlog(n))
     * @param slot
     */
    void addSlot(Slot slot);
    /**
     * Incrementa 1 ao número de alunos da turma da UC
     * Time-complexity -> O(1)
     */
    void addAluno();
    /**
     * Decrementa 1 ao número de alunos da turma da UC
     * Time-complexity -> O(1)
     */
    void removeAluno();
    /**
     * Printa o dia da semana, hora de início de fim (formato hh:mm) e tipo (T, TP, PL) de uma UC
     * Time-complexity -> O(n)
     */
    void showHorario();
    /**
     * Override ao operador <. Verifica se o código da UC é menor que o código da UC2, se for igual
     * verifica se o código da turma é menor que o código da turma2
     * Time-complexity -> O(1)
     * @param s2
     * @return
     */
    bool operator<(const TurmaH& s2) const;
    /**
     * Override ao operador >. Verifica se o código da UC é maior que o código da UC2, se for igual
     * verifica se o código da turma é maior que o código da turma2
     * Time-complexity -> O(1)
     * @param s2
     * @return
     */
    bool operator>(const TurmaH& s2) const;
    /**
     * Override ao operador ==. Verifica se o código da UC e da turma é igual ao código da UC2 e turma2
     * Time-complexity -> O(1)
     * @param s2
     * @return
     */
    bool operator==(const TurmaH& s2) const;
    /**
     * Override ao operador !=. Verifica se o código da UC é diferente do código da UC2, se for igual
     * verifica se o código da turma é diferente do código da turma2
     * Time-complexity -> O(1)
     * @param s2
     * @return
     */
    bool operator!=(const TurmaH& s2) const;
};


#endif //CODIGO_TURMAH_H
