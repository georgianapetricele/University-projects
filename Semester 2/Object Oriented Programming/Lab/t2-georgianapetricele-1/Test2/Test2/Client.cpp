#include "Client.h"


Client::Client()
{
}

Client::Client(string name, double income)
{
	this->name = name;
	this->income = income;
}


Client::~Client()
{
}

string Client::toString()
{
	return this->name + " " + to_string(this->income);
}

string Client::get_name()
{
	return this->name;
}

double Client::get_income()
{
	return this->income;
}