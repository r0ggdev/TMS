#pragma once

#ifndef _FILES_H
#define _FILES_H

#include<iostream>
#include<sstream>
#include<fstream>

using namespace std;

class Files {
public:
	Files(const string& _folder, short _data_quantity) {
		folder = _folder;
		data_quantity = _data_quantity;
	}

	~Files() {}

	template<typename T, typename T2>
	void log(T _file_name, const T2 _data[]) {

		setDirectory(_file_name);

		fileWrite.open(directory, ios::binary);

		if (fileWrite.is_open()) {

			for (short i = 0; i < data_quantity; i++) {
				fileWrite << _data[i] << "\n";
			}

			fileWrite.close();
		}
		else {
			cout << "No se pudo crear el archivo" << endl;
		}
	}

	template<typename T>
	string getData(const T _file_name, short _position) {

		setDirectory(_file_name);
		fileRead.open(directory);

		if (fileRead.is_open()) {
			for (int i = 0; i < _position, i++) {
				getline(fileRead, line);
			}

			fileRead.close();

			return line;
		}
		else {
			return "";
		}

	}

private:

	void setDirectory(string _file_name) {
		ostringstream  print;
		print << ".\\" << folder << "\\";
		print << _file_name;
		print << ".dat";
		directory = (print.str());
	}

private:
	ofstream fileWrite;
	ifstream fileRead;

	string line, folder, directory;
	short data_quantity;
};

#endif // !_FILES_H