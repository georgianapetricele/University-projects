#pragma once
#include "Appliance.h"
#include <string>

using namespace std;
//constructor

DishWasher::DishWasher(string id, double weight, double electricity_per_hour, double length_cycle)
{
	this->id = id;
	this->weight = weight;
	this->electricity_per_hour = electricity_per_hour;
	this->length_cycle = length_cycle;
}

//toString
string DishWasher::toString()
{
	string result = "";
	result += this->id + " | " + to_string(this->weight) + " | " + to_string(this->electricity_per_hour) + " | " + to_string(this->length_cycle);
	return result;
}

//consumedElectricity
double DishWasher::consumedElectricity()
{
	return this->electricity_per_hour * this->length_cycle*20;
}