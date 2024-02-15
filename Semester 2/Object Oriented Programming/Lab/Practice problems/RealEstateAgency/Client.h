#pragma once
#include <string>
#include "Dweling.h"

using std::string;

class Client
{
protected:
	string name;
	double income;
public:
	Client()
	{
		this->name = "";
		this->income = 0;
	}
	Client(string name, double income);
	string get_name()
	{
		return this->name;
	}
	virtual double totalIncome();
	virtual string toString();
	virtual bool isInterested(Dwelling d);
};
