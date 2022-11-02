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
        cout << "What do you want to do?\n"
                "1: Remove UC\n"
                "2: Add UC\n"
                "3: Change classes\n"
                "4: Check schedule of an UC\n"
                "5: Check full schedule\n"
                "0: Go back\n";
        while(!(cin >> input)){
            cout << "Invalid input!\n\n";
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout << "What do you want to do?\n"
                    "1: Remove UC\n"
                    "2: Add UC\n"
                    "3: Change classes\n"
                    "4: Check schedule of an UC\n"
                    "5: Check full schedule\n"
                    "0: Go back\n";
        }
        switch(input){
            case 0:
                canRun = false;
                break;
            case 1:
                str = "removeUC";
                temp.push_back(str);
                cin.clear();
                cin.ignore(INT_MAX, '\n');
                cout << "Insert your Student ID\n";
                cin>>str;
                temp.push_back(str);
                cin.clear();
                cin.ignore(INT_MAX, '\n');
                cout << "Insert the UC you want to remove\n";
                cin>>str;
                temp.push_back(str);
                cin.clear();
                cin.ignore(INT_MAX, '\n');
                requests->push(temp);
                cout << "Request registered!\n\n";
                break;
            case 2:
                str = "addUC";
                temp.push_back(str);
                cout << "Insert your Student ID\n";
                getline(cin, str);
                temp.push_back(str);
                cout << "Insert the UC you want to join\n";
                getline(cin, str);
                temp.push_back(str);
                cout << "Insert the class in the Uc you want to join\n";
                getline(cin, str);
                temp.push_back(str);
                requests->push(temp);
                cout << "Request registered!\n\n";
                break;
            case 3:
                str = "changeUC";
                temp.push_back(str);
                cout << "Insert your Student ID\n";
                getline(cin, str);
                temp.push_back(str);
                cout << "Insert the UC of the class you want to change to\n";
                getline(cin, str);
                temp.push_back(str);
                cout << "Insert the class you want to change to\n";
                getline(cin, str);
                temp.push_back(str);
                requests->push(temp);
                cout << "Request registered!\n\n";
                break;
            case 4:
                cout << "Insert your Student ID\n";
                while(!(cin >> id)){
                    cout << "Invalid ID, please try again!\n";
                    cin.clear();
                    cin.ignore(INT_MAX, '\n');
                }
                if(!students.idValid(id)){
                    cout << "Invalid ID!";
                    break;
                }
                cout << "Insert the UC you want to check the schedule of\n";
                cin >> str;
                students.showStudentUCHor(id, str, h.getHorarios());
                cout << "\n";
                break;
            case 5:
                cout << "Insert your Student ID\n";
                while(!(cin >> id)){
                    cout << "Invalid ID, please try again!\n";
                    cin.clear();
                    cin.ignore(INT_MAX, '\n');
                }
                if(!students.idValid(id)){
                    cout << "Invalid ID!\n";
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
        cout << "Choose want you want to do: \n"
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
        cout << "Choose usage mode: \n"
                "1: User\n"
                "2: Admin\n"
                "3: Process requests\n"
                "0: Leave menu\n" << flush;
        while(!(cin >> input1)){
            cout << "Invalid input!\n\n";
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout <<"Choose usage mode: \n"
                   "1: User\n"
                   "2: Admin\n"
                   "3: Process requests\n"
                   "0: Leave menu\n"<< flush;
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
            case 3:
                while(!requests.empty()){
                    if(requests.front().front()=="removeUC"){
                        int id = stoi(requests.front()[1]);
                        string Uccode = requests.front()[2];
                        cout<<"id: "<<id<<"Uccode: "<<Uccode<<"\n";
                        students.removeUC(id, Uccode, &h);

                    }
                    else if(requests.front().front()=="addUC"){
                        int id = stoi(requests.front()[1]);
                        string Uccode = requests.front()[2];
                        string turma = requests.front()[3];
                        cout<<"id: "<<id<<"Uccode: "<<Uccode<<"\n";
                        students.addUC(id, Uccode,turma, &h);
                    }
                    else if(requests.front().front()=="changeUC"){
                        int id = stoi(requests.front()[1]);
                        string Uccode = requests.front()[2];
                        //Não sei que função usar aqui
                        cout<<"id: "<<id<<"Uccode: "<<Uccode<<"\n";

                    }
                    requests.pop();
                }
                break;
            default:
                cout << "Invalid input!\n\n";
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
/*Obrigatorio
 * nome de estudante<->numero estudante,queue,doxigen*/