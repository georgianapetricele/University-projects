#include "repo.h"
#include "domain.h"
#include "assert.h"

using namespace std;

Repository::Repository()
{
}

Repository::~Repository()
{
}

int Repository::delete_school(School school)
{
	auto iterator=find(this->schools.begin(), this->schools.end(), school);
	if (iterator != this->schools.end())
	{
		this->schools.erase(iterator);
		return 1;
	}
	return 0;
}

vector<School> Repository::get_all()
{
	return this->schools;
}

int Repository::get_size()
{
	return this->schools.size();
}

void Repository::add_school(School school)
{
	this->schools.push_back(school);
}

void Repository::test_delete_school()
{
	School school1 = School("school1", 10, 20, 2023, 4, 12, false);
	int size = this->get_size();
	this->delete_school(school1);
	assert(this->get_size() == size - 1);
}

