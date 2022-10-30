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
    string HorarioInicio;
    string HorarioFim;
    string Tipo;
public:
    Slot() {};
    Slot(string Diadasemana, string HorarioInicio, string HorarioFim, string Tipo);
};


#endif //CODIGO_SLOT_H
