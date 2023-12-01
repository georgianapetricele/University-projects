#include "service.h"
#include "assert.h"
#include <algorithm>
using namespace std;

Service::Service()
{
}

Service::~Service()
{
}

int Service::delete_school(string name, int longitude, int latitude)
{
	School school_to_delete(name, longitude, latitude, 0,0,0,false);
	return this->repo.delete_school(school_to_delete);
}

void Service::add_school(School school)
{
	this->repo.add_school(school);
}

bool compare_schools(School school1, School school2)
{
	if (school1.get_name() < school2.get_name())
		return true;
	return false;
}

vector<School> Service::get_all()
{
	return this->repo.get_all();
}


vector<School> Service::get_all_sorted()
{
	vector<School> schools = this->repo.get_all();
	sort(schools.begin(),schools.end(),compare_schools);
	return schools;
}


void Service::test_delete_school()
{
	School school1 = School("school1", 10, 20, 2023, 4, 12, false);
	this->repo.add_school(school1);
	int size = this->repo.get_size();
	assert(this->delete_school("school1", 10, 20) == 1);
	assert(this->repo.get_size() == size - 1);
}