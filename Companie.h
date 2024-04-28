#pragma once
#include"Vehicles.h"
#include"Lists.h"

class Companie
{
public:
	Companie(char _name[], int _RUC) {
		
		this->RUC = _RUC;
		strcpy_s(this->name, sizeof(name), _name);
		name[sizeof(name) - 1] = '\0';

		lstVehicle = *new LinkedList<Vehicles*>();
	}
	~Companie(){}

	string showCompanie() {
		ostringstream  print;
		print << "\nNombre de la compañia: " << name;
		print << "\nRUC: " << RUC;

		return (print.str());
	}

	int getRUC() { return RUC; }
	string getNameCompany() { return string(name); }

	void addVehicle(Driver _driver, int _licenseplate){
		lstVehicle.addInitial(new Vehicles(_driver, _licenseplate));
	}

	void showVehicles() {
		color::showData("Lista de vehiculos de la empresa", color::BLUE);
		cout << "\n\n";
		for (int i = 0; i < lstVehicle.listLength(); i++) {
			cout << lstVehicle.getPosition(i)->getVehicleInfo();
		}
	}

	void searchVehicle() {
		char input[50];
		bool verify = true;
		do
		{
			color::reset();
			cout << "\nIngrese el numero de matricula del carro que desea buscar: ";
			cin >> input;

		} while (!isDigit(input));

		int temp = atoi(input);

		for (int i = 0; i < lstVehicle.listLength(); i++) {
			if (lstVehicle.getPosition(i)->getLicensePlate() == temp) {
				color::setTextColor(color::GREEN);
				cout << "\n\tVehiculo encontrado: \n";
				cout << lstVehicle.getPosition(i)->getVehicleInfo();
				verify = true;
				break;
			}
			verify = false;
		}
		
		if (!verify){
			color::setTextColor(color::RED);
			cout << "Vehiculo no encontrado...";
		}
	}

private:
	int RUC;
	char name[50];
	LinkedList<Vehicles*> lstVehicle;
};
