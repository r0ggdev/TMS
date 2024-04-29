#pragma once
#include<iostream>
#include<conio.h>
#include"string"
using namespace std;
class CEntrega {
private:
	string tipoEntrega;
public:
	CEntrega(string tipoEntrega = " ") {
		this->tipoEntrega = tipoEntrega;
	}
	~CEntrega() {}
	void mostrar() {

		cout << "Tipo de entrega---> " << tipoEntrega << endl;

	}


};
