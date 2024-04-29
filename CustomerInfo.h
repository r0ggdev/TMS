#pragma once
#include"Headers.h"

class CustomerInfo
{
public:
	CustomerInfo() {
		this->name[0] = '\0';
		this->lastname[0] = '\0';
		this->ID = 0;
		this->DNI = 0;
		this->age = 0;
		this->phone = 0;
	}

	CustomerInfo(char _name[], char _lastname[], int _DNI, short _age, int _phone) {
		strcpy_s(this->name, sizeof(name), _name);
		strcpy_s(this->lastname, sizeof(lastname), _lastname);

		this->DNI = _DNI;
		this->age = _age;
		this->ID = createID(name);
		this->phone = _phone;
	}

	~CustomerInfo() {}

	void setName(char _name[]) { strcpy_s(this->name, sizeof(name), _name); }
	void setLastName(char _lastname[]) { strcpy_s(this->lastname, sizeof(lastname), _lastname); }
	void setDNI(int _DNI) { this->DNI = _DNI; }
	void setAge(short _age) { this->age = _age; }
	void setPhone(int _phone) { this->phone = _phone; }

	short getID() { return this->ID; }
	string getName() { return string(name); }
	string getLastName() { return string(lastname); }
	int getDNI() { return DNI; }
	short getAge() { return age; }
	int getPhone() { return phone; }

	string showCustormerInfo() {
		ostringstream  print;
		print << "\n\nID: " << ID;
		print << "\nnombre: " << name;
		print << "\nApellidos: " << lastname;
		print << "\nDNI: " << DNI;
		print << "\nEdad: " << age;
		print << "\nTelefono: " << phone;
		return (print.str());
	}

private:
	int createID(char name[]) {
		srand(time(nullptr));

		int value1 = abs(int(*name));
		int value2 = DNI % 1000;
		int suffix = rand() % 1000;

		int value = (value1 * 1000) + value2 + suffix;
		return abs(value);
	}

protected:
	char name[50];
	char lastname[50];
	int DNI;
	int ID;
	short age;
	int phone;
};