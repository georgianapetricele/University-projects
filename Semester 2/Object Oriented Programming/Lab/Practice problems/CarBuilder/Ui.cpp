#include "Ui.h"


Ui::Ui()
{
}

Ui::~Ui()
{

}

void Ui::add_car()
{
	string body_style, engine_type, fuel_type, autonomy;
	cout<< "Body style: ";
	getline(cin, body_style);
	cout << "Engine type: ";
	getline(cin, engine_type);
	cout << "Fuel type: ";
	getline(cin, fuel_type);
	if (engine_type == "Electric")
	{
		cout << "Autonomy: ";
		getline(cin, autonomy);
	}
	else
		autonomy = "0";
	int success= this->service.add_car(body_style, engine_type, fuel_type, stoi(autonomy));
	if (success == 0)
		cout << "Invalid input!\n";
	else
	{
		Car car1 = Car(body_style, engine_type, fuel_type, stoi(autonomy));
		cout<<"The price of added car is : "<<car1.compute_price() << endl;
	}
}

void Ui::show_cars()
{
	for(auto car: this->service.get_cars())
		cout<<car.toString()<<endl;
}

void Ui::start()
{
	this->service.add_car("Sedan", "Turbo", "gasoline", 100);
	this->service.add_car("Convertible", "Electric", "diesel", 200);
	while (true)
	{
		cout << "1. Add a car\n";
		cout << "2. Show all cars\n";
		cout << "3. Save to file\n";

		string option;
		getline(cin, option);

		if (option == "1")
			add_car();
		else if (option == "2")
			show_cars();
		else if(option == "3")
				this->service.save_to_file("cars.txt");
		else
			break;
	}

}