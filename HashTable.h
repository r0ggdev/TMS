#pragma once
#include "Lists.h"

template<typename TypeKey, typename TypeValue>
class HashTable {
public:

    HashTable(int _table_size = 128) {
        table_size = _table_size;
        quantity_elements = 0;

        table = new LinkedList<Entity*>[table_size];
    }

    ~HashTable() {
        for (int i = 0; i < table_size; ++i) {
            while (!table[i].isEmpty()) {
                table[i].eraseInitial();
            }
        }
        quantity_elements = 0;
        delete[] table;
    }

    struct Entity {
        Entity(TypeKey& _key, TypeValue& _value) : key(_key), value(_value) {}

        TypeKey getKey() { return key; }
        TypeValue getValue() { return value; }

    private:
        TypeKey key;
        TypeValue value;
    };

    int functionHash(TypeKey& _key) {
        int hash = 0;

        for (int i = 0; i < sizeof(_key); ++i) {
            hash += reinterpret_cast<const unsigned char*>(&_key)[i];
        }
        return hash % table_size;
    }

    void insert(TypeKey _key, TypeValue _value) {
        int hash = functionHash(_key);

        int pos = table[hash].findPosition([&](Entity* entity) { return entity->getKey() == _key; });
        if (pos != -1) {
            table[hash].modifyPosition(new Entity(_key, _value), pos);
            return;
        }

        table[hash].addEnd(new Entity(_key, _value));
        quantity_elements++;
    }

    bool search(TypeKey _key, TypeValue& _value) {
        int hash = functionHash(_key);
        Entity* result = table[hash].search([&](Entity* entity) { return entity->getKey() == _key; });

        if (result != nullptr) {
            _value = result->getValue();
            return true;
        }
        return false;
    }

    void remove(TypeKey _key) {
        int hash = functionHash(_key);
        int pos = table[hash].findPosition([&](Entity* entity) { return entity->getKey() == _key; });
        if (pos != -1) quantity_elements--;
    }

    int getSize() { return table_size; }
    int getSizeNow() { return quantity_elements; }


private:
    LinkedList<Entity*>* table;
    int quantity_elements;
    int table_size;
};