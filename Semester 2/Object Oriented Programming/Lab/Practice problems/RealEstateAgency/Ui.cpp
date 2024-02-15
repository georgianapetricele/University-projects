#include <iostream>
#include <string>
#include <vector>
#include "Ui.h"
#include "Dweling.h"
#include "Person.h"
#include "Company.h"

using namespace std;

void Ui::remove_client()
{
	cout << "Enter client name: ";
	string name;
	getline(cin, name);
	this->agency.removeClient(name);
}

void Ui::show_clients()
{
	cout << "Clients\n";
	for(auto client : this->agency.get_clients())
		cout << client->toString() << "\n";
	cout << "Dwellings\n";
	for(auto dwelling : this->agency.get_dwellings())
		cout << "Price: " << dwelling.get_price()<<" Profitable: "<<dwelling.get_isProfitable()<<"\n";
}

void Ui::add_dwelling()
{
	cout << "Enter price: ";
	string price;
	getline(cin, price);
	cout << "Enter profitability: ";
	string profitability;
	getline(cin, profitability);
	bool isProfitable;
	if (profitability == "true")
		isProfitable = true;
	else
		isProfitable = false;
	Dwelling dwelling = this->agency.addDwelling(stod(price), isProfitable);
	cout << "Clients interested in dwelling\n";
	for (auto client : this->agency.get_clients())
	{
		if (client->isInterested(dwelling))
			cout << client->toString() << "\n";
	}
}

void Ui::save_clients()
{
	cout << "Enter file name: ";
	string file_name;
	getline(cin, file_name);
	this->agency.write_to_file(file_name);
}

void Ui::start()
{

	Client *person1=  new Person("Ion", 1000);
	Client *person2 = new Person("Vasile", 2000);
	this->agency.add_client(person1);
	this->agency.add_client(person2);
	Company *company1 = new Company("SRL", 10000, 23);
	Company *company2 = new Company("SA", 20000, 50);
	this->agency.add_client(company1);
	this->agency.add_client(company2);
	this->agency.addDwelling(1000, true);

	while (true)
	{
		cout << "1. Remove client with name\n";
		cout << "2. Show all clients\n";
		cout << "3. Add dwelling and show clients interested in it \n";
		cout << "4. Save clients to file\n";

		string user_choice;
		getline(cin, user_choice);
		if (user_choice == "1")
			remove_client();
		else
			if (user_choice == "2")
				show_clients();
			else
				if (user_choice == "3")
					add_dwelling();
				else
					if(user_choice == "4")
						save_clients();
					else
						break;
	}
}