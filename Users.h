#pragma once
#include"Client.h"
#include"Lists.h"

class User
{
public:
	User() { lstClients = *new LinkedList<Client*>(); }
	~User() {}

	void setDirectory(string _user) {
		ostringstream  print;
		print << ".\\Users\\";
		print << _user;
		print << ".dat";
		directory = (print.str());
	}

	void registerClient(Client* client) {
		lstClients.addInitial(client);
		setDirectory(client->getUser());

		fileWrite.open(directory, ios::binary);

		if (fileWrite.is_open()) {
			fileWrite << client->getUser();
			fileWrite << endl;
			fileWrite << client->getPassword();
			fileWrite << endl;
			fileWrite << client->data->getID();
			fileWrite << endl;
			fileWrite << client->data->getName();
			fileWrite << endl;
			fileWrite << client->data->getLastName();
			fileWrite << endl;
			fileWrite << client->data->getAge();
			fileWrite << endl;
			fileWrite << client->data->getDNI();
			fileWrite << endl;
			fileWrite << client->data->getPhone();
			fileWrite << endl;
			fileWrite << client->company->getNameCompany();
			fileWrite << endl;
			fileWrite << client->company->getRuc();
			fileWrite << endl;

			fileWrite.close();
		}
		else {
			cout << "No se pudo crear el archivo para el cliente." << endl;
		}
	}

	string getPassFile(string user) {
		setDirectory(user);
		fileRead.open(directory);
		if (fileRead.is_open()) {
			getline(fileRead, line);
			fileRead.close();
		}
		return line;
	}
	string getUserFile(string user) {
		setDirectory(user);
		fileRead.open(directory);
		if (fileRead.is_open()) {
			getline(fileRead, line);
			getline(fileRead, line);
			fileRead.close();
		}
		return line;
	}

	void loadUsers() {
		for (int i = 0; i < lstClients.listLength(); i++) {
			Client* client = lstClients.getPosition(i);
			fileRead.open(directory, ios::out);

		}
	}

	void searchUser(string _user) {
		for (int i = 0; i < lstClients.listLength(); i++) {
			if (lstClients.getPosition(i)->data->getName() == _user || lstClients.getPosition(i)->getUser() == _user) {
				cout << lstClients.getPosition(i)->showAdminInfo();
				break;
			}

		}
	}

private:
	LinkedList<Client*> lstClients;

	ofstream fileWrite;
	ifstream fileRead;
	string line, text, directory;

};
