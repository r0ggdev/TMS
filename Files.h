#pragma once

#ifndef _FILES_H
#define _FILES_H

#include<iostream>
#include<sstream>
#include<fstream>
#include <direct.h>
using namespace std;

class Files {
public:
	Files(const string& _root_folder, string _file_extension = ".dat") {
		root_folder = _root_folder;
		createDirectory(root_folder);

		file_extension = _file_extension;
		used_indexing = false;
	}

	~Files() {}

	template<typename type, typename TypeData>
	void log(type _file_name, int _data_quantity, const TypeData _data[]) {
		setDirectory(_file_name);
		file_write.open(file_path, ios::binary);

		if (file_write.is_open()) {
			for (int i = 0; i < _data_quantity; i++) {
				file_write << _data[i] << "\n";
			}

			file_write.close();
		}
		else {
			cout << "No se pudo crear el archivo" << endl;
		}
	}

	template<typename type>
	string get(const type _file_name, int _position) {
		setDirectory(_file_name);
		file_read.open(file_path);

		if (file_read.is_open()) {
			for (int i = 0; i < _position; i++) {
				getline(file_read, line);
			}

			file_read.close();

			return line;
		}
		else {
			return "";
		}

	}

	template<typename type>
	void createSubfolder(type _sub_folder) {
		ostringstream print;
		print << root_folder << "\\" << _sub_folder;
		createDirectory(print.str());
	}

	template<typename type>
	Files& operator[](type _sub_folder) {
		used_indexing = true;

		ostringstream print;

		print << ".\\" << root_folder << "\\";
		print << _sub_folder;

		sub_folder = print.str();

		return *this;
	}

	bool subfolderExists(const string& subfolder) {
		string folderPath = root_folder + "\\" + subfolder;
		struct stat info;

		if (stat(folderPath.c_str(), &info) != 0) {
			return false;
		}
		else if (info.st_mode & S_IFDIR) {
			return true;
		}
		else {
			return false;
		}
	}

private:
	template<typename type>
	void setDirectory(type _file_name) {

		ostringstream  print;

		if (!used_indexing) {
			print << ".\\" << root_folder << "\\";
			print << _file_name;
			print << file_extension;
			file_path = (print.str());
		}
		else {
			print << sub_folder << "\\";
			print << _file_name;
			print << file_extension;
			file_path = (print.str());
		}
	}

	void createDirectory(string _folder) {
		if (mkdir(_folder.c_str()) != 0) {
			if (errno != EEXIST) {
				cout << "Error al crear el directorio: " << root_folder << endl;
			}
		}
	}

private:
	ofstream file_write;
	ifstream file_read;

	string line, root_folder, file_path, sub_folder, file_extension;
	bool used_indexing;

};

#endif // !_FILES_H