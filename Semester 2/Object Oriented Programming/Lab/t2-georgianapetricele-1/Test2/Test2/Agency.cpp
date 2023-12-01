#include "Agency.h"
#include <fstream>


Agency::Agency()
{
}

Agency::~Agency()
{
}



void Agency::remove_client(string name)
{
	for (int index = 0; index < this->clients.size(); index++)
	{
		if (this->clients[index]->get_name() == name)
		{
			clients.erase(clients.begin() + index);
		}
	}
}

void Agency::add_client(Client* new_client)
{
	this->clients.push_back(new_client);
}

void Agency::add_dwelling(double price, bool is_profitable)
{
	Dwelling dwelling(price, is_profitable);
	this->dwellings.push_back(dwelling);
}

vector<Client*> Agency::get_clients()
{
	return this->clients;
}

vector<Dwelling> Agency::get_dwellings()
{
	return this->dwellings;
}

void Agency::save_to_file(string file_name)
{
	ofstream file;
	file.open(file_name);
	for (auto client : this->clients)
		file << client->toString() << "\n";
	file.close();
}