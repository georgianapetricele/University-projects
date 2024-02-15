#include "Company.h"

double Company::totalIncome()
{
	return this->money_from_investments + this->income;
}

string Company::toString()
{
	return this->name + " " + std::to_string(this->income) + " " + std::to_string(this->money_from_investments);
}


bool Company::isInterested(Dwelling d)
{
	if (d.get_price() / 100 <= this->income)
	{
		return true;
	}
	return false;
}