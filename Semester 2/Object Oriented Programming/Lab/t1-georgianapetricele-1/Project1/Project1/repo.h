#pragma once

#include <vector>
#include <string>
#include "domain.h"


class Repository
{
private:
	vector<School> schools;
public:
	Repository();
	~Repository();
	void add_school(School school);
	int delete_school(School school);
	void test_delete_school();
	vector<School> get_all();
	int get_size();

};