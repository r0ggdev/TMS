#pragma once
#include"Headers.h"

class Product
{
public:
	Product(int _ID, char _name[], float _prices, int _time) {
		strcpy_s(this->name, sizeof(name), _name);

		this->ID = _ID;
		this->price = _prices;
		this->time = _time;
	}
	~Product() {}


	void setName(char _name[]) { strcpy_s(this->name, sizeof(name), _name); }
	void setID(int _ID) { this->ID = _ID; }
	void SetPrice(float _prices) { this->price = _prices; }

	string getName() { string(name); }
	int getId() const { return ID; }
	float getPrice() const { return price; }
	int getTime() const { return time; }

	string getEspecificaciones() {
		ostringstream  print;
		print << "\ID: " << ID;
		print << "\nNombre: " << name;
		print << "\nPrecio: " << price;
		print << "\nTiempo de entrega: " << time;
		return (print.str());
	}

private:
	int ID;
	char name[50];
	float price;
	int time;
};