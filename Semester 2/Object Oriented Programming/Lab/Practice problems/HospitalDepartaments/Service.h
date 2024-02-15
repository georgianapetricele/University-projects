#pragma once
#include <vector>
#include "HospitalDepartament.h"
using namespace std;

class Service
{
private:
			vector<HospitalDepartament*> departaments;
public:
	Service();
	void add_departament(HospitalDepartament* departament);
	vector<HospitalDepartament*> get_all();
	vector<HospitalDepartament*> get_efficient();
	void save_to_file(string file_name);
};