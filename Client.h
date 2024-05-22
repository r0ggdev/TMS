#pragma once
#include"Company.h"
#include"CustomerInfo.h"

class Client {
public:
	Client(string _name, string _lastname, int _DNI, short _age, int _phone, string _name_company, int _ruc, string _user, string _password) {

		data = new CustomerInfo(_name, _lastname, _DNI, _age, _phone);
		company = new Company(_ruc, _name_company);
	
		this->user = _user;
		this->password = _password;
	}
	
	Client() {
		data = new CustomerInfo();
		company = new Company();

		this->user = "";
		this->password = "";
	}

	~Client() {}

	string showAdminInfo() {
		ostringstream  print;
		color::setTextColor(color::BLUE);
		cout << R"(
		#############################
		#  Informacion del Cliente  #
		#############################
					)";
		color::reset();

		print << data->showCustormerInfo();
		print << company->showCompany();

		return (print.str());
	}

	string getUser() { return user; }
	string getPassword() { return password; }

public:
	CustomerInfo* data;
	Company* company;

private:
	string password;
	string user;
};