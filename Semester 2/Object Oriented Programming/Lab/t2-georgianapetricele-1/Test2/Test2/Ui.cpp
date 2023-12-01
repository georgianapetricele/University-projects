#include "Ui.h"


Ui::Ui()
{
}

Ui::~Ui()
{
}

void Ui::remove_client()
{
	cout << "Name: ";
	string name;
	getline(cin, name);
	this->agency.remove_client(name);
}

void Ui::list_clients_and_dwellings()
{
	cout << "Clients\n";
	for(auto client: this->agency.get_clients())
		cout << client->toString() << endl;
	cout << "\nDwellings\n";
	for (auto dwelling : this->agency.get_dwellings())
		cout << dwelling.toString() << endl;
}

void Ui::add_dwelling()
{
	string price, is_profitable;
	bool is_profitable_bool;
	cout << "Price: ";
	getline(cin, price);
	cout << "Is profitable: ";
	getline(cin, is_profitable);
	if(is_profitable == "true")
		is_profitable_bool = true;
	else
		is_profitable_bool = false;
	this->agency.add_dwelling(stod(price), is_profitable_bool);

	Dwelling dwelling(stod(price), is_profitable_bool);
	cout << "\n";
	for(auto client: this->agency.get_clients())
		if (client->is_interested(dwelling))
			cout << client->toString()<<"\n";
}

void Ui::start()
{
	Client* client1 = new Person("John", 1000);
	Client* client2 = new Company("Google", 3000000,10.3);
	Client* client3 = new Person("Mary", 200);
	Client* client4 = new Company("SRL",1000000, 1000.3);
	this->agency.add_client(client1);
	this->agency.add_client(client2);
	this->agency.add_client(client3);
	this->agency.add_client(client4);
	this->agency.add_dwelling(10000, true);
	this->agency.add_dwelling(2000, false);
	while (true)
	{
		cout << "1. Remove client with name\n";
		cout << "2. List clients and dwellings\n";
		cout << "3. Add dwelling\n";
		cout << "4. Save clients to file\n";

		string option;
		getline(cin, option);

		if (option == "1")
			remove_client();
		else
			if (option == "2")
				list_clients_and_dwellings();
			else
				if (option == "3")
					add_dwelling();
				else
				if (option == "4")
					this->agency.save_to_file("output.txt");
				else
					cout<<"Invalid option\n";
	}
}