#pragma once
#include<iostream>
#include<conio.h>
#include"string"
using namespace std;
class CComentarios {
private:
	char com[200];
public:
	CComentarios(string _com = " ") {
		strcpy_s(com, sizeof(com), _com.c_str());
		*com = toupper(*com);

		this->com[sizeof(com) - 1] = '\0';

	}
	~CComentarios() {}
	void mostrar() {

		cout << "comonvenientes--- " << endl;
		cout << "                 |" << endl;
		cout << "                 v" << endl;
		cout << com << endl;

	}


};
