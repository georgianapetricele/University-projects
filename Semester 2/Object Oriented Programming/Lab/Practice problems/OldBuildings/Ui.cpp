#include "Ui.h"
#include <iostream>
#include <string>


Ui::Ui()
{
}

Ui::~Ui()
{
}

void Ui::add_building()
{
	cout << "Address: ";
	string address;
	getline(cin, address);
	cout << "Construction year: ";
	string construction_year;
	getline(cin, construction_year);
	string type;
	cout << "Type: ";
	getline(cin, type);
	if (type == "block")
	{
		string total_apartments;
		cout << "Total apartments: ";
		getline(cin, total_apartments);
		string occupied_apartments;
		cout << "Occupied apartments: ";
		getline(cin, occupied_apartments);
		Building* building = new Block(address, stoi(construction_year), stoi(total_apartments), stoi(occupied_apartments));
		this->service.addBuilding(building);
	}
	else
		if (type == "house")
		{
			string is_historical;
			bool is_historical_bool;
			cout << "Is historical: ";
			getline(cin, is_historical);
			if(is_historical == "true")
				is_historical_bool = true;
			else
				is_historical_bool = false;
			Building* building2 = new House(address, stoi(construction_year), is_historical_bool);
			this->service.addBuilding(building2);
		}
		else
			cout << "Invalid type\n";
}

void Ui::list_all_to_be_restored()
{
	for (auto building : this->service.get_all_to_be_restored())
	{
		cout << building->toString()<<"\n";
	}
}

void Ui::list_all_buildings()
{
	vector<Building*> buildings = this->service.get_all();
	for (auto building : buildings)
	{
		cout << building->toString()<<"\n";
	}
}

void Ui::save_to_file()
{
	string file_name;
	cout << "File name: ";
	getline(cin, file_name);
	int successfuly_write = this->service.write_to_file(file_name);
	if(successfuly_write)
		cout << "Successfuly write\n";
	else
		cout << "Error\n";
}

void Ui::run()
{

	Building *building = new Block("address", 1990, 10, 5);
	this->service.addBuilding(building);
	Building *building2 = new House("address2", 1780, true);
	this->service.addBuilding(building2);
	Building* building3 = new House("address3", 1990, false);
	this->service.addBuilding(building3);

	while (true)
	{
		cout << "1.Add\n";
		cout << "2.List all\n";
		cout<<"3. List all to be restored\n";
		cout<<"4. Save to file\n";

		string option;
		getline(cin, option);
		if (option == "1")
			add_building();
		else
			if (option == "2")
				list_all_buildings();
			else
				if (option == "4")
					save_to_file();
	}
}
