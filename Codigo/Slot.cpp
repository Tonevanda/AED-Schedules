//
// Created by tomas on 30/10/2022.
//

#include <iostream>
#include "Slot.h"
/**
 * Construtor da classe Slot constituído pelo dia da semana, hora de início e fim de uma UC e o seu tipo (T, TP ou PL)
 * Time-complexity -> O(1)
 * @param Diadasemana
 * @param HorarioInicio
 * @param HorarioFim
 * @param Tipo
 */
Slot::Slot(string Diadasemana, double HorarioInicio, double HorarioFim, string Tipo){
    this->Diadasemana = Diadasemana;
    this->HorarioInicio = HorarioInicio;
    this->HorarioFim = HorarioFim;
    this->Tipo = Tipo;
}


/**
 * Retorna o Dia da semana
 * Time-complexity -> O(1)
 * @return
 */
string Slot::getDiaDaSemana() const {return Diadasemana;}
/**
 * Retorna a hora de início de uma UC
 * Time-complexity -> O(1)
 * @return
 */
double Slot::getHorarioInicio() const{return HorarioInicio;}
/**
 * Retorna o hora do fim de uma UC
 * Time-complexity -> O(1)
 * @return
 */
double Slot::getHorarioFim() const{return HorarioFim;}
/**
 * Retorna o tipo de uma UC (T, TP ou PL)
 * Time-complexity -> O(1)
 * @return
 */
string Slot::getTipo() const{return Tipo;}


/**
 * Corresponde a cada dia da semana um valor inteiro para facilitar ordenação
 * Time-complexity -> O(1)
 * @param dia
 * @return
 */
int Slot::valor(std::string dia) const {
    if(dia == "Monday") return 2;
    else if(dia == "Tuesday") return 3;
    else if(dia == "Wednesday") return 4;
    else if(dia == "Thursday") return 5;
    else if(dia == "Friday") return 6;
    else if(dia == "Saturday") return 7;
    else if(dia == "Sunday") return 8;
    else cout << "Error, try again!!!";
    return 0;
}


/**
 * Override ao operador < para verificar se o slot ocorre antes do slot2
 * Time-complexity -> O(1)
 * @param s2
 * @return
 */
bool Slot::operator<(const Slot &s2) const {
    if(valor(Diadasemana) == valor(s2.Diadasemana)){
        return(HorarioInicio < s2.HorarioInicio);
    }
    return valor(Diadasemana) < valor(s2.Diadasemana);
}
/**
 * Override ao operador > para verificar se o slot ocorre depois do slot2
 * Time-complexity -> O(1)
 */
bool Slot::operator>(const Slot &s2) const {
    if(valor(Diadasemana) == valor(s2.Diadasemana)){
        return(HorarioInicio > s2.HorarioInicio);
    }
    return valor(Diadasemana) > valor(s2.Diadasemana);
}
/**
 * Override ao operador == para verificar se o slot ocorre simultaneamente com o slot2
 * Time-complexity -> O(1)
 * @param s2
 * @return
 */
bool Slot::operator==(const Slot &s2) const {
    if(valor(Diadasemana) == valor(s2.Diadasemana)){
        return(HorarioInicio == s2.HorarioInicio);
    }
    return valor(Diadasemana) == valor(s2.Diadasemana);
}
/**
 * Override ao operator != para verificar se o slot não ocorre simultaeamente com o slot2
 * Time-complexity -> O(1)
 */
bool Slot::operator!=(const Slot &s2) const {
    if(valor(Diadasemana) == valor(s2.Diadasemana)){
        return(HorarioInicio != s2.HorarioInicio);
    }
    return valor(Diadasemana) != valor(s2.Diadasemana);
}