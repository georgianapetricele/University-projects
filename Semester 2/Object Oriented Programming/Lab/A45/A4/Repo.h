#pragma once
#include "DynamicVector.h"
#include "Domain.h"

class Repository
{
private:
	DynamicVector dynamic_array{ 10 };

public:

	Repository();

	~Repository();

	int get_size();

	int add_tutorial(const Tutorial& current_tutorial);

	int delete_tutorial(const Tutorial& auxiliary_tutorial);

	int update_tutorial(const Tutorial& current_tutorial, const Tutorial& new_tutorial);

	DynamicVector get_all_tutorials();
};