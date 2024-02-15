#include "Client.h"

Client::Client(string name, double income)
{
	this->name = name;
	this->income = income;
}

double Client::totalIncome()
{
	return this->income;
}

string Client::toString()
{
	return this->name + " " + std::to_string(this->income);
}

bool Client::isInterested(Dwelling d)
{
	return false;
}