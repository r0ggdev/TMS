#pragma once
#include"Client.h"
#include"Users.h"
#include "Profile.h"

#define subMenu_X 46
#define subMenu_Y 15
#define subMenu_W 30
#define subMenu_H 3

class Controller
{
public:
	Controller() {
		users = new User();
		confirmationMenu = new MenuLibrary::RightLeft::AllOptions(subMenu_X, subMenu_Y, 2, 62, 0, color::BG_GRAY, color::BG_YELLOW);
		userMenu = new MenuLibrary::RightLeft::AllOptions(subMenu_X-15, subMenu_Y+5, 5, 127, ' ', color::CYAN, color::BG_BLACK);

		confirmation = false;
		optionsMenu[0] = { "Aceptar" };
		optionsMenu[1] = { "Cancelar" };
	}
	~Controller() {}
	
	void menuConfirmation(bool& confirmation) {
		confirmation = false;
		bool bucleConfirmation = false;

		color::setBackgroundColor(color::BG_YELLOW);
		boxAscii(subMenu_X - 4, subMenu_Y - 2, subMenu_W, subMenu_H);
		confirmationMenu->setColorReset(color::BLACK, color::BG_YELLOW);

		functionsSubMenu = {
			[&confirmation, &bucleConfirmation]() {
				confirmation = true;
				bucleConfirmation = true;
				clearArea(subMenu_X - 4, subMenu_Y - 2, subMenu_W, subMenu_H);
			},
			[&confirmation, &bucleConfirmation]() {confirmation = false; bucleConfirmation = true; }
		};

		confirmationMenu->addOptions(optionsMenu, functionsSubMenu);

		while (!bucleConfirmation) {
			confirmationMenu->showMenu();
		}
		color::reset();
	}

	void registerUser(Client*& client) {

		do {
			boxInput(10, 14, "User:", user);
			client->setUser(user);
			if (user == "*") { return; }
		} while (users->clientExists(client));

		boxInput(45, 14, "Password:", password);
		client->setPassword(password);
	}

	void registerData(Client*& client) {

		boxInput(80, 14, "Nombre:", name);
		client->data->setName(name);

		boxInput(10, 17, "Apellido:", lastname);
		client->data->setLastName(lastname);

		do { 
			msgbox("El rango es de 8 digitos", color::YELLOW);
			boxInput(45, 17, "DNI:", dni); 
		} while (dni < 10000000 || dni > 999999999);
		client->data->setDNI(dni);

		do { 
			msgbox("El rango de edad es de 20 a 50", color::YELLOW);
			boxInput(80, 17, "Edad:", age); 
		} while (age < 20 || age > 50);
		client->data->setAge(age);

		do { 
			msgbox("Debe tener 9 cifras", color::YELLOW);
			boxInput(10, 20, "Telefono:", phone); 
		} while (phone < 900000000 || phone > 999999999);
		client->data->setPhone(phone);
	}

	void registerCompany(Client*& client) {

		boxInput(45, 20, "Nombre Empresa:", name_company);
		client->company->setNameCompany(name_company);

		do { 
			msgbox("El rango es de 8 digitos", color::YELLOW);
			boxInput(80, 20, "Ruc Empresa:", ruc); 
		} while (ruc < 10000000 || ruc > 999999999);
		client->company->setRuc(ruc);
	}

	void menuUser(string& _user) {
		bool exit = false;
		Profile profileUser(users);

		system("cls");
		boxAscii();
		const char* options[]{ "Perfil","Pedidos","Reportes","Ordenamiento", "Salir"};

		vector<function<void()>> functions = {
			[&exit, &profileUser, &_user]() {
				exit = true;
				system("cls");
				profileUser.profile(_user);
				cin.ignore();
				exit = false;
				system("cls");
				boxAscii();
			},

			[&exit](){
				exit = true;
				system("cls");

				cin.ignore();
				exit = false;
				boxAscii();
			},
			[&exit](){},
			[&exit](){},
			[&exit]() {exit = true; }
		};

		userMenu->addOptions(options, functions);

		while (!exit) {
			userMenu->showMenu();
		}
	}

	void clearOptions() {
		system("cls");

		boxAscii();
		drawMenu();
	}

	void option1() {
		system("cls");

		boxInterface();

		Client* client = new Client();

		recordsTitle();

		registerUser(client);
		if (user == "*") { return; }
		registerData(client);
		registerCompany(client);
		menuConfirmation(confirmation);

		if (!users->clientExists(client) && confirmation) {
			users->registerClient(client);
			position(9, 26);
			color::setTxtBgColor(color::LIGHT_WHITE, color::BG_DARK_GREEN);
			cout << "Cliente registrado";
			color::reset();
		}
		else { delete client; return; }

		Sleep(150);
	}

	void option2() {
		system("cls");

		boxInterface();
		drawLogin();

		do {
			clearBoxInput(60,14);
			boxInput(25, 14, "Usuario:", user);
			if (user == "*") { return; }
			boxInput(60, 14, "Password:", password);

		} while (!users->login(user, password));
		if (!users->searchUserList(user)) { users->loadUser(user); }
		menuUser(user);
		//cout << "Entraste";
		//cout << "Ingerse el usuario a buscar: ";
		//cin >> user;
		//users->searchUser(user);

		//system("pause");
	}


private:
	User* users;
	string name, lastname, name_company, user, password;
	int dni, age, phone, ruc;

	MenuLibrary::RightLeft::AllOptions* confirmationMenu;
	MenuLibrary::RightLeft::AllOptions* userMenu;
	const char* optionsMenu[2];
	vector<function<void()>> functionsSubMenu;
	bool confirmation;
};