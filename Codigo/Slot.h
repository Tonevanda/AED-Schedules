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
    Slot() {};
    Slot(string Diadasemana, double HorarioInicio, double HorarioFim, string Tipo);

    string getDiaDaSemana() const;
    double getHorarioInicio() const;
    double getHorarioFim() const;
    string getTipo() const;

    int valor(string dia) const;

    bool operator<(const Slot& s2) const;
    bool operator>(const Slot& s2) const;
    bool operator==(const Slot& s2) const;
    bool operator!=(const Slot& s2) const;
};


#endif //CODIGO_SLOT_H
