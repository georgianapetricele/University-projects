#include "Ui.h"
#include <iostream>
#include <string>
#include "Appliance.h"
#include "Service.h"

using namespace std;

void Ui::add_appliance()
{
	string id, weight, electricity_class, has_freezer,type,electricity_per_hour,length_cycle;
	bool has_freezer_bool;
	cout << "Id: ";
	getline(cin, id);
	cout << "Weight: ";
	getline(cin, weight);
	cout << "Type: ";
	getline(cin, type);
	if (type == "ref")
	{
		cout << "Electricity class: ";
		getline(cin, electricity_class);
		cout << "Has freezer: ";
		getline(cin, has_freezer);
		if (has_freezer == "true")
			has_freezer_bool = true;
		else
			has_freezer_bool = false;
		Appliance* ap1 = new Refrigerator(id, stod(weight), electricity_class, has_freezer_bool);
		this->service.add_appliance(ap1);
	}
	//else
	//{
	//	cout << "Electricity: ";
	//	getline(cin, electricity_per_hour);
	//	cout << "Length cycle: ";
	//	getline(cin, length_cycle);
	//	Appliance* ap1 = new DishWasher(id, stod(weight), stod(electricity_per_hour), stod(length_cycle));
	//	this->service.add_appliance(ap1);
	//}

}

void Ui::show_all_appliances()
{
	for(auto it: this->service.get_all())
		cout << it->toString() << "\n";
}

void Ui::show_efficient_appliances()
{
	string value;
	cout << "Value: ";
	getline(cin, value);
	for (auto it : this->service.get_all())
		if (it->consumedElectricity() < stoi(value))
			cout << it->toString() << "\n";
}

void Ui::save_to_file()
{
	string file_name;
	cout << "File name: ";
	getline(cin, file_name);
	this->service.save_to_file(file_name);
}


void Ui::start()
{

	Appliance *a1= new Refrigerator("1", 20, "A+", true);
	//Appliance *a2 = new DishWasher("2", 10, 10, 10);
	Appliance *a2 = new Refrigerator("2", 300, "A", false);
	this->service.add_appliance(a1);
	this->service.add_appliance(a2);
	while (true)
	{
		cout << "1. Add appliance\n";
		cout << "2. Show all appliances\n";
		cout << "3. Show efficient appliances\n";
		cout << "4. Save to file\n";

		string user_choice;
		getline(cin, user_choice);
		if (user_choice == "1")
			add_appliance();
		else
			if (user_choice == "2")
				show_all_appliances();
			else
				if (user_choice == "3")
					show_efficient_appliances();
				else
					if (user_choice == "4")
						save_to_file();
					else
						break;
	}
}