#pragma once
#include"Headers.h"

class CustomerInfo
{
public:
	CustomerInfo(string _id="", string _name = "", string _lastname = "", int _DNI = 0, short _age = 0, int _phone = 0) {
		this->name = _name;
		this->lastname = _lastname;
		this->dni = _DNI;
		this->age = _age;
		this->id = encryption(_id, 4);
		this->phone = _phone;
	}

	~CustomerInfo() {}

	void setName(string _name) { this->name = _name; }
	void setLastName(string _lastname) { this->lastname = _lastname; }
	void setDNI(int _DNI) { this->dni = _DNI; }
	void setAge(short _age) { this->age = _age; }
	void setPhone(int _phone) { this->phone = _phone; }
	void setID(string _id) { this->id = _id;}


	string getName() { return name; }
	string getLastName() { return lastname; }
	int getDNI() { return dni; }
	int getPhone() { return phone; }
	short getAge() { return age; }
	string getID() { return id; }

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

protected:
	string id, name, lastname;
	int dni, phone;
	short age;
};