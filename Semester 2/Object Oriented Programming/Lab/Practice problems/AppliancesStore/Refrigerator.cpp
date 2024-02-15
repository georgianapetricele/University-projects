#include "Appliance.h"

Refrigerator::Refrigerator(string id,double weight, string electricity_class, bool has_freezer)
{
	this->id = id;
	this->weight = weight;
	this->electricity_class = electricity_class;
	this->has_freezer = has_freezer;
}

string Refrigerator::toString()
{
	string result = "";
	result += this->id + " | " + to_string(this->weight) + " | "+ this->electricity_class + " | ";
	if (has_freezer == true)
		result += "true";
	else
		result += "false";
	return result;
}

double Refrigerator::consumedElectricity()
{
	double x;
	if (this->electricity_class == "A")
		x = 3;
	else
		if (this->electricity_class == "A+")
			x = 2.5;
	return 30 * x;

}
