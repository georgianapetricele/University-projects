#include "Service.h"
#include <algorithm>
#include <fstream>
#include <string>

using namespace std;

Service::Service()
{
}

Service::~Service()
{
}

vector<Disorder> Service::get_medical_disorders()
{
	vector<Disorder> disorders = this->disorders;
	sort(disorders.begin(),disorders.end(), [](Disorder& d1, Disorder& d2) {return d1.get_name() < d2.get_name(); });
    return disorders;
}


void Service::read_from_file()
{
	ifstream file("input.txt");
	Disorder disorder;
	while (file >> disorder)
	{
		this->disorders.push_back(disorder);
	}
	file.close();
}
