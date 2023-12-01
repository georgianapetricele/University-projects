#pragma once
#include <vector>
#include "Domain.h"

class Repository
{
private:

	vector <Tutorial> dynamic_array;

public:

	Repository();

	int get_size();
	
	vector <Tutorial> get_dynamic_array();

	Tutorial get_tutorial_on_position(int position);

	int get_tutorial_position(const Tutorial& tutorial);

	int add_tutorial(const Tutorial& current_tutorial);

	int delete_tutorial(const Tutorial& auxiliary_tutorial);

	int update_tutorial(const Tutorial& current_tutorial, const Tutorial& new_tutorial);

	int find_tutorial(const Tutorial& auxiliary_tutorial);

	vector <Tutorial> get_all_tutorials();
};