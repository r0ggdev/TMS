#pragma once
#include"Headers.h"

class Driver
{
public:
	Driver(char _name[] = "", short _age = 0) {
		strcpy_s(name, sizeof(name), _name);
		name[sizeof(name) - 1] = '\0';

		this->age = _age;
	}
	~Driver(){}

	string getDriver(){
		ostringstream print;
		print << "\n\tConductor del vehiculo";
		print << "\n\nNombre Conductor: " << name;
		print << "\nEdad Conductor: " << age;
		return (print.str());
	}

	string drive(){
		ostringstream print;
		print << endl << name << " esta a cargo del vehiculo\n";
		return print.str();
	}



	string getName() { return string(name); }
	short getAge() { return age; }


private:
	char name[50];
	short age;

};