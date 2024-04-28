#pragma once
#ifndef HEADER_H
#define HEADER_H

#define ARRIBA 72
#define ABAJO 80
#define DERECHA 77
#define IZQUIERDA 75
#define enter 13
#define espacio 32
#define backspace 8

#include<string>
#include <stdlib.h>
#include<time.h>
#include<fstream>
#include <functional>
#include<iostream>
#include <sstream>
#include "Colors.h"
#include <csignal>
using namespace std;


bool isDigit(const char input[]) {
    try {
        char* endPtr;
        strtol(input, &endPtr, 10);
        if (*endPtr != '\0') {
            color::setTxtBgColor(color::WHITE,color::BG_RED);
            throw invalid_argument("La entrada contiene caracteres no numericos.");
        }
    }
    catch (const std::exception& e) {
        std::cerr << "\n Error: " << e.what() << std::endl;
        return false;
    }
    return true;
}

#endif