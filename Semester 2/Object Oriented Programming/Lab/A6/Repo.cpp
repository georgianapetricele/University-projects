#include "Repo.h"
#include "Domain.h"
#include <vector>

using namespace std;

Repository::Repository()
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
	auto iterator = find(this->dynamic_array.begin(), this->dynamic_array.end(),tutorial);
	if (iterator != dynamic_array.end())
		return iterator - dynamic_array.begin();}

int Repository::get_size()
{
	return this->dynamic_array.size();
}

int Repository::add_tutorial(const Tutorial& current_tutorial)
{
	auto iterator = find(this->dynamic_array.begin(), this->dynamic_array.end(), current_tutorial);
	if (iterator != this->dynamic_array.end())
		return -1;
	else
	{
		int position_element_in_array = iterator - this->dynamic_array.begin();
		this->dynamic_array.push_back(current_tutorial);
		return 1;}}

int Repository::update_tutorial(const Tutorial& current_tutorial, const Tutorial& new_tutorial)
{
	auto iterator = find(this->dynamic_array.begin(), this->dynamic_array.end(), current_tutorial);
	if (iterator == this->dynamic_array.end())
		return -1;
	else
	{
		int position_element_in_array = iterator - this->dynamic_array.begin();
		//this->dynamic_array.erase(dynamic_array.begin() + position_element_in_array - 1);
		//this->dynamic_array.push_back(new_tutorial);
		this->dynamic_array[position_element_in_array] = new_tutorial;
		return 1;}}
		

int Repository::delete_tutorial(const Tutorial& auxiliary_tutorial)
{
	auto iterator = find(this->dynamic_array.begin(), this->dynamic_array.end(),auxiliary_tutorial);
	if (iterator != this->dynamic_array.end())
	{
		int position_element_in_array = iterator - this->dynamic_array.begin();
		this->dynamic_array.erase(dynamic_array.begin() + position_element_in_array );
		return 1;}
	else
		return -1;}

vector<Tutorial> Repository::get_all_tutorials()
{
	return this->dynamic_array;
}