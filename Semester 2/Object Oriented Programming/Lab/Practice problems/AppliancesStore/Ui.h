#pragma once
#include "Appliance.h"
#include "Service.h"
#include <iostream>

class Ui
{
private:
	Service service;
public:
	void start();
	void add_appliance();
	void show_all_appliances();
	void show_efficient_appliances();
	void save_to_file();
};
