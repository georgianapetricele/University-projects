#pragma once
#include <iostream>
#include "domain.h"
#include "service.h"

using namespace std;

class UI
{
private:
	Service service;
	public:
	UI();
	~UI();
	void remove_school_with_given_name_and_adress();
	void run_ui();
	void show_all_schools_to_visit_after_given_date();
	void test_show_all_schools_to_visit_after_given_date();
	void show_all_schools();
};