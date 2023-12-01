#pragma once
#include <string>
#include "Dwelling.h"

using namespace std;


class Client
{
protected:
	string name;
	double income;
public:
	Client();
	Client(string name, double income);
	~Client();
	virtual string toString();
	virtual bool is_interested(Dwelling dwelling) = 0;
	string get_name();
	double get_income();
};