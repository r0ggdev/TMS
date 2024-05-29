#pragma once

#ifndef _HEADER_H
#define _HEADER_H


#define msgX 10
#define msgY 26

#define _size_ 100

#include<iostream>
#include<functional>
#include<sstream>
#include<fstream>
#include<time.h>
#include"Colors.h"
#include"MenuLibrary.h"
#include"Draws.h"

using namespace std;

string encryption(const string& name, int shift, int index = 0) {

    auto encryptChar = [](char c, int shift) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            return char((c - base + shift) % 26 + base);
        }
        else { return c; }
        
    };
    return index == name.length() ? "" : encryptChar(name[index], shift) + encryption(name, shift, index + 1);
}
string decoded(const string& name, int shift) {
    return encryption(name, -shift);
}

bool isDigit(const char input[]) {
    try {
        char* endPtr;
        strtol(input, &endPtr, 10);

        if (*endPtr != '\0') {
            color::setTxtBgColor(color::WHITE, color::BG_RED);
            position(msgX, msgY);
            throw invalid_argument("La entrada contiene caracteres no numericos.");
        }
    }
    catch (const std::exception& e) {
        position(msgX, msgY);
        cerr << "Error: " << e.what() << std::endl;
        return false;
    }
    return true;
}

void clearMsgbox() {
    position(msgX - 1, msgY);
    for (int i = 0; i < 100; i++) { cout << " "; }
}

void msgbox(string _message, color::TextColor txt_color = color::WHITE, color::BackgroundColor bg_color = color::BG_BLACK) {
    clearMsgbox();
    color::setTxtBgColor(txt_color, bg_color);
    position(msgX, msgY);
    cout << _message;
    color::reset();
}

template<typename T>
void boxInput(int _x, int _y, string _tittle, T& _input, int _width = 25, int _height = 1) {
        
    boxAscii(_x, _y, _width, _height);
    position(_x + 2, _y);
    cout << " " << _tittle << " ";

    position(_x + 2, _y + 1);
    if constexpr (is_same_v<T, string>) {
        do {
            position(_x + 2, _y + 1);
            color::setTxtBgColor(color::GREEN, color::BG_BLACK);
            getline(cin, _input);
            color::reset();

            if (_input == "") {
                msgbox("Valor vacio no valido", color::LIGHT_RED);
            }
            else {
                clearMsgbox();
            }
        } while (_input == "");

    }
    else {
        bool valid = false;
        while (!valid) {
            string inputStr;
            color::setTxtBgColor(color::GREEN, color::BG_BLACK);
            getline(cin, inputStr);
            color::reset();
            
            const char* inputCStr = inputStr.c_str();
            
            if (!isDigit(inputCStr)) {
                clearBoxInput(_x, _y);
            }
            else {
                istringstream(inputStr) >> _input;
                valid = true;
                clearMsgbox();
            }
        }
    }
}

void clearBoxInput(int _x, int _y, int _width = 25){
    color::reset();
    position(_x + 2, _y + 1);
    for (int i = 0; i < _width - 1; ++i) { cout << " "; }
    position(_x + 2, _y + 1);
}

void clearArea(int x, int y, int width, int height) {
    color::reset();
    for (int j = y; j <= y + height +1; j++) {
        position(x, j);
        for (int i = 0; i <= width + 1; i++) {
            cout << " ";
        }
    }
}

#endif