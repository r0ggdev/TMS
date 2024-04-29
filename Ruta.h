#pragma once
#include<iostream>
#include<conio.h>
#include"string"
using namespace std;
class CRuta {
private:
	char via[200];
public:
	CRuta(string _via = " ") {
		strcpy_s(via, sizeof(via), _via.c_str());
		*via = toupper(*via);

		this->via[sizeof(via) - 1] = '\0';

	}
	~CRuta() {}
	void mostrar() {

		cout << "Origen-Destino---> " << via << endl;

	}


};