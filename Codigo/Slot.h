//
// Created by tomas on 30/10/2022.
//
#include <string>
using namespace std;
#ifndef CODIGO_SLOT_H
#define CODIGO_SLOT_H


class Slot {
private:
    string Diadasemana;
    double HorarioInicio;
    double HorarioFim;
    string Tipo;
public:
    /**
     * Construtor nulo da classe Slot
     * Time-Complexity -> O(1)
     */
    Slot() {};
    /**
     * Construtor da classe Slot constituído pelo dia da semana, hora de início e fim de uma UC e o seu tipo (T, TP ou PL)
     * Time-complexity -> O(1)
     * @param Diadasemana
     * @param HorarioInicio
     * @param HorarioFim
     * @param Tipo
     */
    Slot(string Diadasemana, double HorarioInicio, double HorarioFim, string Tipo);
    /**
     * Retorna o Dia da semana
     * Time-complexity -> O(1)
     * @return
     */
    string getDiaDaSemana() const;
    /**
     * Retorna a hora de início de uma UC
     * Time-complexity -> O(1)
     * @return
     */
    double getHorarioInicio() const;
    /**
     * Retorna o hora do fim de uma UC
     * Time-complexity -> O(1)
     * @return
     */
    double getHorarioFim() const;
    /**
     * Retorna o tipo de uma UC (T, TP ou PL)
     * Time-complexity -> O(1)
     * @return
     */
    string getTipo() const;
    /**
     * Corresponde a cada dia da semana um valor inteiro para facilitar ordenação
     * Time-complexity -> O(1)
     * @param dia
     * @return
     */
    int valor(string dia) const;
    /**
     * Override ao operador < para verificar se o slot ocorre antes do slot2
     * Time-complexity -> O(1)
     * @param s2
     * @return
     */
    bool operator<(const Slot& s2) const;
    /**
     * Override ao operador > para verificar se o slot ocorre depois do slot2
     * Time-complexity -> O(1)
     */
    bool operator>(const Slot& s2) const;
    /**
     * Override ao operador == para verificar se o slot ocorre simultaneamente com o slot2
     * Time-complexity -> O(1)
     * @param s2
     * @return
     */
    bool operator==(const Slot& s2) const;
    /**
     * Override ao operator != para verificar se o slot não ocorre simultaeamente com o slot2
     * Time-complexity -> O(1)
     */
    bool operator!=(const Slot& s2) const;
};


#endif //CODIGO_SLOT_H
