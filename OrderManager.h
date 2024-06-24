#include"Headers.h"
#include"Order.h"


class OrderManager {
public:
	OrderManager(){}
	~OrderManager(){}

	void addOrder(size_t _size, string _user) {
		for (int i = 0; i < _size; i++) {
			order.push_back(Order(i + 1));
			order.at(i).save(_user);
		}
	}

	//void loadOrder(size_t _size, string _user) {
	//	for (size_t i = 0; i < _size; i++) {
	//		order.at(i).load(_user, _nameSender);
	//	}
	//}

	void printTable(size_t _size, string _user) {
		size_t max_id_len = 2;
		size_t max_reciver_len = 8;
		size_t max_address_len = 9;
		size_t max_weight_len = 4;
		size_t max_sender_len = 9;

		for (auto& ord : order) {
			max_id_len = max(max_id_len, ord.getId().length());
			max_reciver_len = max(max_reciver_len, ord.getReciver().length());
			max_address_len = max(max_address_len, ord.getAddress().length());
			max_weight_len = max(max_weight_len, to_string(ord.getWeight()).length() + 3);
			max_sender_len = max(max_sender_len, ord.getSender().length());
		}

		size_t margin = 2;

		color::setTxtBgColor(color::BLACK, color::BG_YELLOW);

		position(5, 3);
		cout << right << setw(max_id_len + margin) << "ID"
			<< setw(max_reciver_len + margin) << "Receptor"
			<< setw(max_address_len + margin) << "Direccion"
			<< setw(max_weight_len + margin) << "Peso"
			<< setw(max_sender_len + margin) << "Remitente" << setw(5) << " ";
		color::reset();

		for (size_t i = 0; i < _size; i++) {
			position(5, i + 5);
			cout << right << setw(max_id_len + margin) << order.at(i).getId()
				<< setw(max_reciver_len + margin) << order.at(i).getReciver()
				<< setw(max_address_len + margin) << order.at(i).getAddress()
				<< setw(max_weight_len + margin) << order.at(i).getWeight() << " kg"
				<< setw(max_sender_len + margin) << order.at(i).getSender();
		}
	}


private:
	vector<Order> order;
};