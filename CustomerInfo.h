#pragma once
#include"Headers.h"

class CustomerInfo
{
public:
	CustomerInfo(string _name = "", string _lastname = "", int _DNI = 0, short _age = 0, int _phone = 0) {
		this->name = _name;
		this->lastname = _lastname;
		this->dni = _DNI;
		this->age = _age;
		this->id = createID(name);
		this->phone = _phone;
	}

	~CustomerInfo() {}

	void setName(string _name) { this->name = _name; }
	void setLastName(string _lastname) { this->lastname = _lastname; }
	void setDNI(int _DNI) { this->dni = _DNI; }
	void setAge(short _age) { this->age = _age; }
	void setPhone(int _phone) { this->phone = _phone; }

	string getName() { return name; }
	string getLastName() { return lastname; }
	int getDNI() { return dni; }
	int getPhone() { return phone; }
	short getAge() { return age; }
	short getID() { return id; }

	string showCustormerInfo() {

		ostringstream  print;
		print << "\n\n\tDatos Personales\n";
		print << "\n ID: " << id;
		print << "\n Nombre: " << name;
		print << "\n Apellidos: " << lastname;
		print << "\n DNI: " << dni;
		print << "\n Edad: " << age;
		print << "\n Telefono: " << phone;
		
		return (print.str());
	}

private:
	int createID(string _name) {

		srand(time(nullptr));
		
		char name_convert[_size_];
		strcpy(name_convert, _name.c_str());

		int value1 = abs(int(name_convert));
		int value2 = dni % 1000;
		int suffix = rand() % 1000;
		int value = (value1 * 1000) + value2 + suffix;
		
		return abs(value);
	}

protected:
	string name, lastname;
	int dni, id, phone;
	short age;
};