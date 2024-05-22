#pragma once
#include"Headers.h"

class Driver
{
public:
	Driver(string _name_driver = "", short _age = 0) {
		this->name = _name_driver;
		this->age = _age;
	}

	~Driver() {}

	string getDriver() {
		ostringstream print;
		print << "\n\n\tConductor del vehiculo\n";
		print << "\n Nombre Conductor: " << name;
		print << "\n Edad Conductor: " << age;

		return (print.str());
	}

	string drive() {
		ostringstream print;
		print << endl << name << " esta a cargo del vehiculo\n";
		return print.str();
	}

	string getName() { return name; }
	short getAge() { return age; }

private:
	string name;
	short age;

};