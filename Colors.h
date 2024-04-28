#pragma once

#ifndef COLORS_H
#define COLORS_H

#include <iostream>
#include <windows.h>

namespace color {
    enum TextColor {
        BLACK = 0,
        DARK_BLUE,
        DARK_GREEN,
        SKY_BLUE,
        RED,
        DARK_PURPLE,
        MUSTARD,
        WHITE,
        GRAY,
        BLUE,
        GREEN,
        CYAN,
        LIGHT_RED,
        LIGHT_PURPLE,
        YELLOW,
        LIGHT_WHITE
    };

    enum BackgroundColor {
        BG_BLACK = 0,
        BG_DARK_BLUE,
        BG_DARK_GREEN,
        BG_SKY_BLUE,
        BG_RED,
        BG_DARK_PURPLE,
        BG_MUSTARD,
        BG_WHITE,
        BG_GRAY,
        BG_BLUE,
        BG_GREEN,
        BG_CYAN,
        BG_LIGHT_RED,
        BG_LIGHT_PURPLE,
        BG_YELLOW,
        BG_LIGHT_WHITE
    };

    inline void setTextColor(TextColor color) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
    }

    inline void setBackgroundColor(BackgroundColor color) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color << 4);
    }

    inline void setTxtBgColor(TextColor textColor, BackgroundColor bgColor) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), textColor);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), bgColor << 4);

        WORD attributes = (static_cast<WORD>(bgColor) << 4) | static_cast<WORD>(textColor);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), attributes);
    }

    inline void reset() {
        WORD attributes = (static_cast<WORD>(BG_BLACK) << 4) | static_cast<WORD>(WHITE);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), attributes);
    }

    template<typename type>
    inline void dataEntry(type _value, TextColor color) {
        setTextColor(color);
        cin >> _value;
        reset();
    }

    template<typename type>
    inline void showData(type _value, TextColor color) {
        setTextColor(color);
        cout << _value;
        reset();
    }

    void testColor() {
        for (int i = 0; i <= 255; i++) {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);
            std::printf("#define name SetConsoleTextAttribute(hConsole,", i, ");\n");
        }
    }

}

#endif