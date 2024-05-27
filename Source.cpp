#include"Controller.h"

int main() {

	system("cls");

	Controller control;

	MenuLibrary::UpDown::AllOptions main_menu(55, 20, 3, 175, 174, color::WHITE, color::BG_DARK_PURPLE);

	const char* options[]{ "LOGIN", "SIGN-IN", "EXIT" };

	vector<function<void()>> functions{
		[&control]() { Beep(1500, 100); control.option1(); },
		[&control]() { Beep(1500, 100); control.option2(); },
		[]() {exit(0); }
	};

	main_menu.addOptions(options, functions);

	boxAscii();
	drawMenu();

	while (true) {
		main_menu.showMenu();
	}

	return 0;
}