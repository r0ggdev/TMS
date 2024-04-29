#pragma once

#include"Menu.h"
#include"Client.h"
#include"User.h"
#include"Ruta.h"
#include "Inconvenientes.h"
#include "Comentarios.h"
#include "Servicio.h"
#include "Entrega.h"

#include<conio.h>

class Controller
{
public:
    Controller(){
        *user = '/O';
        *password = '/O';
        
        verify = '/O';

        *name = '/O', * lastname = '/O', * name_company = '/O';
        *DNI = '/O', *RUC = '/O', *phone = '/O';
        *age = '/O';

        //clients = *new LinkedList<User*>();
        Users = new User();

        lstr = *new LinkedList<CRuta*>();
        lste = *new LinkedList<CEntrega*>();
        lsts = *new LinkedList<CServicio*>();
        lsti = *new LinkedList<CInconvenientes*>();
        lstc = *new LinkedList<CComentarios*>();
    }
    ~Controller() {}

    void menu() {
        int x = 50, z = 20, y = 0;
        title();
        while (1) {

            color::setTxtBgColor(color::WHITE, color::BG_BLACK);
            select("     LOGIN     ", x, z + 0, y == 0);
            select("    SIGN IN    ", x, z + 1, y == 1);
            select("     SALIR     ", x, z + 2, y == 2);

            int op = _getch();
            switch (op) {
            case ARRIBA:
                y--;
                if (y < 0) { y = 2; }
                break;

            case ABAJO:
                y++;
                if (y > 2) { y = 0; }
                break;

            case enter:
                switch (y) {
                case 0:
                    registerUser();
                    break;

                case 1:
                    session();
                    break;

                case 2:
                    exit(0);
                    break;
                }
                break;
            }
        }
    }

    void session() {
        do {
            system("cls");
            color::setTextColor(color::CYAN);
            cout << R"(
                 ___       _      _         ____            _             
                |_ _|_ __ (_) ___(_) __ _  / ___|  ___  ___(_) ___  _ __  
                 | || '_ \| |/ __| |/ _` | \___ \ / _ \/ __| |/ _ \| '_ \ 
                 | || | | | | (__| | (_| |  ___) |  __/\__ \ | (_) | | | |
                |___|_| |_|_|\___|_|\__,_| |____/ \___||___/_|\___/|_| |_|
                            
                             logeese con x para salir 
)";
            color::reset();
            cout << "\nIngrese su user: ";
            color::dataEntry(user, color::CYAN);

            cout << "\nIngrese su password: ";
            dataEntry(password);

            if (user[0] == 'x' && password[0] == 'x') {
                break;
            }

        } while (!login());

        if (login()) {
            char value[50] = "";

                do {
                    system("cls");

                    cout << "\nBienvenido, que desea hacer: ";
                    cout << "\n 1. Ver info: ";
                    cout << "\n 2. Hacer un pedido:";
                    cout << "\n 3. Ver reportes: ";
                    cout << "\n 4. Cerrar sesion";

                    cin >> value;
                } while (!isDigit(value));

                int temp = atoi(value);
                
                switch (temp) {
                case 1: 
                    Users->searchUser(usernow);
                    _getch();
                    break;
                
                case 2:
                case 3:
                case 4:
                    break;

                default:
                    break;
                }


            _getch();
        }

        system("cls");
        title();
    }

    bool login() {
        if (Users->getPassFile(user) == user && Users->getUserFile(user) == password) {
            usernow = user;
            return true;
        }
        return false; 
    }

    void dataEntry(char* input) {
        int i = 0; char charcter;
        
        while (true) {
            charcter = _getch();
            if (charcter == enter) { break; }
            
            else if (charcter == backspace) {
                if (i > 0) { cout << "\b \b"; i--; }
            }
            else {
                input[i++] = charcter;
                color::setTextColor(color::CYAN);
                cout << '*';
                color::reset();
            }
        }

        input[i] = '\0';
    }


    void registerUser() {
        system("cls");
        color::setTextColor(color::SKY_BLUE);
        cout << R"(

                 ____            _     _                      
                |  _ \ ___  __ _(_)___| |_ _ __ ___  ___  ___ 
                | |_) / _ \/ _` | / __| __| '__/ _ \/ __|/ _ \
                |  _ <  __/ (_| | \__ \ |_| | |  __/\__ \  __/
                |_| \_\___|\__, |_|___/\__|_|  \___||___/\___|
                           |___/                              

                       escriba _ para salir
            

)";
        color::reset();

        cout << "\nCree su user: ";
        color::dataEntry(user, color::SKY_BLUE);

        if (user[0] != '_') {

            cout << "\nCree su password: ";
            color::dataEntry(password, color::SKY_BLUE);

            system("cls");
            color::setTextColor(color::SKY_BLUE);
            cout << R"(

                 ____        _              ____                                 _           
                |  _ \  __ _| |_ ___  ___  |  _ \ ___ _ __ ___  ___  _ __   __ _| | ___  ___ 
                | | | |/ _` | __/ _ \/ __| | |_) / _ \ '__/ __|/ _ \| '_ \ / _` | |/ _ \/ __|
                | |_| | (_| | || (_) \__ \ |  __/  __/ |  \__ \ (_) | | | | (_| | |  __/\__ \
                |____/ \__,_|\__\___/|___/ |_|   \___|_|  |___/\___/|_| |_|\__,_|_|\___||___/
            

)";
            color::reset();
            cout << "\nIngrese su Nombre: ";
            color::dataEntry(name, color::SKY_BLUE);

            cout << "\nIngrese su Apellido: ";
            color::dataEntry(lastname, color::SKY_BLUE);

            do
            {
                color::reset();
                cout << "\nIngrese su DNI: ";
                color::setTextColor(color::SKY_BLUE);
                cin >> DNI;
                color::reset();
            } while (!isDigit(DNI));
            do
            {
                color::reset();
                cout << "\nIngrese su Edad: ";
                color::setTextColor(color::SKY_BLUE);
                cin >> age;
                color::reset();
            } while (!isDigit(age));

            do
            {
                color::reset();
                cout << "\nIngrese su Telefono: ";
                color::setTextColor(color::SKY_BLUE);
                cin >> phone;
                color::reset();
            } while (!isDigit(phone));


            system("cls");
            color::setTextColor(color::SKY_BLUE);
            cout << R"(

                 ____        _              _____                                     
                |  _ \  __ _| |_ ___  ___  | ____|_ __ ___  _ __  _ __ ___  ___  __ _ 
                | | | |/ _` | __/ _ \/ __| |  _| | '_ ` _ \| '_ \| '__/ _ \/ __|/ _` |
                | |_| | (_| | || (_) \__ \ | |___| | | | | | |_) | | |  __/\__ \ (_| |
                |____/ \__,_|\__\___/|___/ |_____|_| |_| |_| .__/|_|  \___||___/\__,_|
                                                           |_|                        
            

)";
            color::reset();
            cout << "\nIngrese el nombre de su empresa: ";

            color::dataEntry(name_company, color::SKY_BLUE);

            do {
                color::reset();
                cout << "\nIngrese el RUC de su empresa: ";
                color::setTextColor(color::SKY_BLUE);
                cin >> RUC;
                color::reset();
            } while (!isDigit(RUC));

            _Age = atoi(age);
            _DNI = atoi(DNI);
            _RUC = atoi(RUC);
            _Phone = atoi(phone);

            //clients = new Client(name, lastname, _DNI, _Age, _Phone, name_company, _RUC, user, password);
            Users->registerClient(new Client(name, lastname, _DNI, _Age, _Phone, name_company, _RUC, user, password));

            system("cls");
            color::setTextColor(color::GREEN);
            cout << R"(
                 ____            _     _                         _ _                  
                |  _ \ ___  __ _(_)___| |_ _ __ ___     _____  _(_) |_ ___  ___  ___  
                | |_) / _ \/ _` | / __| __| '__/ _ \   / _ \ \/ / | __/ _ \/ __|/ _ \ 
                |  _ <  __/ (_| | \__ \ |_| | | (_) | |  __/>  <| | || (_) \__ \ (_) |
                |_| \_\___|\__, |_|___/\__|_|  \___/   \___/_/\_\_|\__\___/|___/\___/ 
                           |___/                                                      
        )";

            color::reset();
        //cout << clients->showAdminInfo();
            system("pause");

        }
        system("cls");
        title();
    }


private:

   User* Users;

   string usernow;
    char user[50];
    char password[50];

    char name[50], lastname[50], name_company[100]; 
    char DNI[50], RUC[50], phone[50], age[10];

    int _DNI, _RUC, _Phone, _Age;

    char verify;

    LinkedList<CRuta*> lstr;
    LinkedList<CEntrega*> lste;
    LinkedList<CServicio*> lsts;
    LinkedList<CInconvenientes*> lsti;
    LinkedList<CComentarios*> lstc;

};

