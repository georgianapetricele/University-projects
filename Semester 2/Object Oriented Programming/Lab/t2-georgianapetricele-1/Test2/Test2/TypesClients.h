#pragma once
#include "Client.h"
#include "Dwelling.h"


class Person : public Client
{
public:
	Person();
	Person(string name, double income);
	~Person();
	bool is_interested(Dwelling dwelling) override;
	string toString() override;
};

class Company : public Client
{
private:
	double money_investements;
public:
	Company();
	Company(string name, double income, double money_investements);
	~Company();
	string toString() override;
	bool is_interested(Dwelling dwelling) override;
};