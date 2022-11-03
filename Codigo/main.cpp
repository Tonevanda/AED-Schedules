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

                cout << "Insert your Student ID or Name:\n";
                cin>>str;
                id = students.getStudentId(str);
                if(id == 0){
                    id = stoi(str);
                }
                if(!students.idValid(id)){
                    cout << "User not found!\n";
                    break;
                }
                temp.push_back(to_string(id));
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

                cout << "Insert your Student ID or Name:\n";
                cin>>str;
                id = students.getStudentId(str);
                if(id == 0){
                    id = stoi(str);
                }
                if(!students.idValid(id)){
                    cout << "User not found!\n";
                    break;
                }
                temp.push_back(to_string(id));
                cin.clear();
                cin.ignore(INT_MAX, '\n');

                cout << "Insert the UC you want to join\n";
                cin>>str;
                temp.push_back(str);
                cin.clear();
                cin.ignore(INT_MAX, '\n');

                cout << "Insert the class in the Uc you want to join\n";
                cin>>str;
                temp.push_back(str);
                cin.clear();
                cin.ignore(INT_MAX, '\n');

                requests->push(temp);
                cout << "Request registered!\n\n";
                break;
            case 3:
                str = "changeUC";
                temp.push_back(str);

                cout << "Insert your Student ID or Name:\n";
                cin>>str;
                id = students.getStudentId(str);
                if(id == 0){
                    id = stoi(str);
                }
                if(!students.idValid(id)){
                    cout << "User not found!\n";
                    break;
                }
                temp.push_back(to_string(id));
                cin.clear();
                cin.ignore(INT_MAX, '\n');


                cout << "Insert the UC of the class you want to change to\n";
                cin>>str;
                temp.push_back(str);
                cin.clear();
                cin.ignore(INT_MAX, '\n');

                cout << "Insert the class you want to change to\n";
                cin>>str;
                temp.push_back(str);
                cin.clear();
                cin.ignore(INT_MAX, '\n');

                requests->push(temp);
                cout << "Request registered!\n\n";
                break;
            case 4:
                cout << "Insert your Student ID or Name:\n";
                cin>>str;
                id = students.getStudentId(str);
                if(id == 0){
                    id = stoi(str);
                }
                if(!students.idValid(id)){
                    cout << "User not found!\n";
                    break;
                }
                cin.clear();
                cin.ignore(INT_MAX, '\n');

                cout << "Insert the UC you want to check the schedule of\n";
                cin>>str;
                students.showStudentUCHor(id, str, h.getHorarios());
                cout << "\n";
                cin.clear();
                cin.ignore(INT_MAX, '\n');
                break;
            case 5:
                cout << "Insert your Student ID or Name:\n";
                cin>>str;
                id = students.getStudentId(str);
                if(id == 0){
                    id = stoi(str);
                }
                if(!students.idValid(id)){
                    cout << "User not found!\n";
                    break;
                }
                cin.clear();
                cin.ignore(INT_MAX, '\n');

                students.showStudentHorario(id, h.getHorarios());
                cin.clear();
                cin.ignore(INT_MAX, '\n');
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
    students.showAllStudentsinUC("L.EIC004");
    cout << "\n\n";
    students.showAllStudentsinUCTurma("L.EIC004", "1LEIC08");
    cout << "\n\n";
    students.showAllStudentsinTurma("1LEIC08");
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
                        students.removeUC(id, Uccode, &h);
                    }
                    else if(requests.front().front()=="addUC"){
                        int id = stoi(requests.front()[1]);
                        string Uccode = requests.front()[2];
                        string turma = requests.front()[3];
                        if(!students.addUC(id, Uccode,turma, &h)){
                            //adicionar a outra cena
                        }
                    }
                    else if(requests.front().front()=="changeUC"){
                        int id = stoi(requests.front()[1]);
                        string Uccode = requests.front()[2];
                        string novaTurma = requests.front()[3];
                        if(!students.changeTurma(id, Uccode, novaTurma, &h)){
                            //adicionar a outra cena
                        }
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
 * Queue (Processar pedido) e guardar noutra cena o que faltar
 * Alterar um conjunto de turmas/uc
 * Ordenação de Listagens
 * Printar todos alunos de uma Turma(retirar duplicados ig?) e Ano
 * Estudantes com mais de n UCs
 * Doxygen + indicar complexidade
 */
/*Obrigatorio
 *queue,doxigen*/