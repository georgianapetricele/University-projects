#pragma once
#include <string>

using namespace std;


class Appliance
{
protected:
	string id;
	double weight;

public:
	virtual double consumedElectricity();
	virtual string toString();
	void set_id(string id);
};

class Refrigerator: public Appliance
{
private:
	string electricity_class;
	bool has_freezer;
public:
	
	Refrigerator(string id, double weight, string electricity_class, bool has_freezer);
	string toString() override;
	double consumedElectricity() override;
};

class DishWasher : public Appliance
{
private:
	double length_cycle,electricity_per_hour;
public:
	DishWasher(string id, double weight, double electricity_per_hour, double length_cycle);
	string toString() override;
	double consumedElectricity() override;
};