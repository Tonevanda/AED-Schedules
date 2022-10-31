//
// Created by tomas on 30/10/2022.
//

#include <iostream>
#include "Slot.h"

Slot::Slot(string Diadasemana, double HorarioInicio, double HorarioFim, string Tipo){
    this->Diadasemana = Diadasemana;
    this->HorarioInicio = HorarioInicio;
    this->HorarioFim = HorarioFim;
    this->Tipo = Tipo;
}



string Slot::getDiaDaSemana() const {return Diadasemana;}
double Slot::getHorarioInicio() const{return HorarioInicio;}
double Slot::getHorarioFim() const{return HorarioFim;}
string Slot::getTipo() const{return Tipo;}



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



bool Slot::operator<(const Slot &s2) const {
    if(valor(Diadasemana) == valor(s2.Diadasemana)){
        return(HorarioInicio < s2.HorarioInicio);
    }
    return valor(Diadasemana) < valor(s2.Diadasemana);
}

bool Slot::operator>(const Slot &s2) const {
    if(valor(Diadasemana) == valor(s2.Diadasemana)){
        return(HorarioInicio > s2.HorarioInicio);
    }
    return valor(Diadasemana) > valor(s2.Diadasemana);
}

bool Slot::operator==(const Slot &s2) const {
    if(valor(Diadasemana) == valor(s2.Diadasemana)){
        return(HorarioInicio == s2.HorarioInicio);
    }
    return valor(Diadasemana) == valor(s2.Diadasemana);
}

bool Slot::operator!=(const Slot &s2) const {
    if(valor(Diadasemana) == valor(s2.Diadasemana)){
        return(HorarioInicio != s2.HorarioInicio);
    }
    return valor(Diadasemana) != valor(s2.Diadasemana);
}