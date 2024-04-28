#pragma once
#include"Companie.h"
#include"CustomerInfo.h"

class Client {
public:
	Client(char _name[], char _lastname[], int _DNI, short _age, int _phone, char _nameCompany[], int _RUC, char _user[], char _password[]) {

		data = new CustomerInfo(_name, _lastname, _DNI, _age, _phone);
		companie = new Companie(_nameCompany, _RUC);

		strcpy_s(password, sizeof(password), _password);
		strcpy_s(user, sizeof(user), _user);
	}
	~Client() {}

	string showAdminInfo() {
		ostringstream  print;

		print << data->showCustormerInfo();
		print << companie->showCompanie();
		print << "\n\n\n";
	
		return print.str();
	}

	string getUser() { return string(user); }
	string getPassword() { return string(password); }



public:
	CustomerInfo* data;
	Companie* companie;
private:
	char password[8];
	char user[20];
};
