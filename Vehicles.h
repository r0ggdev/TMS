#pragma once
#include"Driver.h"

class Vehicles {

public:
	Vehicles(Driver _driver, int _licenseplate) {
		this->driver = _driver;
		this->licenseplate = _licenseplate;
	}

	~Vehicles(){}

	void start() {
		cout << "El vehiculo esta a punto de partir\n\n";
		
		//logica de envio

		cout << driver.drive();
	}

	string getVehicleInfo() {
		ostringstream print;
		print << "\n\n\tInformacion del vehiculo";
		print << "\n\nMatricula del carro: "<< licenseplate;
		print << "\n\n";
		return driver.getDriver() + print.str();
	}

	int getLicensePlate() { return licenseplate; }


private:
	int licenseplate;
	Driver driver;
};