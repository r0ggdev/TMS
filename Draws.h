#pragma once

#include<iostream>
using namespace std;

void position(int _x, int _y) {
    COORD coord;
    coord.X = _x;
    coord.Y = _y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void boxAscii(int x = 7, int y = 1, int _width = 103, int _height = 25) {

    const char topLeftCorner = 201;
    const char topRightCorner = 187;
    const char bottomLeftCorner = 200;
    const char bottomRightCorner = 188;
    const char horizontalLine = 205;
    const char verticalLine = 186;

    auto printLine = [x, y](int offsetX, int offsetY, char start, char middle, char end, int _width) {
        position(x + offsetX, y + offsetY);
        cout << start;
        for (int i = 0; i < _width; i++) {
            cout << middle;
        }
        cout << end;
        };

    printLine(0, 0, topLeftCorner, horizontalLine, topRightCorner, _width);

    for (int i = 1; i <= _height; i++) {
        printLine(0, i, verticalLine, ' ', verticalLine, _width);
    }

    printLine(0, _height + 1, bottomLeftCorner, horizontalLine, bottomRightCorner, _width);
}

void boxInterface(int x = 7, int y = 1, int _width = 103, int _height = 25) {
    const char horizontalLine = 205;
    const char intersectionLeft = 204;
    const char intersectionRigth = 185;

    boxAscii(x, y, _width, _height);

    position(x, _height);
    cout << intersectionLeft;

    for (int i = x + 1; i < _width + (x + 1); i++) {
        position(i, _height);
        cout << horizontalLine;
    }

    cout << intersectionRigth;
}

void recordsTitle() {
	position(0, 1);
	cout << R"(

		                 ____            _     _                      
		                |  _ \ ___  __ _(_)___| |_ _ __ ___  ___  ___ 
		                | |_) / _ \/ _` | / __| __| '__/ _ \/ __|/ _ \
		                |  _ <  __/ (_| | \__ \ |_| | |  __/\__ \  __/
		                |_| \_\___|\__, |_|___/\__|_|  \___||___/\___|
		                           |___/                              
	
				                   escriba * para salir
)";
}

void drawMenu() {
	position(0, 3);
	cout << R"(
		                                   ________  ________
		                                  /_  __/  |/  / ___/
		                                   / / / /|_/ /\__ \ 
		                                  / / / /  / /___/ / 
		                                 /_/ /_/  /_//____/  
)";
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

void drawLogin() {
    position(0, 1);
    cout << R"(
                     ___       _      _         ____            _             
                    |_ _|_ __ (_) ___(_) __ _  / ___|  ___  ___(_) ___  _ __  
                     | || '_ \| |/ __| |/ _` | \___ \ / _ \/ __| |/ _ \| '_ \ 
                     | || | | | | (__| | (_| |  ___) |  __/\__ \ | (_) | | | |
                    |___|_| |_|_|\___|_|\__,_| |____/ \___||___/_|\___/|_| |_|
                                    logeese con * para salir 
)";
}