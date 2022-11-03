#include <iostream>
#include "BSTudents.h"
#include "GestaoHor.h"
#include <queue>
/**
 * Menu para user mode
 * @param requests
 * @param students
 * @param h
 */
void menuUsr(queue<vector<string>> *requests, BSTudents students, GestaoHor h,queue<vector<string>> *failedr) {
    bool canRun = true, changing = true;
    string str, modo;
    vector<string> temp;
    int input, id;
    while(canRun) {
        cout << "What do you want to do?\n"
                "1: Remove UC\n"
                "2: Add UCs\n"
                "3: Change Classes\n"
                "4: Remove all UCs\n"
                "5: Check schedule of an UC\n"
                "6: Check full schedule\n"
                "0: Go back\n";
        while(!(cin >> input)){
            cout << "Invalid input!\n\n";
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout << "What do you want to do?\n"
                    "1: Remove UC\n"
                    "2: Add UCs\n"
                    "3: Change Classes\n"
                    "4: Remove all UCs\n"
                    "5: Check schedule of an UC\n"
                    "6: Check full schedule\n"
                    "0: Go back\n";
        }
        switch(input){
            case 0:
                canRun = false;
                break;
            case 1:
                modo = "removeUC";
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

                while(changing) {
                    temp.push_back(modo);
                    temp.push_back(to_string(id));
                    cout << "Insert the UC you want to remove\n";
                    cin >> str;
                    temp.push_back(str);
                    cin.clear();
                    cin.ignore(INT_MAX, '\n');

                    requests->push(temp);
                    temp.clear();
                    cout << "Request registered!\n";
                    cout << "Do you want to keep removing UCs?\n"
                            "1: yes\n"
                            "2: no\n";
                    cin >> str;
                    cin.clear();
                    cin.ignore(INT_MAX, '\n');
                    if (str == "1") continue;
                    else if (str == "2") {
                        changing = false;
                    }
                    while (str != "1" && str != "2") {
                        cout << "Invalid input!\n"
                                "Do you want to keep removing UCs?\n"
                                "1: yes\n"
                                "2: no\n";
                        cin >> str;
                        cin.clear();
                        cin.ignore(INT_MAX, '\n');
                        if (str == "1") continue;
                        else if (str == "2") {
                            changing = false;
                        }
                    }
                }
                break;
            case 2:
                modo = "addUC";
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

                while(changing){
                    temp.push_back(modo);
                    temp.push_back(to_string(id));
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
                    temp.clear();
                    cout << "Request registered!\n";
                    cout << "Do you want to keep adding UCs?\n"
                            "1: yes\n"
                            "2: no\n";
                    cin >> str;
                    cin.clear();
                    cin.ignore(INT_MAX, '\n');
                    if (str == "1") continue;
                    else if (str == "2") {
                        changing = false;
                    }
                    while (str != "1" && str != "2") {
                        cout << "Invalid input!\n"
                                "Do you want to keep adding UCs?\n"
                                "1: yes\n"
                                "2: no\n";
                        cin >> str;
                        cin.clear();
                        cin.ignore(INT_MAX, '\n');
                        if (str == "1") continue;
                        else if (str == "2") {
                            changing = false;
                        }
                    }
                }


                break;
            case 3:
                modo = "changeTurma";
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
                while(changing) {
                    temp.push_back(modo);
                    temp.push_back(to_string(id));
                    cout << "Insert the UC of the class you want to change\n";
                    cin >> str;
                    temp.push_back(str);
                    cin.clear();
                    cin.ignore(INT_MAX, '\n');

                    cout << "Insert the class you want to change to\n";
                    cin >> str;
                    temp.push_back(str);
                    cin.clear();
                    cin.ignore(INT_MAX, '\n');

                    requests->push(temp);
                    temp.clear();
                    cout << "Request registered!\n";
                    cout << "Do you want to keep changing classes?\n"
                            "1: yes\n"
                            "2: no\n";
                    cin >> str;
                    cin.clear();
                    cin.ignore(INT_MAX, '\n');
                    if (str == "1") continue;
                    else if (str == "2") {
                        changing = false;
                    }
                    while (str != "1" && str != "2") {
                        cout << "Invalid input!\n"
                                "Do you want to keep changing classes?\n"
                                "1: yes\n"
                                "2: no\n";
                        cin >> str;
                        cin.clear();
                        cin.ignore(INT_MAX, '\n');
                        if (str == "1") continue;
                        else if (str == "2") {
                            changing = false;
                        }
                    }
                }
                break;
            case 4:
                str = "removeAllUC";
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

                requests->push(temp);
                temp.clear();
                cout << "Request registered!\n\n";
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

                cout << "Insert the UC you want to check the schedule of\n";
                cin>>str;
                students.showStudentUCHor(id, str, h.getHorarios());
                cout << "\n";
                cin.clear();
                cin.ignore(INT_MAX, '\n');
                break;
            case 6:
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
    int input;
    while(canRun){
        cout << "Choose want you want to do: \n"
                "1: Show every student\n"
                "2: Show every UCs\n"
                "0: Return\n";
        while(!(cin >> input)){
            cout << "Invalid input!\n\n";
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout <<"Choose want you want to do: \n"
                   "1: Show every student\n"
                   "2: Show every UCs\n";
        }
        switch(input){
            case 0:
                canRun = false;
                break;
            case 1:
                cout << "How do you want to see?\n"
                        "1: Ordered by Student ID\n"
                        "2: Ordered by Name\n";
                while(!(cin >> input)){
                    cout << "Invalid input!\n\n";
                    cin.clear();
                    cin.ignore(INT_MAX, '\n');
                    cout <<"How do you want to see?\n"
                           "1: Ordered by Student ID\n"
                           "2: Ordered by Name\n";
                }
                if(input == 1) students.showAllStudentCodes();
                else if(input == 2) students.showAllStudentNames();
        }
    }
}
void processrequests(queue<vector<string>>*requests,BSTudents *students,GestaoHor *h,queue<vector<string>>*failedr){
    int size=requests->size();
    vector<string> temp;
    for(int it=0;it<size;it++){
        if(requests->front().front()=="removeUC"){
            int id = stoi(requests->front()[1]);
            string Uccode = requests->front()[2];
            students->removeUC(id, Uccode, h);
        }
        else if(requests->front().front()=="addUC"){
            int id = stoi(requests->front()[1]);
            string Uccode = requests->front()[2];
            string turma = requests->front()[3];
            if(!students->addUC(id, Uccode,turma, h)){
                cout << "Error while adding UC: " << Uccode << " in class " << turma << " to user: " << requests->front()[1] << ", " << students->getStudentName(id) << "\nRequest saved!\n\n";
                temp.push_back(requests->front().front());
                temp.push_back(requests->front()[1]);
                temp.push_back(requests->front()[2]);
                temp.push_back(requests->front()[3]);
                failedr->push(temp);
            }
        }
        else if(requests->front().front()=="changeTurma"){
            int id = stoi(requests->front()[1]);
            string Uccode = requests->front()[2];
            string novaTurma = requests->front()[3];
            if(!students->changeTurma(id, Uccode, novaTurma, h)){
                cout << "Error while trying to change user " << requests->front()[1] << ", " << students->getStudentName(id) << " to class" << novaTurma << " in UC: " << Uccode << "\nRequest saved!\n\n";
                temp.push_back(requests->front().front());
                temp.push_back(requests->front()[1]);
                temp.push_back(requests->front()[2]);
                temp.push_back(requests->front()[3]);
                failedr->push(temp);
            }
        }
        else if(requests->front().front()=="removeAllUC"){
            int id = stoi(requests->front()[1]);
            students->removeAllUC(id, h);
        }
        requests->pop();
    }
}
int main() {
    GestaoHor h = GestaoHor();
    h.insertTurmas();
    h.insertSchedule();
    cout<<"Insert File name with extension:";
    string file;
    cin>>file;
    BSTudents students = BSTudents(); // inicializa BST de students
    students.insertStudents(&h,file); // insere todos os students
    queue<vector<string>> requests;
    queue<vector<string>> failedr;
    vector<string> temp;
    string str;
    int input1;
    bool canRun = true;
    while(canRun){
        cout << "Choose usage mode: \n"
                "1: User\n"
                "2: Listings\n"
                "3: Process requests\n"
                "0: Leave menu\n" << flush;
        while(!(cin >> input1)){
            cout << "Invalid input!\n\n";
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout <<"Choose usage mode: \n"
                   "1: User\n"
                   "2: Listings\n"
                   "3: Process requests\n"
                   "0: Leave menu\n"<< flush;
        }
        switch(input1){
            case 0:
                canRun= false;
                break;
            case 1:
                menuUsr(&requests, students, h,&failedr);
                break;
            case 2:
                menuAdm(students, h);
                break;
            case 3:
                processrequests(&failedr,&students,&h,&failedr);
                processrequests(&requests,&students,&h,&failedr);
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
 * Alterar um conjunto de turmas/uc -> Done ig???
 * Ordenação de Listagens
 * Estudantes com mais de n UCs
 * Doxygen + indicar complexidade
 */

/*Obrigatorio
 *doxigen
 */