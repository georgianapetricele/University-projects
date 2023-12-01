#pragma once
#include "domain.h"
#include "repo.h"

class Service
{
private:
		Repository repo;
public:
	Service();
	~Service();
	void add_school(School school);
	int delete_school(string name, int longitude, int latitude);
	vector<School> get_all_sorted();
	vector<School> get_all();
	void test_delete_school();
	int get_size();
};
