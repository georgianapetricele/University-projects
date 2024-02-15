#include "RealEstateAgency.h"
#include <fstream>

using namespace std;

//make constructor
Agency::Agency()
{

}

//add dwelling to the vector
Dwelling Agency::addDwelling(double price, bool isProfitable)
{
	Dwelling d(price, isProfitable);
	this->dwellings.push_back(d);
	return d;
}

void Agency::add_client(Client* new_client)
{
	this->clients.push_back(new_client);
}

vector<Client*> Agency::get_clients()
{
	return this->clients;
}

vector<Dwelling> Agency::get_dwellings()
{
	return this->dwellings;
}

//remove client from the vector
void Agency::removeClient(string name)
{
	for (int i = 0; i < this->clients.size(); i++)
	{
		if (this->clients[i]->get_name() == name)
		{
			this->clients.erase(this->clients.begin() + i);
		}
	}
}

void Agency::write_to_file(string file_name)
{
	ofstream file;
	file.open(file_name);
	for (auto client : this->clients)
	{
		file << client->toString() << "\n";
	}
	file.close();
}