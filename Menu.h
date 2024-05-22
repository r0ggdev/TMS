#pragma once

#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <windows.h>
#include <vector>
#include <functional>
#include <conio.h>

#define _size_ 25

enum Direction {
    UP = 72, DOWN = 80, LEFT = 75, RIGHT = 77, INTRO = 13
};

class BaseMenu {
public:

    BaseMenu(float _x, float _y, short _num_options, char _symbol_left = 62, char _symbol_right = 0, short _txt_color = 0, short _bg_color = 1) {
        x = _x;
        y = _y;

        txt_color = _txt_color;
        bg_color = _bg_color;

        num_options = _num_options;
        symbol_left = _symbol_left;
        symbol_right = _symbol_right;

        selected_option = 0;
        accumulated_length = 0;
    }
    ~BaseMenu() {}

    virtual void addOptions(const char* _options[], std::vector<std::function<void()>> _functions) {
        for (int i = 0; i < num_options; i++) {
            options[i] = _options[i];
            option_functions[i] = _functions[i];
        }
    }

    virtual void showMenu() {
        colorReset();
        showOptions();
        handleInput();
    }

private:

    inline void colorReset() {
        WORD attributes = (static_cast<WORD>(0) << 4) | static_cast<WORD>(7);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), attributes);
    }

    inline void setColorTxtBgColor() {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), txt_color);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), bg_color << 4);

        WORD attributes = (static_cast<WORD>(bg_color) << 4) | static_cast<WORD>(txt_color);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), attributes);
    }

    inline void position(float _x, float _y) {
        COORD coord;
        coord.X = static_cast<FLOAT>(_x);
        coord.Y = static_cast<FLOAT>(_y);
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    }

protected:

    virtual void select(int _x, int _y, const char* _text, int _selected) {
        setColorTxtBgColor();
        if (_selected == selected_option) {
            position(_x - 2, _y);
            std::cout << " " << symbol_left << " " << _text << " " << symbol_right << " " << std::endl;
        }
        else {
            colorReset();
            position(_x - 2, _y);
            std::cout << "   " << _text << "   " << std::endl;
        }
        colorReset();
    }

    virtual void showOptions() {
        for (int i = 0; i < num_options; i++) {
            select(x, y + i, options[i], i);
        }
    }

    virtual void handleInput() = 0;

    void executeSelectedOption() {
        if (option_functions[selected_option]) {
            option_functions[selected_option]();
        }
    }


    float x, y;
    short num_options;
    int selected_option;
    char symbol_left, symbol_right;
    const char* options[_size_];
    int options_position[_size_];
    int accumulated_length;
    short bg_color, txt_color;

    std::function<void()> option_functions[_size_];

};

namespace Menu {

    // menu vertical
    namespace UpDown {
        // Muestra varias opciones a la vez
        class AllOptions : public BaseMenu {
        public:
            using BaseMenu::BaseMenu;

        protected:
            void handleInput() override {
                char _input = _getch();
                switch (_input) {
                case UP:
                    selected_option--;
                    if (selected_option < 0) { selected_option = num_options - 1; }
                    break;

                case DOWN:
                    selected_option++;
                    if (selected_option >= num_options) { selected_option = 0; }
                    break;

                case INTRO:
                    executeSelectedOption();
                    break;
                }
            }
        };

        // Muestra una opcion a la vez
        class SingleOption : public BaseMenu {
        public:
            using BaseMenu::BaseMenu;

            void showOptions() override {
                select(x, y, options[selected_option], selected_option);
            }
        protected:
            void handleInput() override {
                char _input = _getch();
                switch (_input) {
                case UP:
                    selected_option--;
                    if (selected_option < 0) { selected_option = num_options - 1; }
                    break;

                case DOWN:
                    selected_option++;
                    if (selected_option >= num_options) { selected_option = 0; }
                    break;

                case INTRO:
                    executeSelectedOption();
                    break;
                }
            }
        };
    }

    // menu horizontal
    namespace RightLeft {

        // Muestra varias opciones a la vez
        class AllOptions : public BaseMenu {
        public:
            using BaseMenu::BaseMenu;

            void addOptions(const char* _options[], std::vector<std::function<void()>> _functions) override {
                for (int i = 0; i < num_options; i++) {
                    options[i] = _options[i];
                    option_functions[i] = _functions[i];
                    options_position[i] = x + accumulated_length;
                    accumulated_length += strlen(options[i]) + 5;
                }
            }
        protected:
            void showOptions() override {
                for (int i = 0; i < num_options; i++) {
                    select(options_position[i], y, options[i], i);
                }
            }

            void handleInput() override {
                char _input = _getch();
                switch (_input) {
                case RIGHT:
                    selected_option++;
                    if (selected_option >= num_options) { selected_option = 0; }
                    break;

                case LEFT:
                    selected_option--;
                    if (selected_option < 0) { selected_option = num_options - 1; }
                    break;

                case INTRO:
                    executeSelectedOption();
                    break;
                }
            }
        };

        // Muestra una opcion a la vez
        class SingleOption :public BaseMenu {
        public:
            using BaseMenu::BaseMenu;

            void addOptions(const char* _options[], std::vector<std::function<void()>> _functions) override {
                for (int i = 0; i < num_options; i++) {
                    options[i] = _options[i];
                    option_functions[i] = _functions[i];
                    options_position[i] = x + accumulated_length;
                    accumulated_length += strlen(options[i]) + 5;
                }
            }
        protected:
            void showOptions() override {
                select(x, y, options[selected_option], selected_option);
            }

            void handleInput() override {
                char _input = _getch();
                switch (_input) {
                case RIGHT:
                    selected_option++;
                    if (selected_option >= num_options) { selected_option = 0; }
                    break;

                case LEFT:
                    selected_option--;
                    if (selected_option < 0) { selected_option = num_options - 1; }
                    break;

                case INTRO:
                    executeSelectedOption();
                    break;
                }
            }
        };
    }
}

#endif // !MENU_H