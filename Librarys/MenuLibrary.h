#pragma once

#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <windows.h>
#include <vector>
#include <functional>
#include <conio.h>

// define el tamaño maximo de opciones
#define _size_ 25

enum Direction {
    UP = 72, DOWN = 80, LEFT = 75, RIGHT = 77, INTRO = 13
};

class Entity {
public:

    Entity(float _x, float _y, short _num_options, char _symbol_left = 62, char _symbol_right = 0, short _txt_color = 0, short _bg_color = 1);
    ~Entity() {}

    virtual void addOptions(const char* _options[], std::vector<std::function<void()>> _functions);

    virtual void showMenu() {
        colorReset();
        showOptions();
        handleInput();
    }

private:

    void colorReset();

    void setColorTxtBgColor();
    void position(float _x, float _y);

protected:

    virtual void select(int _x, int _y, const char* _text, int _selected);

    virtual void showOptions();
    virtual void handleInput() = 0;

    void executeSelectedOption();

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

namespace MenuLibrary {

    namespace UpDown {
        class AllOptions : public Entity {
        public:
            using Entity::Entity;
        protected:
            void handleInput() override;
        };

        class SingleOption : public Entity {
        public:
            using Entity::Entity;
            void showOptions() override;

        protected:
            void handleInput() override;
        };
    }

    namespace RightLeft {

        class AllOptions : public Entity {
        public:
            using Entity::Entity;
            void addOptions(const char* _options[], std::vector<std::function<void()>> _functions) override;
        protected:
            void showOptions() override;
            void handleInput() override;
        };

        class SingleOption : public Entity {
        public:
            using Entity::Entity;
            void addOptions(const char* _options[], std::vector<std::function<void()>> _functions) override;
        protected:
            void showOptions() override;
            void handleInput() override;
        };
    }
}

#endif // !MENU_H