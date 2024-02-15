#include "HospitalDepartament.h"

Surgery::Surgery()
{
}

Surgery::Surgery(string name, int numberOfDoctors, int numberOfPatients) : HospitalDepartament(name, numberOfDoctors)
{
	this->numberOfPatients = numberOfPatients;
}

bool Surgery::is_efficient()
{
	return this->numberOfPatients / this->numberOfDoctors >= 2;
}

string Surgery::toString()
{
	return "Surgery " + this->name + " " + to_string(this->numberOfDoctors) + " " + to_string(this->numberOfPatients);
}