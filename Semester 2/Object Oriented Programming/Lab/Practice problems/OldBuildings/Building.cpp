#include "Building.h"


Building::Building()
{
	this->address = "";
	this->constructionYear = 0;
}
Building::Building(string address, int constructionYear)
{
	this->address = address;
	this->constructionYear = constructionYear;
}

Building::~Building()
{
}

string Building::get_address()
{
	return this->address;
}

int Building::get_construction_year()
{
	return this->constructionYear;
}

string Building::toString()
{
	return this->address + " " + to_string(this->constructionYear);
}

bool Building::must_be_restored()
{
	return false;
}

bool Building::can_be_demolished()
{
	return false;
}