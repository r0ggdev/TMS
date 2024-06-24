#include"Headers.h"
#include"HashTable.h"
#include"Marker.h"
#include"Files.h"

class Order
{
public:
	Order(int _size) {
		srand(time(NULL));
		current_time = time(NULL);
		file_data = new Files("Data", ".txt");
		file_log = new Files("Clients");

		for (int i = 0; i < _size; i++) {
			generateOrder();
		}
	}
	~Order() {}

	string getId() { return this->id; }
	string getReciver() { return this->receiver; }
	string getAddress() { return this->address; }
	string getSender() { return this->sender; }
	string getHours() { return this->hours; }
	float getWeight() { return this->weight; }

	void save(string _user) {
		string data[] = { getId(), getReciver(), getSender(), getAddress(), to_string(getWeight()), getHours()};
		string subdirectory = encryption(_user, 4) + "\\Orders";

		if (!file_log->subfolderExists(subdirectory)) file_log->createSubfolder(subdirectory);
		(*file_log)[subdirectory].log(getId(), 6, data);
	}

	void load(string _user, string _nameSender) {
		string subdirectory = encryption(_user, 4) + "\\Orders";
		string data[6];
		
		for (size_t i = 0; i < data->length(); i++) {
			data[i] = (*file_log)[subdirectory].get(_nameSender, i + 1);
		}

		this->id = data[0];
		this->receiver = data[1];
		this->sender = data[2];
		this->address = data[3];
		this->weight = stof(data[4]);
		this->hours = data[5];
	}

private:


	void generateOrder() {
		this->sender = generateSender();
		this->id = generateID(sender);
		this->receiver = generateReciver();
		this->address = generateAddress();
		this->weight = rand() % (50 + 1);
		this->hours = getHours();
	}

	string generateID(string _sender) {
		_sender.erase(remove_if(_sender.begin(), _sender.end(), isspace), _sender.end());
		return encryption(_sender, 4);
	}

	string generateHours() {
		return ctime(&current_time);
	}

	string generateReciver() {
		return file_data->get("names_random", rand() % 40 + 1);
	}

	string generateAddress() {
		return file_data->get("address_random", rand() % 40 + 1);
	}

	string generateSender() {
		return file_data->get("names_random", rand() % 40 + 1);
	}

private:
	Files* file_data;
	Files* file_log;

	Marker comment;
	string id, receiver, address, sender, hours;
	time_t current_time;

	float weight;
};