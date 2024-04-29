#pragma once
#include<iostream>
#include<conio.h>
#include"string"
using namespace std;
class CInconvenientes {
private:
	char inc[200];
public:
	CInconvenientes(string _inc = " ") {
		strcpy_s(inc, sizeof(inc), _inc.c_str());
		*inc = toupper(*inc);

		this->inc[sizeof(inc) - 1] = '\0';

	}
	~CInconvenientes() {}
	void mostrar() {

		cout << "Inconvenientes--- " << endl;
		cout << "                 |" << endl;
		cout << "                 v" << endl;
		cout << inc << endl;

	}


};
