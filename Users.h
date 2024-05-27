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

	bool clientExists(Client* client) {
		string subdirectory = encryption(client->getUser(), 4);
		return file_clients->subfolderExists(subdirectory);
	}

	void loadUser(string _user) {
		auto subdirectory = encryption(_user, 4);
		Client* clientData = setClientData(new Client(), subdirectory);
		lst_clients->addInitial(clientData);
	}

	void searchUser(string _user) {
		Client* customer_searched = new Client();
		customer_searched->setUser(_user);

		auto searched = [](Client* a, Client* b) { return a->getUser() == b->getUser(); };

		Client* customer_found = lst_clients->search(customer_searched, searched);
		if (customer_found != nullptr) {
			color::setTextColor(color::GREEN);
			cout << customer_found->showAdminInfo();
		}
		else {
			position(msgX, msgY);
			color::setTextColor(color::RED);
			cout << "El usuario " << _user << " no se ha podido encontrar";
		}
	}

private:
	LinkedList<Client*>* lst_clients;
	Files* file_clients;
};