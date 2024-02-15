#pragma once
#include "Client.h"
#include <string>

using namespace std;

class Company: public Client
{
private:
	double money_from_investments;
public:
	Company()
	{
		this->money_from_investments = 0;
	}
	Company(string name, double income, double money_from_investments)
	{
		this->name = name;
		this->income = income;
		this->money_from_investments = money_from_investments;
	}
	double totalIncome() override;
	string toString() override;
	bool isInterested(Dwelling d) override;
};