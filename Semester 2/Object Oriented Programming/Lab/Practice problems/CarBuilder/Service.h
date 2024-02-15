#pragma once
#include "Car.h"
#include <vector>
#include <string>

using namespace std;

class Service
{
private:
	vector<Car> cars;
public:
	Service();
	~Service();
	int add_car(string body_style, string engine_type, string fuel_type, int autonomy);
	void show_all();
	vector<Car> get_cars();
	void save_to_file(string file_name);
};
