#include "HospitalDepartament.h"


NeonatalUnit::NeonatalUnit()
{
}

NeonatalUnit::NeonatalUnit(string name, int numberOfDoctors, int numberOfMothers, int numberOfBabies, double averageGrade) : HospitalDepartament(name, numberOfDoctors)
{
	this->numberOfMothers = numberOfMothers;
	this->numberOfBabies = numberOfBabies;
	this->averageGrade = averageGrade;
}

bool NeonatalUnit::is_efficient()
{
	return this->averageGrade > 8.5 && this->numberOfBabies>=this->numberOfMothers;
}

string NeonatalUnit::toString()
{
	return "NeonatalUnit " + this->name + " " + to_string(this->numberOfDoctors) + " " + to_string(this->numberOfMothers) + " " + to_string(this->numberOfBabies) + " " + to_string(this->averageGrade);
}