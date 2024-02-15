#include "Service.h"
#include <fstream>


Service::Service()
{
}

Service::~Service()
{
}

void Service::addBuilding(Building* building)
{
	this->buildings.push_back(building);
}

vector<Building*> Service::get_all()
{
	return this->buildings;
}


vector<Building*> Service::get_all_to_be_restored()
{
	vector<Building*> buildings_to_be_restored;
	for (auto building : this->buildings)
	{
		if (building->must_be_restored())
			buildings_to_be_restored.push_back(building);
	}
	return buildings_to_be_restored;
}
int Service::write_to_file(string filename)
{
	ofstream file(filename);
	ofstream file_for_demolished("demolished.txt");
	if (file)
	{
		for (auto building : this->get_all_to_be_restored())
		{
			file << building->toString() << "\n";
		}
		file.close();
		for (auto building : this->get_all_to_be_demolished())
		{
			file_for_demolished << building->toString() << "\n";
		}
		return 1;
	}

	return 0;
}

vector<Building*> Service::get_all_to_be_demolished()
{
	vector<Building*> buildings_to_be_demolished;
	for (auto building : this->buildings)
	{
		if (building->must_be_restored())
			buildings_to_be_demolished.push_back(building);
	}
	return buildings_to_be_demolished;
}
