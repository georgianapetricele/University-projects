#include "Service.h"
#include <fstream>


void Service::add_appliance(Appliance* a)
{
	this->appliances.push_back(a);
}


vector<Appliance*> Service::get_all()
{
	return this->appliances;
}

void Service::save_to_file(string file_name)
{
	ofstream f(file_name);
	for (auto it : this->appliances)
		f << it->toString() << "\n";
	f.close();
}