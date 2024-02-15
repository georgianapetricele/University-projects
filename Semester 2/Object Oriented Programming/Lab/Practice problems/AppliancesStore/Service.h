#pragma once
#include "Appliance.h"
#include <vector>
#include <string>

using namespace std;


class Service
{
private:
	vector<Appliance*> appliances;
public:
	void add_appliance(Appliance* a);
	vector<Appliance*> get_all();
	void save_to_file(string file_name);
};