#pragma once
#include "Dweling.h"
#include "Client.h"
#include <string>
#include <vector>
using std::vector;
using std::string;

class Agency
{

private:
	vector<Dwelling> dwellings;
	vector<Client*> clients;
public:
	Agency();
	vector<Client*> get_clients();
	vector<Dwelling> get_dwellings();
	Dwelling addDwelling(double price, bool isProfitable);
	void removeClient(string name);
	void add_client(Client* new_client);
	void write_to_file(string file_name);
	//vector<Client> get_interested_clients(Dwelling given_dwelling);
	//void write_to_file(string file_name);
};