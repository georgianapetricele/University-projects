#include "TypesClients.h"

Person::Person()
{
}

Person::Person(string name, double income)
{
	this->name = name;
	this->income = income;
}

Person::~Person()
{
}

bool Person::is_interested(Dwelling dwelling)
{
	if (dwelling.get_price() / 1000 <= this->income)
		return true;
	return false;
}

string Person::toString()
{
	return this->name + " | " + to_string(this->income);
}

Company::Company()
{
}

Company::Company(string name, double income, double money_investements)
{
	this->name = name;
	this->income = income;
	this->money_investements = money_investements;
}

Company::~Company()
{
}

bool Company::is_interested(Dwelling dwelling)
{
	if (dwelling.get_price() / 100 <= this->income && dwelling.get_is_profitable())
		return true;
	return false;
}

string Company::toString()
{
	return this->name + " | " + to_string(this->income) + " | " + to_string(this->money_investements);
}