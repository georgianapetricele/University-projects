#pragma once
#include <string>

using namespace std;


class Engine
{
protected:
	string fuel_type;
	double base_price;

public:
	Engine(string fuel_type, double base_price);
	~Engine() {
	}
	virtual double get_price() = 0;
	virtual string toString() = 0;
};