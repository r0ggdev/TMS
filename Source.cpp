#include"Controller.h"


int main() {
	//Companie* company = new Companie("Aliexpress", 982315151);
	
	Driver driver("mario", 19);
	Driver driver1("Jose", 19);
	Driver driver2("Pepe", 19);

	//Client* client1 = new Client("Jorge", "Ayuda", 72350880, 19, 932447233, "Aliexpress", 987654321, "roger", "nuevo");

	Controller* controller = new Controller();

	controller->menu();

	//cout << client1->showAdminInfo();

	//client1->companie->addVehicle(driver,9876728);
	//client1->companie->showCompanie();
	//client1->companie->showVehicles();
	//client1->companie->searchVehicle();


	//company->addVehicle(driver,1234);
	//company->addVehicle(driver1, 214);
	//company->addVehicle(driver2, 152);
	//company->showVehicles();
	//company->searchVehicle();

	_getch();
	return 0;
}