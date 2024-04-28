#pragma once
#include"Headers.h"

void pos(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void select(const char* text, int x, int y, bool selected) {
    if (selected) {
        color::setBackgroundColor(color::BG_DARK_BLUE);
        pos(x - 3, y);
        cout << " " << (char)62 << " " << text << " " << (char)60 << " " << endl;
    }
    else {
        color::reset();
        pos(x - 3, y);
        cout << "   " << text << "   " << endl;
    }
    pos(x, y);
    cout << text << endl;
    color::reset();
}

void image() {
    cout << R"(
                                          __________________________
                                         (_________________________@)
                                         /  |  |  |  |  |  |  |  || `\
                                         |__|__|__|__|__|__|__|__||___\
                                         |===================  RF | : |`'-._
                                        _|    .-.                 | : | ,===`\
                                       '=|___/.-.\________________|_:_|_/.-.\|
                                             \'-'/                      \'-'/
                                              '-'                        '-'
)";
}

void title() {
    pos(0, 4 - 3);
    cout << R"(
                                                  ________  ________
                                                 /_  __/  |/  / ___/
                                                  / / / /|_/ /\__ \ 
                                                 / / / /  / /___/ / 
                                                /_/ /_/  /_//____/  
)" << endl;

    image();
}
