#pragma once
#ifndef LISTS_H
#define LISTS_H
#include<functional>

typedef unsigned int uint;

template <typename value, value empty = 0>
class LinkedList {
public:
    LinkedList() {
        initial = nullptr;
        listlength = 0;
    }

    ~LinkedList() {
        Node* auxiliary = initial;
        while (auxiliary != nullptr) {
            Node* temp = auxiliary;
            auxiliary = auxiliary->next;
            delete temp;
        }
    }

    struct Node {
        value element;
        Node* next;

        Node(value _element = empty, Node* _next = nullptr) : element(_element), next(_next) {}
    };

    uint listLength() { return listlength; }

    bool isEmpty() { return listlength == 0; }

    void addInitial(value _element) {
        Node* item = new Node(_element, initial);
        if (item != nullptr) {
            initial = item;
            listlength++;
        }
    }

    void addPosition(value _element, uint _position) {
        if (_position > listlength) return;
        if (_position == 0) addInitial(_element);
        else {
            Node* auxiliary = initial;
            for (uint i = 1; i < _position; i++) {
                auxiliary = auxiliary->next;
            }
            Node* item = new Node(_element, auxiliary->next);
            if (item != nullptr) {
                auxiliary->next = item;
                listlength++;
            }
        }
    }

    void addEnd(value _element) {
        addPosition(_element, listlength);
    }

    void modifyInitial(value _element) {
        if (listlength > 0) {
            initial->element = _element;
        }
    }

    void modifyPosition(value _element, uint _position) {
        if (_position < listlength) {
            Node* auxiliary = initial;
            for (uint i = 0; i < _position; i++) {
                auxiliary = auxiliary->next;
            }
            auxiliary->element = _element;
        }
    }

    void modifyEnd(value _element) { modifyPosition(_element, listlength - 1); }

    void eraseInitial() {
        if (listlength > 0) {
            Node* auxiliary = initial;
            initial = initial->next;
            delete auxiliary;
            listlength--;
        }
    }

    value getInitial() { return getPosition(0); }

    value getPosition(uint _position) {
        if (_position < listlength) {
            Node* auxiliary = initial;
            for (uint i = 0; i < _position; i++) {
                auxiliary = auxiliary->next;
            }
            return auxiliary->element;
        }
        else {
            return empty;
        }
    }

    value getEnd() {
        return getPosition(listlength - 1);
    }

    value search(value _element, function<bool(value, value)>compare){
        Node* aux = initial;
        while (aux!=nullptr) {
            if (compare(_element, initial->element)) {
                return aux->element;
            }
            aux = aux->next;
        }
        // se debe agregar una opcion de lo que ocurre si no encuentra un valor
    }

private:
    Node* initial;
    uint listlength;
};

#endif //