#include "Building.h"

House::House()
{
		this->address = "";
	this->constructionYear = 0;
	this->is_historical = false;
	
}

House::House(string address, int constructionYear, bool is_historical)
{
	this->address = address;
	this->constructionYear = constructionYear;
	this->is_historical = is_historical;
}

House::~House()
{
}

string House::toString()
{
	return this->address + " " + to_string(this->constructionYear) + " " + to_string(this->is_historical);
}

bool House::must_be_restored()
{
	if (this->constructionYear < 1923)
		return true;
	return false;
}

bool House::can_be_demolished()
{
	if (this->is_historical == false)
		return true;
	return false;
}