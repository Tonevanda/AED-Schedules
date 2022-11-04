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
    vector<string> temp;
    while(canRun) {
        string str, modo, tempuc;
        int input, id;
        cout << "What do you want to do?\n"
                "1: Remove UC\n"
                "2: Add UCs\n"
                "3: Change Classes\n"
                "4: Remove all UCs\n"
                "5: Check schedule of an UC\n"
                "6: Check full schedule\n"
                "7: Check UC and respective classes\n"
                "8: Show your Uc\n"
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
                    "7: Check UC and respective classes\n"
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
                    cin.clear();
                    cin.ignore(INT_MAX, '\n');
                    if(!h.isValidUC(str)){
                        cout << "Invalid UC\n";
                        temp.clear();
                        break;
                    }
                    temp.push_back(str);

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
                changing = true;
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
                    tempuc = str;
                    cin.clear();
                    cin.ignore(INT_MAX, '\n');
                    if(!h.isValidUC(str)){
                        cout << "Invalid UC\n";
                        temp.clear();
                        break;
                    }
                    temp.push_back(str);
                    cout << "Insert the class in the Uc you want to join\n";
                    cin>>str;
                    cin.clear();
                    cin.ignore(INT_MAX, '\n');
                    if(!h.isValidTurma(tempuc, str)){
                        cout << "Invalid Class\n";
                        temp.clear();
                        break;
                    }
                    temp.push_back(str);
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
                changing = true;
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
                    tempuc = str;
                    cin.clear();
                    cin.ignore(INT_MAX, '\n');
                    if(!h.isValidUC(str)){
                        temp.clear();
                        cout << "Invalid UC \n";
                        break;
                    }
                    temp.push_back(str);

                    cout << "Insert the class you want to change to\n";
                    cin >> str;
                    cin.clear();
                    cin.ignore(INT_MAX, '\n');
                    if(!h.isValidTurma(tempuc, str)){
                        temp.clear();
                        cout << "Invalid class \n";
                        break;
                    }
                    temp.push_back(str);
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
                changing = true;
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
                cin.clear();
                cin.ignore(INT_MAX, '\n');
                if(!h.isValidUC(str)){
                    cout << "Invalid UC! \n";
                    break;
                }
                students.showStudentUCHor(id, str, h.getHorarios());
                cout << "\n";
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
                break;
            case 8:{
                string n;
                cout << "Input n: ";
                cin >> n;
                cin.clear();
                cin.ignore(INT_MAX, '\n');
                students.showStudentUCs(stoi(n));
                cout << "\n";
                break;
            }
        }
    }
}
/**
 * Menu para ver as listagens
 * @param students
 * @param h
 */
void menuAdm(BSTudents students, GestaoHor h){
    bool canRun = true;
    int n;
    while(canRun){
        int input;
        cout << "Choose want you want to do: \n"
                "1: Show Student...\n"
                "2: Show UCs, Class, Schedule...\n"
                "3: Show the number of...\n"
                "0: Return\n";
        while(!(cin >> input)){
            cout << "Invalid input!\n\n";
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout <<"Choose want you want to do: \n"
                   "1: Show Student...\n"
                   "2: Show UCs, Class, Schedule...\n"
                   "3: Show the number of...\n"
                   "0: Return\n";
        }
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        switch(input){
            case 0:
                canRun = false;
                break;
            case 1:
                cout << "How do you want to see?\n"
                        "1: Every student ordered by Student ID\n"
                        "2: Every student ordered by Name\n"
                        "3: Every student in an Uc/Class combination\n"
                        "4: Every student in an Uc\n"
                        "5: Every student in a Class \n"
                        "6: Every student in an year\n"

                        "8: With more than n UCs\n"
                        "0: Return \n";
                while(!(cin >> input)){
                    cout << "Invalid input!\n\n";
                    cin.clear();
                    cin.ignore(INT_MAX, '\n');
                    cout <<"How do you want to see?\n"
                           "1: Every student ordered by Student ID\n"
                           "2: Every student ordered by Name\n"
                           "3: Every student in an Uc/Class combination\n"
                           "4: Every student in an Uc\n"
                           "5: Every student in a Class\n"
                           "6: Every student in an year\n"
                           "8: With more than n UCs\n"
                           "0: Return \n";
                }
                cin.clear();
                cin.ignore(INT_MAX, '\n');
                switch (input) {
                    case 0: canRun = false; break;
                    case 1:
                        cout << "In which order?\n"
                                "1: Normal\n"
                                "2: Reverse \n"
                                "0: Return\n";
                        while(!(cin >> n)) {
                            cout << "Invalid input!\n\n";
                            cin.clear();
                            cin.ignore(INT_MAX, '\n');
                            cout << "In which order?\n"
                                    "1: Normal\n"
                                    "2: Reverse \n"
                                    "0: Return\n";
                        }
                        cin.clear();
                        cin.ignore(INT_MAX, '\n');
                        switch(n){
                            case 0: break;
                            case 1:students.showAllStudentCodes();break;
                            case 2:students.showAllStudentsCodesReverse();break;
                            default: cout << "Invalid Input!\n"; break;
                        }
                        break;
                    case 2:cout << "In which order?\n"
                                   "1: Normal\n"
                                   "2: Reverse \n"
                                   "0: Return\n";
                        while(!(cin >> n)) {
                            cout << "Invalid input!\n\n";
                            cin.clear();
                            cin.ignore(INT_MAX, '\n');
                            cout << "In which order?\n"
                                    "1: Normal\n"
                                    "2: Reverse \n"
                                    "0: Return \n";
                        }
                        cin.clear();
                        cin.ignore(INT_MAX, '\n');
                        switch(n){
                            case 0: break;
                            case 1:students.showAllStudentNames();break;
                            case 2:students.showAllStudentsNamesReverse();break;
                            default: cout << "Invalid Input!\n"; break;
                        }
                        break;
                    case 3:{
                        string uc,turma;
                        cout << "Input Uc:";
                        cin >> uc;
                        cin.clear();
                        cin.ignore(INT_MAX, '\n');
                        cout<<"Input turma:";
                        cin>>turma;
                        cin.clear();
                        cin.ignore(INT_MAX, '\n');
                        students.showAllStudentsinUCTurma(uc,turma);
                        break;
                    }
                    case 4:{
                        string uc;
                        cout << "Input Uc:";
                        cin >> uc;
                        cin.clear();
                        cin.ignore(INT_MAX, '\n');
                        students.showAllStudentsinUC(uc);
                        break;
                    }
                    case 5: {
                        string turma;
                        cout << "Input Class:";
                        cin >> turma;
                        cin.clear();
                        cin.ignore(INT_MAX, '\n');
                        students.showAllStudentsinTurma(turma);
                        break;
                    }
                    case 6:{
                        char year;
                        cout << "Input year: (1,2,3,...) \n";
                        cin >> year;
                        cin.clear();
                        cin.ignore(INT_MAX, '\n');
                        if(year != '1' && year != '2' && year != '3'){
                            cout << "Invalid year!\n";
                            break;
                        }
                        students.showAllStudentsinYear(year);
                        cout << "\n";
                        break;
                    }
                    case 7:{
                        cout << "Input n: ";
                        cin >> n;
                        cin.clear();
                        cin.ignore(INT_MAX, '\n');
                        students.showStudentUCs(n);
                        cout << "\n";
                        break;
                    }
                    case 8:{
                        cout << "Input n: ";
                        cin >> n;
                        cin.clear();
                        cin.ignore(INT_MAX, '\n');
                        students.showStudentsNUCs(n);
                        cout << "\n";
                        break;
                    }
                    default: cout << "Invalid input \n";break;
                }
                break;
            case 2:
                cout << "1: Show every UC, Class and Schedule \n"
                        "2: Show every UC in a year\n"
                        "0: Return\n";
                while(!(cin >> input)) {
                    cout << "Invalid input!\n\n";
                    cin.clear();
                    cin.ignore(INT_MAX, '\n');
                    cout << "1: Show every UC, Class and Schedule \n"
                            "2: Show every UC in a year\n"
                            "0: Return\n";
                }
                cin.clear();
                cin.ignore(INT_MAX, '\n');
                switch(input){
                    case 0: break;
                    case 1: h.showUCTandHorario(); break;
                    case 2:{
                        char year;
                        cout << "Input year: (1,2,3,...) \n";
                        cin >> year;
                        cin.clear();
                        cin.ignore(INT_MAX, '\n');
                        if(year != '1' && year != '2' && year != '3'){ cout << "Invalid year!\n"; break;}
                        h.showAllUCinYear(year);
                        cout << "\n";
                        break;
                    }
                        break;
                }
                break;
            case 3:
                cout << "1: Students in an UC\n"
                        "2: Students in an UC/Class combo\n"
                        "3: Students with more than n UCs\n"
                        "0: Return \n";
                while(!(cin >> input)) {
                    cout << "Invalid input!\n\n";
                    cin.clear();
                    cin.ignore(INT_MAX, '\n');
                    cout << "1: Students in an UC\n"
                            "2: Students in an UC/Class combo\n"
                            "3: Students with more than n UCs \n"
                            "0: Return \n";
                }
                cin.clear();
                cin.ignore(INT_MAX, '\n');
                switch(input) {
                    case 0:
                        break;
                    case 1: {
                        string uc;
                        cout << "Input UC: ";
                        cin >> uc;
                        cin.clear();
                        cin.ignore(INT_MAX, '\n');
                        if (!h.isValidUC(uc)) {
                            cout << "Invalid UC! \n";
                            break;
                        }
                        h.shownAlunosUC(uc);
                        cout << "\n";
                        break;
                    }
                    case 2: {
                        string uc, turma;
                        cout << "Input UC: ";
                        cin >> uc;
                        cin.clear();
                        cin.ignore(INT_MAX, '\n');
                        cout << "\n";
                        if (!h.isValidUC(uc)) {
                            cout << "Invalid UC! \n";
                            break;
                        }
                        cout << "Input Class: ";
                        cin >> turma;
                        cin.clear();
                        cin.ignore(INT_MAX, '\n');
                        cout << "\n";
                        if (!h.isValidTurma(uc, turma)) {
                            cout << "Invalid Class! \n";
                            break;
                        }
                        h.shownAlunos(uc, turma);
                        cout << "\n";
                        break;
                    }
                    case 3:{
                        cout << "Input n: ";
                        cin >> n;
                        cin.clear();
                        cin.ignore(INT_MAX, '\n');
                        students.shownStudentsNUCs(n);
                        cout << "\n";
                        break;
                    }
                    default: cout << "Invalid Input! \n"; break;
                }
                break;
            default: cout << "Invalid input!\n"; break;
        }
    }
}
/**
 * Menu para processar os pedidos relativos a mudanças de turmas, etc.
 * @param requests
 * @param students
 * @param h
 * @param failedr
 */
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
/**
 * Menu principal. Inicializa as BSTs e outros objetos
 * @return
 */
int main() {
    GestaoHor h = GestaoHor();
    h.insertTurmas();
    h.insertSchedule();
    //cout<<"Insert student_classes File name with extension:";        <-Estes comentarios não são para apagar
    //string file;
    //cin>>file;
    string file="students_classes.csv";
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
                "0: Quit Program\n" << flush;
        while(!(cin >> input1)){
            cout << "Invalid input!\n\n";
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout <<"Choose usage mode: \n"
                   "1: User\n"
                   "2: Listings\n"
                   "3: Process requests\n"
                   "0: Quit Program\n"<< flush;
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
                students.output();
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
 * Ordenação de Listagens
 * debug
 * */