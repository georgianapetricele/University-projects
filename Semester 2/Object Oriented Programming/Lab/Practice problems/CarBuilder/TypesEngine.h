#pragma once
#include <string>
#include "Engine.h"

using namespace std;

class Turbo : public Engine
{
public:
	Turbo();
	Turbo(string fuel_type, double base_price);
	~Turbo() {
	}
	string toString() override;
	double get_price() override;
};


class Electric : public Engine
{
private:
	int autonomy;
public:
	Electric();
	Electric(string fuel_type, double base_price, int autonomy);
	~Electric() {
	}
	string toString() override;
	double get_price() override;
};
