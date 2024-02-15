#include "Service.h"
#include <fstream>
#include <algorithm>

Service::Service()
{
}

Service::~Service()
{
}

vector<Car> Service::get_cars()
{
		return this->cars;
}

int Service::add_car(string body_style, string engine_type, string fuel_type, int autonomy)
{
	if (body_style != "Sedan" && body_style != "Convertible")
		return 0;
	if (engine_type != "Turbo" && engine_type != "Electric")
		return 0;
	Car new_car = Car(body_style, engine_type, fuel_type, autonomy);

	this->cars.push_back(new_car);
	return 1;
	
}

void Service::save_to_file(string file_name)
{
	ofstream file;
	file.open(file_name);
	vector<Car> cars = this->get_cars();
	sort(cars.begin(),cars.end(), [](Car& car1, Car& car2) {return car1.compute_price() < car2.compute_price(); });
	for (auto car : cars)
		file << car.toString() << " | Price: "<<car.compute_price() << "\n";
	file.close();
}