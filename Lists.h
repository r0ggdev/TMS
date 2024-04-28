#pragma once
#ifndef LISTS_H
#define LISTS_H

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

    uint listLength() {
        return listlength;
    }

    bool isEmpty() {
        return listlength == 0;
    }

    void addInitial(value element) {
        Node* item = new Node(element, initial);
        if (item != nullptr) {
            initial = item;
            listlength++;
        }
    }

    void addPosition(value element, uint position) {
        if (position > listlength) return;
        if (position == 0) addInitial(element);
        else {
            Node* auxiliary = initial;
            for (uint i = 1; i < position; i++) {
                auxiliary = auxiliary->next;
            }
            Node* item = new Node(element, auxiliary->next);
            if (item != nullptr) {
                auxiliary->next = item;
                listlength++;
            }
        }
    }

    void addEnd(value element) {
        addPosition(element, listlength);
    }

    void modifyInitial(value element) {
        if (listlength > 0) {
            initial->element = element;
        }
    }

    void modifyPosition(value element, uint position) {
        if (position < listlength) {
            Node* auxiliary = initial;
            for (uint i = 0; i < position; i++) {
                auxiliary = auxiliary->next;
            }
            auxiliary->element = element;
        }
    }

    void modifyEnd(value element) {
        modifyPosition(element, listlength - 1);
    }

    void eraseInitial() {
        if (listlength > 0) {
            Node* auxiliary = initial;
            initial = initial->next;
            delete auxiliary;
            listlength--;
        }
    }

    value getInitial() {
        return getPosition(0);
    }

    value getPosition(uint position) {
        if (position < listlength) {
            Node* auxiliary = initial;
            for (uint i = 0; i < position; i++) {
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

private:
    Node* initial;
    uint listlength;
};

#endif // !LISTS_H