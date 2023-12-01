#include "Dwelling.h"


Dwelling::Dwelling()
{
}


Dwelling::~Dwelling()
{
}

Dwelling::Dwelling(double price, bool is_profitable)
{
	this->price= price;
	this->is_profitable = is_profitable;
}

string Dwelling::toString()
{
	string s = "";
	s= to_string(this->price) + " | ";
	if (is_profitable == true)
		s += "true";
	else
		s += "false";
	return s;

}

double Dwelling::get_price()
{
	return this->price;
}

bool Dwelling::get_is_profitable()
{
	return this->is_profitable;
}

