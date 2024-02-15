#include "Appliance.h"

#include <string>

using namespace std;


string Appliance::toString()
{
	string result = "";
	result += this->id + "| " + to_string(this->weight);
	return result;
}

void Appliance::set_id(string id)
{
	this->id = id;
}

double Appliance::consumedElectricity()
{
	return 1;
}