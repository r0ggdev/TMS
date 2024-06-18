#pragma once
#include"Headers.h"

class HashTable
{
public:
	HashTable(int _table_size = 128){
		this->table_size = _table_size;
		table = new Entity * [table_size];

		for (int i = 0; i < table_size; i++) {
			table[i] = nullptr;
		}

		quantity_elements = 0;
	}

	~HashTable(){
		for (int i = 0; i < table_size; i++) {
			if (table[i] != nullptr) delete table[i];
		}
		delete[] table;
	}

	struct Entity {
		Entity(int _key, string _value) {
			this->key = _key;
			this->value = _value;
		}

		int getkey() { return key; }
		string getValue() { return value; }

	private:
		int key;
		string value;
	};

	string insert(int _key, string _value){
		int base, step, hash;

		if (quantity_elements == table_size) return;

		base = _key % table_size;
		hash = base;
		step = 0;

		while (table[hash]!=nullptr) {
			hash = (base + step) % table_size;
			step++;
		}

		table[hash] = new Entity(_key,_value);
		quantity_elements++;
	}

	int getSize() { return table_size; }
	int getSizeNow() { return quantity_elements; }

	string search(int _key){

		int step = 0;
		int i, base;

		i = base = _key % table_size;

		int iteration = 0;

		while (iteration < table_size) {
			if (table[i] == nullptr) return "";
			else if (table[i]->getkey() == _key) return table[i]->getValue();
			else {
				step++;
				i = (base + step) % table_size;
			}

			iteration++;
		}
		return "";
	}
	
private:
	Entity** table;
	int quantity_elements;
	int table_size;
};