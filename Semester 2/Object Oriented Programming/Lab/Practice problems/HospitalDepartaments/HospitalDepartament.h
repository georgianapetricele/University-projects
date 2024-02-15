#pragma once
#include <string>
using namespace std;

class HospitalDepartament
{
protected:
	string name;
	int numberOfDoctors;
public:
	HospitalDepartament();
	HospitalDepartament(string name, int numberOfDoctors);
	virtual bool is_efficient();
	virtual string toString();
	string get_name()
	{
		return this->name;
	}
};

class Surgery : public HospitalDepartament
{
private:
	int numberOfPatients;
public:
	Surgery();
Surgery(string name, int numberOfDoctors, int numberOfPatients);
	bool is_efficient() override;
	string toString() override;
};


class NeonatalUnit : public HospitalDepartament
{
private:
	int numberOfMothers;
	int numberOfBabies;
	double averageGrade;
public:
	NeonatalUnit();
	NeonatalUnit(string name, int numberOfDoctors, int numberOfMothers, int numberOfBabies, double averageGrade);
	bool is_efficient() override;
	string toString() override;
};