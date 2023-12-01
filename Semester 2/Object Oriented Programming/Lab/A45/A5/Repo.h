#pragma once
#include "DynamicVector.h"
#include "Domain.h"

class Repository
{
private:

	DynamicVector<Tutorial> dynamic_array;

public:

	Repository(); 

	int get_size();

	Tutorial get_tutorial_on_position(int position);

	int get_tutorial_position(const Tutorial& tutorial);

	int add_tutorial(const Tutorial& current_tutorial);

	int delete_tutorial(const Tutorial& auxiliary_tutorial);

	int update_tutorial(const Tutorial& current_tutorial, const Tutorial& new_tutorial);
		
	DynamicVector<Tutorial> get_all_tutorials();
};