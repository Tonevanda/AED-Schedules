#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <typeinfo>
#include "student.h"
#include "binarySearchTree.h"
#include "BSTudents.h"
#include "GestaoHor.h"

int main() {
    GestaoHor h = GestaoHor();
    h.insertSchedule();
    BSTudents students = BSTudents(); // inicializa BST de students
    students.insertStudents(&h); // insere todos os students

    int input1,input2;
    cout << "Input Student Id:\n";
    while (!(cin >> input1)) {
            cout << "Invalid Student Id" << endl; //executes
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout << "Input Student Id:\n";
        }
    bool flag= true;
    while(flag) {
        cout << "Select Options:\n 0:End Program \n 1: Check all Students\n 2: Show your classes \n 3: Show another student's classes \n 4:ඞඞඞඞඞඞඞඞඞ \n 5:Show another student's Schedule";
        while (!(cin >> input2)) {
            cout << "Invalid Option" << endl; //executes
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout
                    << "Select Options:\n 1: Check all Students\n 2: Show your classes \n 3: Show another student's classes \n 4: \n 5:Show another student's Schedule";
        }
        switch (input2) {
            case 0:
                cout<<"Program terminated";
                flag= false;
                break;
            case 1:
                students.showAllStudents();
                break;
            case 2:
                students.showStudentClasses(input1);
                break;
            case 3:
                students.showStudentClasses(202071557);
                break;
            case 4:
                h.showUCTandHorario();
                break;
            case 5:
                students.showStudentHorario(202071557, h.getHorarios());
                break;
            case 6:
                h.shownAlunos("L.EIC003", "1LEIC05");
                break;
            case 7:
                cout << "UCs do estudante 202031607: \n";
                students.showStudentUCs(202031607);
                cout << "\nN de estudantes na UC L.EIC004 da Turma 1LEIC08: \n";
                h.shownAlunos("L.EIC004", "1LEIC08");
                students.removeUC(202031607, "L.EIC004", &h);
                cout << "\nUCs do estudante 202031607 apos sair da UC: ";
                students.showStudentUCs(202031607);
                cout << "\nN de estudantes na UC L.EIC004 da Turma 1LEIC08 apos saida do estudante: \n";
                h.shownAlunos("L.EIC004", "1LEIC08");
                break;
            case 8:
                cout << "UCs do estudante 202071557: \n";
                students.showStudentUCs(202071557);
                cout << "\nN de estudantes na UC L.EIC004 da Turma 1LEIC08: \n";
                h.shownAlunos("L.EIC004", "1LEIC08");
                students.addUC(202071557, "L.EIC004", "1LEIC08", &h);
                cout << "\nUCs do estudante 202071557 apos entrar na UC: ";
                students.showStudentUCs(202071557);
                cout << "\nN de estudantes na UC L.EIC004 da Turma 1LEIC08 apos saida do estudante: \n";
                h.shownAlunos("L.EIC004", "1LEIC08");
                break;
            case 69:
                cout
                        << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@WWWWMMxxnnnnzz#zzz;iznnxxxMxxxMWWW@@@WW@@@@@W@@WMW@@@@@@@@@@@M**W@@@#W##########@@##\n"
                           "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@WWWMMMxxnnnnz#z###*.#znxxxxnW@@@@@@@@@@@@@@@@W@@WWWW@@@@@@@@@Mi#W@@@@@##@@######@@##\n"
                           "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@WWWWW@@WWWWMMMxxnnnznnnz+z#,+#nnxnMW@##@@@@@@@@@W@@@@@@@@WWWW@@@@@@@@x;zW@@@@@@##W#######@##\n"
                           "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@WWW@@@WWWWMMMxxxnnnznnz+#z+:z#nnxW@W@@@@@@W@@@@@@@@@@@@@W@@MM@@@@@@Wn;zW@@@@@@@@W##@@@#####\n"
                           "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@W@@@WWWWWMMxxnnnn#zz#zzz+,z#zzxMW@@@W@#@@@@@WW@@@WWWW@@@WMMW@@@@@M**x@@@@@@@@@W#@@@@#####\n"
                           "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@WWWWWMMxxxnnz###zzzz#.+++zxMW@@@@@@@@@@W@W@WWMMWW@@WWMMx@@W@Wn;zW@@@@@@@@@W@@#@#@####\n"
                           "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@W@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@W@@@@WWWWMMMxxnnnnznnzz+#:**#nMM@@@@@W@@@@@@@@@@WMxxMWWWWWMxW@@@Wn;nW@@@@@@@@@@@@@@@@#@@#\n"
                           "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@W@@@WWWWWMMMxxxxnnnnnnz##ii*zxMW@@W@@W@@@@@@@@@@@WMxMWWMMMM##@W@@xi+M@@@@@@@@@@@@@@@@@@@@\n"
                           "@@@@@@@@@@@@@@@@@@@@@@W@@@@@@@@@@@@@@@@@@@@@@@@@@@@@WWWWWWWWWWWWWWWWWWMMMMxxxxxxnnnnz#;;*zxWW@@@@@WWWWW@WWWW@WWWxnMMxxxn:z@W@@Wz:xW@@@@@@@@@@@@@@@@@W@\n"
                           "@@@@@@@@@@@@@@@@@@@@@@W@@@@@@@@@@@@@@@@@@@@@@@@@@@@WWWWWWWWWWWWWWWWWWMMMMMMxxxxxn#nnz#i:+zMWWWWWWWWMz#z#zzxxMMMWMnxn#:...n@@@@Wn;zW@@@@@@@@@@@@@@@@@@@\n"
                           "@@@@@@@@@@@@@@@@@@@@@@W@@@@@@@@WWWWW@@@@@@@@@@@@WWWWWWWWWWWWWWWWWWWWWMMMMMMMxxxnnz#z##+,i#MMWMMz#*i;;,::::;;i*#nnnx;,.**zx@@W@Wn;nW@@@@@@@@@@@@@@@@@@@\n"
                           "@@@@@@@@@@@@@@@@@@@@@@WW@@@@@W@WWWWWWW@@@@@@WWWWWWWWWWWWWWWWWWWWWWWWWMMMMMMMxxxnz##zzz+*,ixMM#i;;::,`.`.,,,,,,::;;;*nzxMMW@@WWM#;xW@@WW@@@@@@@@@@@@@@@\n"
                           "@@@@@@@@@@@WWWW@WWW@@@WW@@@@@@@WWWWWWWW@@WWWWWWWWWWWWWWWWWWMMMWWWWMMMMMMMMxxxnnnnnzzz###+.nM*...:,.``,,.````` `.`.:*#MWW@@@@Wx#;:xW@@@M@@@@@@@@@@@@@@@\n"
                           "@@@@@@@@WWWWWWWWWWWWWWWWWW@@WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWMMMMMMMMMMMxxxxxnnnnzzzz###*`nx*`;;*i;:,::,..,..,,,,;***MW@@@@Wn*.:*M@@@@M@@@@@@@@@@@@@@@\n"
                           "@@@WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWMMMMMMMMMMxxxnxnnnzzzz#####*`nn;,,;ii;:::,,,..,,,:::;**+xWWW@Wn;.:#MW@@@@W@@@@@@@@@@@@@@@\n"
                           "@@@WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWMWWWWWWWWWWWWWWWWWWWWWWWMMMMMMMMMxxxnnnnnnzz###+##+;:n+,i:.:;;:::,,,..,,,::;i*++xMMW@M+`;nWW@@@@@W@@@@@@@@@@@@@@@\n"
                           "@@@WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWMWWWMMMMMMWWWMMWWWWWWMMMMMMMMxxxxnnnnzzzzz##++#++*.*#:,+*:.,:,::,,,,..,,:;;ii++nxxMWn;`+M@@@@@@@W@@@@@@@@@@@@@@@\n"
                           "@@WWWWWWWWWWWWWWWWWWWMMMMMWWWWWWWWWWWWMMMMMMMMMMMMMMMMWWWWMMMMMMxxxxxxnzzzzzz####+++#++*.+*.,#*;,.,,,,,,,....,:;ii*+++nnnxi.,nW@@@@@@@@@@@@@@@@@@@@@@@\n"
                           "WWWWWWWWWWWWWWMWMMMMMMMMMMMMWWWWWWWWWMMMMMMMMxxxxMMMMMMMMMMMxxxxxnnnnnzzzzz#####++++#++*.*i.i#*;:.,,,,,,......,,;i++#+zzn+.,*xW@@@@@@@@@@@@@@@@@@@@@@@\n"
                           "WWWWWWWWWWWWWWMWMMMMMMMMMMMMMWWWWWMMMMMMMMMMxxxxxxMMMxxxxxxxxnnnnnzzzzz########++++##++i,*i,*zzii.;;::,,,,:::::;i**+##zzz:`*xWWWWW@@@@@@@@@@@@@@@@@@@@\n"
                           "WWWWWWWWWWWWWWWMMMMMMMMMMMMMMMMWWWMMMMMMMMMxxxxxnnnxxnnnnnnnzzzzzz######++######**+++++;:*;:+MMi::z#+i:::;*+znn###**+#zz#,`*xWWWWWWWWWWWWW@@@@@@@@@@@@\n"
                           "WWWWWWWWWWWWWMMMMMMMMMMMMMMMMMMMMMMMMMMMMxxxxxnnnnzzzzzzzzzz#####+*+##+++*++###++**i***.:;i:#n+;.:*##+;::*#z#i::i+:,+#z#z,`inMWWWWWWWWWWWWWWWW@@@@@@@@\n"
                           "WWWWWWWWWWWMMMMMMMMMMMMMxxMMxxxMMMMMMMMxxxxxnnnzzzzzzzz#######++++*+++++***++####**i*i,`,**:izz:``,*z+:,:i#z+i,:;,..i#z##,,;#xMWWWWWWWWWWWWWWW@@@@@@@@\n"
                           "WWWWWWWWWWMMMMMMMMMMMMMxxxxxxxxMMMxxxxxxxnnnnnzzzzzzzz###++#+++++********i++####++i**i`.;#i;+n#:,..;#+:,:i*i.```;i::,*#i+;*zizMMWWWWWWWWWWWWWW@@@@@@@@\n"
                           "WWWWWWWMMMMMMMMMMMxxxMxxxxxxxxxxxxxxxxxnnnnzzznnzzzzz###++++++**+*iii***i*++#####*i++i`:iz:*+***i;::+*:,:::ii;:::;;;:,:+:,+xz*xMMWWWWWWWWWWWW@@@@@@@@@\n"
                           "WWWWWWMMMMn:*xi:n*,,ix+:zn:*xxx*,,;z:+xi:n+,.:#z,iz;:+,i++:..,;**i;iiiiiii++####+*iiii`,;+:*i::::,,:+;,,:::,,:,,,,::;;:,.,+Mx*zxMMMWWWWWWWWWW@@@@@@@@@\n"
                           "WWWWMMMMMMx,`+`;* :; ;i #n ;xx+ :i,+ ix,.#`.;`.+ :z,`i :++, ,``:;;:;;iii;:;*+*+*++**;i.`;+,*i;:,,,:i+;,,::,,,....,,:;i+i:;zMxzinMMMMMWWWWWWWW@@@@@@@@@\n"
                           "MMWMMMMMMMMz``.n:`nn,.i #z ;xx* .iz# .:`.* *ni i :z,`i :+*, ;: .i;::;;;:::,;i*+*++*i**. :#,ii;:,,,:*+;:,::,......,:;;*++*;nxxn*#xMMMMWWWWW@@W@@@@@@@@@\n"
                           "MMMMMMMMMMMM; *x,`nx,`; #z ;xxn;` `+ .:`.i +xi ; :#,`i :+*.`;:`.i;:::,,:::,,;i*i*+****, :n,;*;::,:;#*:,:;::,.....,:;;*#;i;xxxxz*nMMMWWWWW@@@W@@@@@@@@@\n"
                           "MMMMMMMMMMMM* #x; +#`,* *+ ;xx++z: i in,.+ ;z,`*`,+..i ,*i. :. ,i;:,,,:;;:,.:iiii*+++i:`,n.;*i::::i+;,..:;;,.....:;;i+#:;ixxxxn*#xMMWWW@@@@@@@@@@@@@@@\n"
                           "MMMMMMMMMMxx* #xz. ``#z. ``#xx* ``,# ix,.n;```iz: ``;*   `.   .;;::,..:;,,,..:ii**+++i:,:+,:+i::::i+i,.,::;,....,:;;i+#;i+xxMxxz*#nMWW@@@@@@@@@@@@@@@@\n"
                           "MMMMMMMMMxxxn#nxxn++zxxn++zxxxn#+#nn#nxzzxn#+#nnz+*+#+iiii;;;;;::,.::,::,,...:i***++*i;,:#;;#*;:::+nn*;in#;:...,:;;;**#i*#xxMMMxziizMW@@@@@@@@@@@@@@@@\n"
                           "MMMMMMxMMxxxxxxxxxnnxxxxxxxnxxxxxxxxxxxxxxxnnnnzzzzz##+**i;;i;:,...;:,,,,,...:ii;iii;;:,:+i;*+i::;+zxn+***i,,.,,:;;;**#ii*nxMMMMxzi*xW@@@@@@@@@@@@@@@@\n"
                           "MMMMMMMMMxxxxxxxnnnnnnnnxnxnnnnnnnxnnnxxxxxxnnnnzzzz##+*ii;;::,,.`.;;;:,,,,..,;::,,:;;;,,.*;i+*;;;i*#+;:::,,,,,:;;;ii*#i+;#nxMMMMn*;nW@W@@@@@@@@@@@@@@\n"
                           "MMMMzxMzzz##zzzxnn#znnnn##nn#zn#+#nn#znz#n###znn#**##*i;;i::::,.```:;i;:,,,..,::,.,:;;:,. i;i*+*i;;i++;*::,,,::;;;;ii+xnn*izxMMMMn*;nWWWW@@@@@@@@@@W@W\n"
                           "MMMn i+`;, `i,.nn+ *nnnn,`#;`+; ``;z`;n,`#  ``+*```.;   ., :;:    `.;;:,,...,.,.`.,:::,.``::i*##***#x;i+i*:,:;;;;iiii+xxxzi+xMMMMz#+#xWWW@@@@@@@@@WWWW\n"
                           "MMMn :`,xz`:n,.nn+ innnn#`,`:+ :z,`+ ;n,`+ ;* ;: i+i; :;i, :;, `,::;::,,.......``.,:,,.   ;;;i#++#++i::,;**;:;iiiiii*nxxxn*;zxMMx+n#izMWW@@@@@@@@@WWWW\n"
                           "WMMn   #Mn`:x,.nn+ *xxnxn; `#i +n* i ;n,`+ ..`+i  `i;   :, ;::`  `;::,,..``.``````,,,.`   ,+:;i+#*++***i;;;;i*iiii*i+xxxxn*,*xMMz*z+iinMWWWWWW@@@WWWWW\n"
                           "WMMn .`:xn`:x,.nn+ ixxxxn# :n* *ni i`:n,`+ .`,zz*;``: :ii, :ii`.::::,,,..`````````...``` ``+:::*#nxz###z##zz#*iiiii*nxxxxn*:inMxz*+###*nMWWWWWWWWWWWWW\n"
                           "WMMn ;; **`.#,`;;* ,;*xxnz`:nz`.;`.#.`;`,# ;i ;::;.`; .,:, .,;`.ii,`,``` ```...````.``.````,i,:*z*:,,,,,,:;;i*iiii*#nznxxn*:i*nxz+*+#z+*xWWWWWWWWWWWWW\n"
                           "WMMx:+x:;;::+i,,,*,,,;nxxz:inn+,.:#n+,.:#z,*n;:i,.,**,..:;,..:.:*i:`,``` ```..```  ``..`````n::+z*i,.....:;;;*iii*#xxznnnz;:ii+zn++++z**zMWWWWWWWWWWWW\n"
                           "WMMMMMMMMMMxxxxxxxnnnnnnnnnzznnzznnnnnnnnnnnnnnnnzzz##+####+***i;;,,..` ```````` ``,,..` ```*+,+#zzi:,,:i*i;i**ii+Mx+#xnn#*;;i;*z+#**+**+xWWWWWWWWWWWW\n"
                           "MMMMMMMMMMMMMxxxxxnnnnnnnnz##zzznnnnnnnzznnnnnxxnnzzz##zz##+**i;:,..`  `````..,.``.,:.``   `.n:iznnxxxMxz*iiiiii*xW+*#nnzi#z+:::***i*z+**zxWWWWWWWWWWW\n"
                           "MMMMMMMMMMMMMxxxxxxnnnnnzz#++#zzz#zzzzz##zznnnxnnzz###zzz##+*i;:,.```  .,..,:::``.,,:,`` ```.i#;znn#++*i;;;;iii*zWz**##n#+nnn+:,:i;:+zzi#++nMWWWWWWWWW\n"
                           "MMMMMMMMMMMMMxxxxxxx#,,#z#;.i++i.``:+z;.;#z:,inz,,+,.+zzz#++*i;:..``...,,.,,::,..`,,,,`   ``.,z*+z#+i;,,,::;;i+nWz*ii+#z+znxxz;:,:;:+##+###+xMWWMWWWWW\n"
                           "WMMMMMMMMMMMxxxxxxxx+  ,z#, ;+:  `` `+; .+#` ,n# .#` +zz##++*i:,....,,.,..,,,:..`,,,,,``..``..:n+zz+*;:::;;;i#xWn+iii*++#znxxx#:,`.,*#*++#+*+xMWMMMMWW\n"
                           "MMMMMMMMMMMMxxxxxxxx+   i#, ;*` ;++. :* `+*  `z* :#` +z###+##i:,.::,,,,,....::`...,,..``.,,...,#Mxnz+*iii**+zWWn+*i;i*++++nxxxz;:.  ,;i#zzz+izxxMMMMMW\n"
                           "MMMMMMMMMMMMxxxxxxxx+ .``+: ;i .###i .+` +: . +: *z.`#zzzzznz*i;;i;,,,;;,...,...`.:;.`..,;*+*:.iM@WMxz###nnMW@x+*i;;i*+****zMMnii;.  `:+znzz*+nMMMMMMM\n"
                           "MMMMMMMMMMMMxxxxxxxn* ,i ,: i; ,#zz* `#, i..i ;.`#z.`#zznznnz#*iii;ii;iii:,,,`.`,::;:..:i*###*.:zW@@@@WWWW@@@x#*ii;;i**iiiii#WM**+;`  .;#nxn#*nMWWMMMM\n"
                           "MMMMMMMMMxMxxxxxnnnz* ,z, ` ii .zzzi .zi . :# .`.zz,`#nnxxnnz#+**+++++*+*i;;,`..::,;;,,;i+###*:xxMW@###@@@@@xz*iii;;;ii;;;;;#W@M#+i:. `:*znxz*zxMWMMMM\n"
                           "MMMMWMMMMMxxxxnnnzzz* ,z#`  i#` ;z+. iz#   *n.  ;zz*izxxxxxnzz#++#z##+++++*;,`.,;::i;::*+#zzzxM#MzMMW@@@@@Wn#+*ii;;;;;;;:::*WW@WM+i;;.`,i+znn#+nMMMMMx\n"
                           "MMMWWWWWMMxMxnzzzznn* ,nni  ini  `` ,znz. `zn:  *z#``#xxxxxnnnz###z#####++*i.;,,;;;i;;;+#zMW@WW#WznxMWMMMxxn#+*ii;;;;;;:::*W@@@WWWzi+:`,ii*###*zxxxxxx\n"
                           "MMMWWWWWWWWMMnzzzznn#:innz;:+nn+:.,iznnni:;nn+::#z#:,zxxxxxnnnnzzz######++*i.::,;;i;;;izW#@#@@@@WnzxxMxnnnnz++*ii;;;;;;::+@@@WWWWMM##;.,ii;*++**nnnnzz\n"
                           "MMWWWWWWWWWWMnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnxnnnnzzznnnnnnnnnnzzznxz###++++*i,;;;iiiii*z@##@@@W@@WM+nxnz####+**iii;;;;;::zW@@WWWWWWWMn*,:;iii+++i#znnnn\n"
                           "WWWWWWWWMMWWMMMnnnnnnnnnnnnnnnnnnxxxxnnnnnnxnnnnnnnnxxnnnnnnnzzzxxnz##++++*i,ii*++**+x@###@@@M@WWWiznnz#+++*iiiiii;;;:ixW@@WWWWWWWWMxz;;;;**i**i#zxxxn\n"
                           "@@WW@WWWWMWWMMMxnnnnnnxnnnnnnnnnxMMxxxxnnnnxxxxxxxxxxxxnnxnnnnnnnxMMnz###++;,i*++++nW@@@@@@@WWWWMW*#zz#+*+**iiiiii;;;#WW@WWMWWMMMMMMMMn**i*+++++*znxnn\n"
                           "@@@W@@W@WMWWWMWMMMMMxnnnxxxnnnxxMMMMxxxxxxxxxxxMMxxxMxxxxxxxnnnnMWWWWxzz##+i.***#zMWW@@@@@@@MxMMxMn+#z#+*+*iiiiii;;*MWWWWMMMMMMMMxxnzxMxz+i##+##+i#znz\n"
                           "@@@W@@@@@W@WWMWWWWWWMxxMWWMMxxxxMWWMMMMMMMxxxxMMMMMMMMxxMMMMxxxxW@WWWMxz#++,i+*+nxMWWW@@@@WWxxxx#*;;:i##+**i;;;;;*xWWWWMMMxMMxxxxnii;+xMnz;*#z###***##\n"
                           "@@@@@@@@@@@@WWWWWWWWMxMWWWMMMMMxWWWWMMMMMMMMMMMMMxMMMMMMMMMMMMW@W@WMMMxxz+i:+*zxzMW@@WWWWWWMnn+;*zMWz;:;iii;:::+xWWWWMMMxxxxxxxn+ixWM+ii*+*i*#z#+*;*+#\n"
                           "@@@@@@@@@@@@@@WWWWWWMMMWWWWWWWWWWWWWWWMMMMMMMMMMMxMMMMxxxMMMM@@WW@WWMMxxn#*i*zn#nMWWWMMxMMx#*#zW@@@@Wz+i:.,:i#xMWWMMMxxxxnxxnz*izWWWWWWMMnz+:;**+*;i*+\n"
                           "@@@@@@@@@@@@@WWWWWMMMMMWWWWWW@@@WWWWWWMMMMMMMMMxxxxxxxxxxxMMM@@@W@WWMMxxnz#:**+nMWWWWMMzxzi#W@@@@#@@@@@WWMn+izxxMMMxxxnnz#i;:izWWMMMMWWWMMMMz*:,;i::i+\n"
                           "@@@@@@@@@@@@@@WWWWWWWWWWW@@@@@###@WWWWWMMMMMxxxxxxxxMMxxnnxM@@@@W@WWMMxxnnz;iznxMMMMMMx#:+W@@@@@@@#@@@@@@@WWM+inxxnnnz*::+zMMMWMMMMMMMxxxMMMxzz*,..,;*\n"
                           "@@@@@@@@@@@@@@@@@WWWWWW@#@@@@######@@WWMMMxxxxxM@@W###@WMnMW#@@@@@WWMMMxxnz#:,izxxnzzz*inn@@@@W@@@@@@@@@WWW@@@M*izz#*,;nMMMMMMxnxMMMMWWWWWWWWWx+**:.:i\n"
                           "@@@@@@@@@@@@@@@@@@W@WW@##############@MxxxxxxxnM##@######WW@#@@@@@WWMMxxxnnWWni:**+znnz@@MW@@@@@@@@@@@@@@@@WWWWWni,,,nMMMMMMn**xMMMMMWWWMWWWWWxW##z*.;\n"
                           "@@@@@@@@@@@@@@@@@@@@@#################@WMxxxxnnW#############@@@@@WWMMMxxxxWWW@W@@@@@@@@@@W@@@@@@@@@@WWWWWWWWWWWWMMxzMMMWMMz, `nxxMMMMMMMMMWWWxWW*##:.\n"
                           "@@@@@@@@@@@@@@@@@@@@@####################WxxxMM#######@#####@@@@@WWWMMMxxxMWWW@W@@@@WWW@W@@@@@@@WWW@@@WWWWWWWWWWWWWnxMWMMMn`` .nnxMMMMMMMMMWMxMWWn#+;`\n"
                           "@@@@@@@@@@@@@@@@@@@###########################@##############@@@@WWWMMMxxxW@WW@@W@Wn;i+nxMWWWWWWWWWWWWWWMWWWWWWWWMMnMMWMMMx,, .nnxMMMMMMMMMMMxWMMMxxn;\n"
                           "@@@@@@@@@@@@@@@@@@#############@###############@######@#######@@@WWWMMMxxMW@WW@@WM*ixx+*;,iMWWWWWWWWWWWWWWWWWWWWWMMMMMWMMxn*`;;nxMxMMMMMMMMMMMMMMMxxnn\n"
                           "@@@@@@@@@@@W@@@@###############@@#######@#####################@@@@WWWMMxzMW@@WMWM:*MW@WWWx*:MWWWWWWWWWWWWWWWWWWWMMMMMMMWWMMxzxnnxMxnxMMMMMMMMMMMMMMxnz\n"
                           "@@@@@@@@@@@@W@@#################@#######@#####################@@@@WWWMMxxWW@@+;*:#MW@@@WWWW#+WWWWWWW@WWWWWWWWWWMxMMxxMMMMMMMMM++xz:,,*MMMMMWMMMMMMxzzn\n"
                           "@@@#@@@@##@@@@##################@########@#####################@@@@WWMMMMW@@W,::+xMW@WWWWWWxiWWWWWWW@@WWWWWMWWxnnzz++nMMMMMMMxxnn,inx*#MMMMMMMMxxxnxnn\n"
                           "@####@@###@@#@#####@#################@###@###################@#@@@@WWMMMM@W@W;.`,,.nWWWWWWWM:xMWWWWW@WWWWWWMxMxMMMx:`;zMMMMMxnxxn.*xMx;MxxxxxMxxMMMn+#\n"
                           "###############################@##@##@@########################@@@@WWWMMW@@@@MnxWM:,MWWWWWWWi*WWWWW@WWWWWWWMxnxMMxz  ,nznnnz#+*#,.zMMx;nnMMMMMMMM+;:*,\n"
                           "###################@###########@##@#@#@@#######################@@@@WWWMW@@@@@WWW@W#.MWWWWWWW#;MWMWWW@WWWWWMi,;;iz+, ``,*nMMxz,:,zznnxn:nMMMMMWMM*+xxnz\n"
                           "#####################################@#@###################@####@@@@WWWW@@@@@W@@@Wx*WWWWWWWWx,zMMWWWWWWWMM#;znxniii#nzi,zx#;;#x#zMxi#:*MMMMWWMMz*MMxnn\n"
                           "################@####################@#@###################@####@@@@@WWW@@@@@W@@@Wz#WWWWWWWWMz,xMWW@@WWWW#;#MMMMMMMMMMMx;:,+xMMn*xn,.ixnMMWWMM*ixMMxnn\n"
                           "#########@###########################@#@########################@@@@@WWW@@@@@@@@@WMiMWWWWWWWWz:xMWM@@WWWx:xxzxxMMMMMMWMMn`:#xxMMx+;;nMMzMWWMM#*MMMMMxn\n"
                           "################@####################@###########@###############@@@@@WWW@zWW@@@@WWz:nMWWWWWx,nMMWMW@MWM;zMMM#MMMMxMMMMMx#+,*#Mxxx+inMxMWMxxi#MMMWMMxx\n"
                           "################@####################@#########@#W#####################@W@M@WMM@WW#x*.;*xMWW*zMMWWMWWMM#*MWWx+#xMMxMMMWMz;;:.#xzxM#.zxWWxxzinMMWWWMxxx\n"
                           "##@##############################################W######################@MnMnxWxnzzx:````;zn,#MMWWMWWx+:xWWWxz#nMMxMMWWMMxx* ...nx;:,#WMMzixMMMWWMMxxx\n"
                           "##@##############@###############################@############@#########@@@WWMWMW@W+,z; .;,``ixMWWMW#,.nWWWWMzxxnMxMMMWMMMxi`*+*.,`*,inxx*#MMMWMMWMMMx\n"
                           "##@###############################################@###########@#########@@@@@xMW@@W#*xz *Mx+`.z#nxMM+ :nMWWWWMMznMxMWMWWWMzzn,:x; :MMz;ix**MMMWWWWMxMM\n"
                           "##@@#############@################################@######@##############@@@@@WW@@@Wx;xn;`*+:  ,`*nMMM* .nWWWWWWMnxxWWWMMWxxWM:.#,+:;nz;.,;nWMMMWWWMMWW\n"
                           "###@##############################################@######@#############WWW@@@MW@@@Wn+WWx+:. .*#zxMMWMn.;xWWWWWWMnMMWWWWMWnWMM#`,nWWn#+nMxMMMWWWWWWMMWW";
                break;
        }

    }
    return 0;
}
