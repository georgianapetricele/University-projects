#pragma once
#include <vector>
#include "Domain.h"

class Repository
{
protected:
	string file_name;
	vector <Tutorial> dynamic_array;

public:

	Repository();

	Repository(string file_name);

	~Repository();

	int get_size();

	vector <Tutorial> get_dynamic_array();

	Tutorial get_tutorial_on_position(int position);

	int get_tutorial_position(const Tutorial& tutorial);

	virtual int add_tutorial(const Tutorial& current_tutorial);

	virtual int find_tutorial(Tutorial given_tutorial);

	int delete_tutorial(const Tutorial& auxiliary_tutorial);


	int update_tutorial(const Tutorial& current_tutorial, const Tutorial& new_tutorial);

	vector <Tutorial> get_all_tutorials();

	void read_from_file();

	virtual void write_to_file();

	virtual void open_in_given_app();
};