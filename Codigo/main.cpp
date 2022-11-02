#include <iostream>
#include "BSTudents.h"
#include "GestaoHor.h"
#include <queue>

void menuUsr(queue<vector<string>> *requests, BSTudents students, GestaoHor h) {
    bool canRun = true;
    string str;
    vector<string> temp;
    int input, id;
    while(canRun) {
        cout << "O que deseja fazer?\n"
                "1: Remover UC\n"
                "2: Adicionar UC\n"
                "3: Mudar de turma\n"
                "4: Ver horario de UC\n"
                "5: Ver horario completo\n"
                "0: Voltar atras\n";
        while(!(cin >> input)){
            cout << "Escolha invalida!\n\n";
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout << "O que deseja fazer?\n"
                    "1: Remover UC\n"
                    "2: Adicionar UC\n"
                    "3: Mudar de turma\n"
                    "4: Ver horario de UC\n"
                    "5: Ver horario completo\n"
                    "0: Voltar atras\n";
        }
        switch(input){
            case 0:
                canRun = false;
                break;
            case 1:
                str = "removeUC";
                temp.push_back(str);
                cout << "Insira o seu Student ID\n";
                getline(cin, str);
                temp.push_back(str);
                cout << "Insira a UC que deseja remover\n";
                getline(cin, str);
                temp.push_back(str);
                requests->push(temp);
                cout << "Pedido registado!\n\n";
                break;
            case 2:
                str = "addUC";
                temp.push_back(str);
                cout << "Insira o seu Student ID\n";
                getline(cin, str);
                temp.push_back(str);
                cout << "Insira a UC em que deseja se juntar\n";
                getline(cin, str);
                temp.push_back(str);
                requests->push(temp);
                cout << "Pedido registado!\n\n";
                break;
            case 3:
                str = "changeUC";
                temp.push_back(str);
                cout << "Insira o seu Student ID\n";
                getline(cin, str);
                temp.push_back(str);
                cout << "Insira a UC da turma que deseja alterar\n";
                getline(cin, str);
                temp.push_back(str);
                cout << "Insira a turma em que deseja entrar\n";
                getline(cin, str);
                temp.push_back(str);
                requests->push(temp);
                cout << "Pedido registado!\n\n";
                break;
            case 4:
                cout << "Insira o seu Student ID\n";
                while(!(cin >> id)){
                    cout << "ID Invalido, insira novamente!\n";
                    cin.clear();
                    cin.ignore(INT_MAX, '\n');
                }
                if(!students.idValid(id)){
                    cout << "ID invalido!";
                    break;
                }
                cout << "Insira a UC que deseja ver o horario\n";
                cin >> str;
                students.showStudentUCHor(id, str, h.getHorarios());
                cout << "\n";
                break;
            case 5:
                cout << "Insira o seu Student ID\n";
                while(!(cin >> id)){
                    cout << "ID Invalido, insira novamente!\n";
                    cin.clear();
                    cin.ignore(INT_MAX, '\n');
                }
                if(!students.idValid(id)){
                    cout << "ID invalido!\n";
                    break;
                }
                students.showStudentHorario(id, h.getHorarios());
                break;
        }
    }
}

void menuAdm(BSTudents students, GestaoHor h){
    bool canRun = true;
    while(canRun){
        cout << "Escolha o que deseja ver: \n"
                "1: Mostrar todos os alunos"
                "...";
    }
}

int main() {
    GestaoHor h = GestaoHor();
    h.insertTurmas();
    h.insertSchedule();
    BSTudents students = BSTudents(); // inicializa BST de students
    students.insertStudents(&h); // insere todos os students
    queue<vector<string>> requests;
    vector<string> temp;
    string str;
    int input1;
    bool canRun = true;

    while(canRun){
        cout << "Escolha o modo de uso: \n"
                "1: Usuario\n"
                "2: Administrador\n"
                "3: Processar pedidos\n"
                "0: Abandonar menu\n" << flush;
        while(!(cin >> input1)){
            cout << "Escolha invalida!\n\n";
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout <<"Escolha o modo de uso: \n"
                   "1: Usuario\n"
                   "2: Administrador\n"
                   "3: Processar pedidos\n"
                   "0: Abandonar menu\n"<< flush;
        }
        switch(input1){
            case 0:
                canRun= false;
                break;
            case 1:
                menuUsr(&requests, students, h);
                break;
            case 2:
                menuAdm(students, h);
                break;
            //case 3:
             //   for(auto request: requests){

               // }
            default:
                cout << "Escolha invalida!\n\n";
                cin.clear();
                cin.ignore(INT_MAX, '\n');
                break;
        }

    }


    return 0;
}

/*Falta:
 * Escrever/guardar mudanças em ficheiros
 * Queue (Processar pedido)
 * Traduzir para Eng/UK (or Pirate Eng)
 * Alterar um conjunto de turmas/uc
 * Ordenação de Listagens
 * Printar todos alunos de uma Turma/Cadeira/Ano
 * Estudantes com mais de n UCs
 * Doxygen + indicar complexidade
 */