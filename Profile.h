#include"Headers.h"
#include "Client.h"

class Profile {
public:
	Profile(User*& _users) { users = _users; }
	~Profile() {}

	void profile(string _user){
		int x = 54 ,y = 10;

		Client client = users->getClient(_user);
		boxAscii();
		color::setTextColor(color::CYAN);
		drawProfile();
		color::reset();
		data(x, y-3, color::BLACK, color::BG_WHITE, "    Perfil de " + client.getUser()+"    ");

		data(x, y++, color::LIGHT_WHITE, color::BG_BLACK, "Nombre: " + client.data->getName());
		data(x, y++, color::LIGHT_WHITE, color::BG_BLACK, "Apellido: " + client.data->getLastName());
		data(x, y++, color::LIGHT_WHITE, color::BG_BLACK, "DNI: " + to_string(client.data->getDNI()));
		data(x, y++, color::LIGHT_WHITE, color::BG_BLACK, "Edad: " + to_string(client.data->getAge()));
		data(x, y++, color::LIGHT_WHITE, color::BG_BLACK, "Telefono: " + to_string(client.data->getPhone()));
		y++;
		data(x, y++, color::LIGHT_WHITE, color::BG_BLACK, "Empresa: " + client.company->getNameCompany());
		data(x, y++, color::LIGHT_WHITE, color::BG_BLACK, "RUC: " + to_string(client.company->getRuc()));
	}

private:
	void data(int _x, int _y, color::TextColor _txt_c, color::BackgroundColor _bg_c,string _text) {
		position(_x,_y);
		color::setTxtBgColor(_txt_c, _bg_c);
		cout << " " << _text << " ";
		color::reset();
	}
	User* users;
};