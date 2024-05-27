#pragma once
#include"Client.h"
#include"Users.h"

class Controller
{
public:
	Controller() { users = new User(); }
	~Controller(){}

	void registerUser(Client*& client){

		boxInput(10, 14, "User:", user);
		client->setUser(user);

		boxInput(45, 14, "Password:", password);
		client->setPassword(password);
	}
	
	void registerData(Client*& client){

		boxInput(80, 14, "Nombre:", name);
		client->data->setName(name);

		boxInput(10, 17, "Apellido:", lastname);
		client->data->setLastName(lastname);

		boxInput(45, 17, "DNI:", dni);
		client->data->setDNI(dni);
		
		boxInput(80, 17, "Edad:", age);
		client->data->setAge(age);

		boxInput(10, 20, "Telefono:", phone);
		client->data->setPhone(phone);
	}

	void registerCompany(Client*& client) {

		boxInput(45, 20, "Nombre Empresa:", name_company);
		client->company->setNameCompany(name_company);

		boxInput(80, 20, "Ruc Empresa:", ruc);
		client->company->setRuc(ruc);
	}

	void option1() {  
		system("cls");

		boxInterface();

		Client* client = new Client();
		
		recordsTitle();

		registerUser(client);
		registerData(client);
		registerCompany(client);
		
		if (!users->clientExists(client)) {
			users->registerClient(client);
			position(9, 26);
			color::setTxtBgColor(color::LIGHT_WHITE, color::BG_DARK_GREEN);
			cout << "Cliente registrado";
			color::reset();
		}
		else {
			position(9, 26);
			color::setTxtBgColor(color::LIGHT_WHITE, color::BG_RED);
			cout << "El usuario ya existe";
			color::reset();
		}

		system("pause>>null");
		system("cls");
		
		boxAscii();
		drawMenu();
	}

	void option2() { 
		cout << "Ingerse el usuario a buscar: ";
		cin >> user;
		users->searchUser(user);
	}


private:
	User* users;
	
	string name, lastname, name_company, user, password;
	int dni, age, phone, ruc;
};