#pragma once
#include"Vehicles.h"
#include"Lists.h"

class Company
{
public:
	Company(int _ruc = 0 , string _name_comany = "") {
		this->ruc = _ruc;
		this->name = _name_comany;

		lstVehicles = *new LinkedList<Vehicles*>();
	}

	~Company(){}

	int getRuc() { return this->ruc; }
	string getNameCompany() { return this->name; }

	string showCompany() {
		ostringstream print;
		print << "\n\n\tDatos de la Empresa\n";
		print << "\n Nombre de la compañia: "<< name;
		print << "\n RUC: "<< ruc;

		return (print.str());
	}

	void addVehicles(Driver _drive, int _licenseplate) {
		lstVehicles.addInitial(new Vehicles(_drive, _licenseplate));
	}

	void showVehicles() {
		cout << "\n\n\n     ";
		color::setTxtBgColor(color::BLACK, color::BG_WHITE);
		
		cout << " Lista de vehiculos asociados ";
		color::reset();

		for (int i = 0; i < lstVehicles.listLength(); i++) {
			cout << "\n\n\n	     ";
			color::setTxtBgColor(color::BLACK, color::BG_BLUE);
			cout << " Vehiculo " << i + 1 << " ";
			color::reset();
			
			cout << lstVehicles.getPosition(i)->getVehicleInfo();
		}
	}

private:
	int ruc;
	string name;
	LinkedList<Vehicles*> lstVehicles;
};
