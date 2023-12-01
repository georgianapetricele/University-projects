#include "Repo.h"
#include "Domain.h"
#include <vector>
#include <fstream>
#include "Exceptions.h"

using namespace std;


Repository::Repository()
{
}

Repository::Repository(string file_name)
{
	this->file_name = file_name;
}

Repository::~Repository()
{
}

vector<Tutorial> Repository::get_dynamic_array()
{
	return this->dynamic_array;
}

Tutorial Repository::get_tutorial_on_position(int position)
{
	return this->dynamic_array[position];
}

int Repository::get_tutorial_position(const Tutorial& tutorial)
{
	auto iterator = find(this->dynamic_array.begin(), this->dynamic_array.end(), tutorial);
	if (iterator != dynamic_array.end())
		return iterator - dynamic_array.begin();
}

int Repository::get_size()
{
	return this->dynamic_array.size();
}

int Repository::add_tutorial(const Tutorial& current_tutorial)
{
	auto iterator = find(this->dynamic_array.begin(), this->dynamic_array.end(), current_tutorial);
	if (iterator != this->dynamic_array.end())
	{
		throw DuplicateException("\nError! The tutorial you want to add is already in the list.");
		return -1;
	}
	else
	{
		int position_element_in_array = iterator - this->dynamic_array.begin();
		this->dynamic_array.push_back(current_tutorial);
		this->write_to_file();
		return 1;
	}
}

int Repository::update_tutorial(const Tutorial& current_tutorial, const Tutorial& new_tutorial)
{
	auto iterator = find(this->dynamic_array.begin(), this->dynamic_array.end(), current_tutorial);
	if (iterator == this->dynamic_array.end())
	{
		throw UnexistentTutorialException("\nError! The tutorial you want to update doesn't exist.");
		return -1;
	}
	else
	{
		int position_element_in_array = iterator - this->dynamic_array.begin();
		this->dynamic_array[position_element_in_array] = new_tutorial;
		this->write_to_file();
		return 1;
	}
}


int Repository::delete_tutorial(const Tutorial& auxiliary_tutorial)
{
	auto iterator = find(this->dynamic_array.begin(), this->dynamic_array.end(), auxiliary_tutorial);
	if (iterator != this->dynamic_array.end())
	{
		int position_element_in_array = iterator - this->dynamic_array.begin();
		this->dynamic_array.erase(dynamic_array.begin() + position_element_in_array);
		this->write_to_file();
		return 1;
	}
	else
	{
		throw UnexistentTutorialException("\nError! The tutorial you want to delete doesn't exist.");
		return -1;
	}
}

vector<Tutorial> Repository::get_all_tutorials()
{
	return this->dynamic_array;
}

void Repository::read_from_file()
{
	ifstream fin(this->file_name);
	this->dynamic_array.clear();
	if (!fin.is_open())
		throw FileException("\nError! The file could not be opened.");
	else
	{

		vector<Tutorial> read_tutorials;
		Tutorial tutorial;
		while (fin >> tutorial)
		{
			//if (find(this->dynamic_array.begin(), this->dynamic_array.end(), tutorial) == this->dynamic_array.end())
				this->dynamic_array.push_back(tutorial);
		}
		fin.close();
	}
}

int Repository::find_tutorial(Tutorial given_tutorial)
{
	auto iterator = find(this->dynamic_array.begin(), this->dynamic_array.end(), given_tutorial);
	if (iterator == this->dynamic_array.end())
		return 0;
	else
	{
		int position_element_in_array = iterator - this->dynamic_array.begin();
		return 1;
	}
}

void Repository::write_to_file()
{
	ofstream fout(this->file_name);
	if (!fout.is_open())
		throw FileException("\nError! The file could not be opened!");
	for (auto tutorial : this->dynamic_array)
		fout << tutorial;
	fout.close();
}

void Repository::open_in_given_app()
{
}