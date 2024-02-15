#include "HospitalDepartament.h"


HospitalDepartament::HospitalDepartament()
{
}

HospitalDepartament::HospitalDepartament(string name, int numberOfDoctors)
{
	this->name = name;
	this->numberOfDoctors = numberOfDoctors;
}

bool HospitalDepartament::is_efficient()
{
	return false;
}

string HospitalDepartament::toString()
{
	return "";
}