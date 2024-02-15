#pragma once
#include "Client.h"

class Person: public Client
{
	public:
		Person()
		{
	}
	Person(string name, double income): Client(name, income)
	{
	}
	bool isInterested(Dwelling d) override
	{
		if (d.get_price() / 1000 <= this->income)
		{
				return true;
		}
		return false;
	}
};