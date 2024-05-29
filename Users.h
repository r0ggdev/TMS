#pragma once
#include"Files.h"
#include"Client.h"
#include"Lists.h"

#define NUM_CREDENTIALS 2
#define NUM_CLIENT_DATA 6
#define NUM_COMPANY_DATA 2

class User
{
public:
	User() {
		lst_clients = new LinkedList<Client*>();
		file_clients = new Files("Clients");
	}
	~User() {
		delete lst_clients;
		delete file_clients;
	}

private:
	struct ClientData {
		string credentials[NUM_CREDENTIALS];
		string clientData[NUM_CLIENT_DATA];
		string companyData[NUM_COMPANY_DATA];
	};

	ClientData getClientData(Client* _client) {

		ClientData data;

		data.credentials[0] = _client->getUser();
		data.credentials[1] = _client->getPassword();

		data.clientData[0] = _client->data->getID();
		data.clientData[1] = _client->data->getName();
		data.clientData[2] = _client->data->getLastName();
		data.clientData[3] = to_string(_client->data->getAge());
		data.clientData[4] = to_string(_client->data->getDNI());
		data.clientData[5] = to_string(_client->data->getPhone());

		data.companyData[0] = _client->company->getNameCompany();
		data.companyData[1] = to_string(_client->company->getRuc());

		return data;
	}

	Client* setClientData(Client* _client, string _subdirectory) {
		_client->setUser((*file_clients)[_subdirectory].get("credentials", 1));
		_client->setPassword((*file_clients)[_subdirectory].get("credentials", 2));

		_client->data->setID((*file_clients)[_subdirectory].get("data", 1));
		_client->data->setName((*file_clients)[_subdirectory].get("data", 2));
		_client->data->setLastName((*file_clients)[_subdirectory].get("data", 3));
		_client->data->setAge(stoi(((*file_clients)[_subdirectory].get("data", 4))));
		_client->data->setDNI(stoi((*file_clients)[_subdirectory].get("data", 5)));
		_client->data->setPhone(stoi((*file_clients)[_subdirectory].get("data", 6)));

		_client->company->setNameCompany((*file_clients)[_subdirectory].get("company", 1));
		_client->company->setRuc(stoi((*file_clients)[_subdirectory].get("company", 2)));

		return _client;
	}

public:

	void registerClient(Client* _client) {
		lst_clients->addInitial(_client);

		ClientData data = getClientData(_client);
		auto subdirectory = _client->data->getID();

		file_clients->createSubfolder(subdirectory);
		(*file_clients)[subdirectory].log("credentials", NUM_CREDENTIALS, data.credentials);
		(*file_clients)[subdirectory].log("data", NUM_CLIENT_DATA, data.clientData);
		(*file_clients)[subdirectory].log("company", NUM_COMPANY_DATA, data.companyData);
	}

	bool clientExists(Client* client, bool msg = true) {
		string subdirectory = encryption(client->getUser(), 4);

		if (file_clients->subfolderExists(subdirectory)&& msg){
			msgbox("El usuario ya existe", color::LIGHT_WHITE, color::BG_RED);
		}

		return file_clients->subfolderExists(subdirectory);
	}

	void loadUser(string _user) {
		auto subdirectory = encryption(_user, 4);
		Client* clientData = setClientData(new Client(), subdirectory);
		lst_clients->addInitial(clientData);
	}

	bool searchUserList(string& _user){
		auto searched = [_user](Client* a) { return a->getUser() == _user; };
		Client* customer_found = lst_clients->search(searched);
		
		return customer_found != nullptr ? true : false;
	}

	void searchUser(string& _user) {
		auto searched = [_user](Client* a) { return a->getUser() == _user; };
		Client* customer_search = new Client();
		customer_search->setUser(_user);

		if (searchUserList(_user)) {
			auto searched = [_user](Client* a) { return a->getUser() == _user; };
			cout << lst_clients->findPosition(searched);
		}
		else if (clientExists(customer_search,false)) {
			// cout << "SIIIIIUUUUUUU";
		}
		else {
			msgbox("El usuario " + _user + " no se ha podido encontrar ", color::RED);
		}

		delete customer_search;
	}

	bool login(string _user, string _password, bool msg = true) {
		auto subdirectory = encryption(_user, 4);
		string crdentialUser = (*file_clients)[subdirectory].get("credentials", 1);
		string crdentialPassword = (*file_clients)[subdirectory].get("credentials", 2);

		bool exist = crdentialUser == _user && crdentialPassword == _password ? true : false;
		bool user_exist = crdentialUser == _user && crdentialPassword != _password ? true : false;

		if (user_exist && msg) {
			msgbox("Password Incorrecto", color::LIGHT_RED);
		}
		else if (!exist && msg) {
			msgbox("El usuario no existe", color::LIGHT_RED);
		}
		return exist;
	}

private:
	LinkedList<Client*>* lst_clients;
	Files* file_clients;
};