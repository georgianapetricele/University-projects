#include "Building.h"


Block::Block()
{
	this->address = "";
	this->constructionYear = 0;
	this->total_apartments = 0;
	this->occupied_apartments = 0;
}

Block::Block(string address, int constructionYear, int total_apartments, int occupied_apartments)
{
	this->address = address;
	this->constructionYear = constructionYear;
	this->total_apartments = total_apartments;
	this->occupied_apartments = occupied_apartments;
}

Block::~Block()
{
}

string Block::toString()
{
	return this->address + " " + to_string(this->constructionYear) + " " + to_string(this->total_apartments) + " " + to_string(this->occupied_apartments);
}

bool Block::must_be_restored()
{
	if(this->constructionYear<1980 && (this->total_apartments - this->occupied_apartments) * 100 / this->total_apartments > 80)
	return true;
	return false;
}

bool Block::can_be_demolished()
{
	if (this->occupied_apartments < 0.5*this->total_apartments)
		return true;
	return false;
}