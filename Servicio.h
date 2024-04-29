#pragma once
#include<iostream>
#include<conio.h>
#include"string"
using namespace std;
class CServicio {
private:
	string serv;
public:
	CServicio(string serv = " ") {
		this->serv = serv;

	}
	~CServicio() {}
	void mostrar() {

		cout << "Tipo de servicio---> " << serv << endl;

	}


};
