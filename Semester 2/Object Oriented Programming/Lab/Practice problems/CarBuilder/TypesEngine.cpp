#include "TypesEngine.h"


using namespace std;


Turbo::Turbo(string fuel_type, double base_price) : Engine(fuel_type, base_price)
{
}

string Turbo::toString()
{
	return " | Fuel: " + this->fuel_type + " | Baseprice: " + to_string(this->base_price);
}

double Turbo::get_price()
{
	if(fuel_type == "gasoline")
		return this->base_price + 0.01*100;
	else if(fuel_type == "diesel")
		return this->base_price + 0*01*150;

}

Electric::Electric(string fuel_type, double base_price, int autonomy) : Engine(fuel_type, base_price)
{
	this->autonomy = autonomy;
}
string Electric::toString()
{
	return " | Fuel: " + this->fuel_type + " | Baseprice: " + to_string(this->base_price) + " | Autonomy: " + to_string(this->autonomy);
}

double Electric::get_price()
{
	return this->base_price + 0.01*this->autonomy;
}