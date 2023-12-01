#pragma once
#include <vector>
#include <string>
#include "Dwelling.h"
#include "Client.h"

using namespace std;

class Agency
{
private:
	vector<Dwelling> dwellings;
	vector<Client*> clients;
public:
	Agency();
	~Agency();
	vector<Client*> get_clients();
	void add_client(Client* new_client);
	void add_dwelling(double price,bool is_profitable);
	vector<Dwelling> get_dwellings();
	void save_to_file(string file_name);
	void remove_client(string name);
};