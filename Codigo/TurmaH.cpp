//
// Created by tomas on 30/10/2022.
//

#include "TurmaH.h"
#include <Algorithm>
/**
 * Construtor da classe TurmaH constituído por uma UC, a sua respetiva turma e o número de alunos inscritos
 * nessa UC nessa turma
 * Time-complexity -> O(1)
 * @param codUC
 * @param codTurma
 */
TurmaH::TurmaH(std::string codUC, std::string codTurma) {
    this->codUC = codUC;
    this->codTurma = codTurma;
    nAlunos = 0;
}
/**
 * Retorna o código da UC
 * Time-complexity -> O(1)
 * @return
 */
string TurmaH::getCodUc() const {
    return codUC;
}
/**
 * Retorna o código da turma
 * Time-complexity -> O(1)
 */
string TurmaH::getCodTurma() const {
    return codTurma;
}
/**
 * Retorna o número de alunos presentemente inscritos nessa UC nessa turma
 * Time-complexity -> O(1)
 * @return
 */
int TurmaH::getnAlunos() const {
    return nAlunos;
}
/**
 * Retorna um vetor com o horário de cada UC
 * Time-complexity -> O(1)
 * @return
 */
vector<Slot> TurmaH::getHorario() const {
    return horario;
}
/**
 * Adiciona um slot de aulas ao horário
 * Time-complexity -> O(nlog(n))
 * @param slot
 */
void TurmaH::addSlot(Slot slot) {
    horario.push_back(slot);
    std::sort(horario.begin(), horario.end());
}
/**
 * Incrementa 1 ao número de alunos da turma da UC
 * Time-complexity -> O(1)
 */
void TurmaH::addAluno() {
    nAlunos++;
}
/**
 * Decrementa 1 ao número de alunos da turma da UC
 * Time-complexity -> O(1)
 */
void TurmaH::removeAluno() {
    nAlunos -= 1;
}
/**
 * Printa o dia da semana, hora de início de fim (formato hh:mm) e tipo (T, TP, PL) de uma UC
 * Time-complexity -> O(n)
 */
void TurmaH::showHorario() {
    for(auto it: horario){
        int iniciomin=00;
        int finalmin=00;
        int inicioint=(int)(it.getHorarioInicio()*10);
        if (inicioint%10!=0){iniciomin=30;}
        inicioint/=10;
        int finalint=(int)(it.getHorarioFim()*10);
        if (finalint%10!=0){finalmin=30;}
        finalint/=10;
        string iniciomins,finalmins;
        if(iniciomin==0){iniciomins="00";}
        else{iniciomins= to_string(iniciomin);}
        if(finalmin==0){finalmins="00";}
        else{finalmins= to_string(finalmin);}
        cout << it.getDiaDaSemana() << " | " << inicioint <<":"<< iniciomins << " -> " << finalint <<":"<< finalmins << " | " << it.getTipo() << "\n";
    }
}
/**
 * Override ao operador <. Verifica se o código da UC é menor que o código da UC2, se for igual
 * verifica se o código da turma é menor que o código da turma2
 * Time-complexity -> O(1)
 * @param s2
 * @return
 */
bool TurmaH::operator<(const TurmaH &s2) const {
    if(codUC == s2.codUC){
        return codTurma < s2.codTurma;
    }
    return codUC < s2.codUC;
}
/**
 * Override ao operador >. Verifica se o código da UC é maior que o código da UC2, se for igual
 * verifica se o código da turma é maior que o código da turma2
 * Time-complexity -> O(1)
 * @param s2
 * @return
 */
bool TurmaH::operator>(const TurmaH &s2) const {
    if(codUC == s2.codUC){
        return codTurma > s2.codTurma;
    }
    return codUC > s2.codUC;
}
/**
 * Override ao operador ==. Verifica se o código da UC e da turma é igual ao código da UC2 e turma2
 * Time-complexity -> O(1)
 * @param s2
 * @return
 */
bool TurmaH::operator==(const TurmaH &s2) const {
    return((codUC == s2.codUC) && (codTurma == s2.codTurma));
}
/**
 * Override ao operador !=. Verifica se o código da UC é diferente do código da UC2, se for igual
 * verifica se o código da turma é diferente do código da turma2
 * Time-complexity -> O(1)
 * @param s2
 * @return
 */
bool TurmaH::operator!=(const TurmaH &s2) const {
    if(codUC == s2.codUC){
        return codTurma != s2.codTurma;
    }
    return codUC != s2.codUC;
}