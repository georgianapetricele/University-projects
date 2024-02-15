#include "Service.h"
#include <fstream>
#include <algorithm>

using namespace std;

Service::Service()
{
}

void Service::add_departament(HospitalDepartament* departament)
{
	this->departaments.push_back(departament);
}

vector<HospitalDepartament*> Service::get_all()
{
	return this->departaments;
}

vector<HospitalDepartament*> Service::get_efficient()
{
	vector<HospitalDepartament*> efficient_departaments;
	for (auto departament : this->departaments)
		if (departament->is_efficient())
			efficient_departaments.push_back(departament);
	return efficient_departaments;
}

void Service::save_to_file(string file_name)
{
	ofstream file(file_name);
	vector<HospitalDepartament*> departaments = this->get_all();
	sort(departaments.begin(), departaments.end(), [](HospitalDepartament* departament1, HospitalDepartament* departament2) {return departament1->get_name() < departament2->get_name(); });
	for (auto departament : departaments)
		file << departament->toString() << endl;
	file.close();
}