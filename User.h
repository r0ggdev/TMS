#pragma once
#include"Client.h"
#include"lists.h"

class User
{
public:
	User(){
	}
	~User(){}

	void setDirectory(int ID) {
		ostringstream  print;
		print << ".\\Users\\";
		print << ID;
		print << ".dat";
		directory = (print.str());
	}

	void registerClient(Client* newClient) {
		lstClients.addInitial(newClient);
		
		setDirectory(newClient->data->getID());

		fileWrite.open(directory, ios::binary);

		if (fileWrite.is_open()) {
			fileWrite.write(reinterpret_cast<char*>(newClient), sizeof(Client));
			fileWrite.close();
		}
		else {
			cout << "No se pudo crear el archivo para el cliente." << endl;
		}
	}



private:
	string directory;
	LinkedList<Client*> lstClients;

	ofstream fileWrite;
	ifstream fileRead;
	string line, text;
	string directory;
};
