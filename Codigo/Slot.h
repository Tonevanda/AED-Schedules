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
     * @note Time-Complexity -> O(1)
     */
    Slot() {};
    /**
     * Construtor da classe Slot constituído pelo dia da semana, hora de início e fim de uma UC e o seu tipo (T, TP ou PL)
     * @note Time-complexity -> O(1)
     * @param Diadasemana
     * @param HorarioInicio
     * @param HorarioFim
     * @param Tipo
     */
    Slot(string Diadasemana, double HorarioInicio, double HorarioFim, string Tipo);
    /**
     * Retorna o Dia da semana
     * @note Time-complexity -> O(1)
     * @return dia da semana
     */
    string getDiaDaSemana() const;
    /**
     * Retorna a hora de início de uma UC
     * @note Time-complexity -> O(1)
     * @return hora do início
     */
    double getHorarioInicio() const;
    /**
     * Retorna o hora do fim de uma UC
     * @note Time-complexity -> O(1)
     * @return hora do fim
     */
    double getHorarioFim() const;
    /**
     * Retorna o tipo de uma UC (T, TP ou PL)
     * @note Time-complexity -> O(1)
     * @return tipo da UC
     */
    string getTipo() const;
    /**
     * Corresponde a cada dia da semana um valor inteiro para facilitar ordenação
     * @note Time-complexity -> O(1)
     * @param dia
     * @return valor numérico do dia da semana
     */
    int valor(string dia) const;
    /**
     * Override ao operador < para verificar se o slot ocorre antes do slot2
     * @note Time-complexity -> O(1)
     * @param s2
     * @return
     */
    bool operator<(const Slot& s2) const;
    /**
     * Override ao operador > para verificar se o slot ocorre depois do slot2
     * @note Time-complexity -> O(1)
     */
    bool operator>(const Slot& s2) const;
    /**
     * Override ao operador == para verificar se o slot ocorre simultaneamente com o slot2
     * @note Time-complexity -> O(1)
     * @param s2
     * @return
     */
    bool operator==(const Slot& s2) const;
    /**
     * Override ao operator != para verificar se o slot não ocorre simultaeamente com o slot2
     * @note Time-complexity -> O(1)
     */
    bool operator!=(const Slot& s2) const;
};


#endif //CODIGO_SLOT_H
