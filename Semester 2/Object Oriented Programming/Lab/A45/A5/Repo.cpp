#include "Repo.h"
#include "Domain.h"
#include "DynamicVector.h"


Repository::Repository()
{

}

Tutorial Repository::get_tutorial_on_position(int position)
{
	return this->dynamic_array.get_element(position);
}

int Repository::get_tutorial_position(const Tutorial& tutorial)
{
	return this->dynamic_array.find(tutorial);
}

int Repository::get_size()
{
	return this->dynamic_array.get_size();
}

int Repository::add_tutorial(const Tutorial& current_tutorial)
{
	int position_element_in_array = this->dynamic_array.find(current_tutorial);
	if (position_element_in_array != -1)
		return -1;
	else
	{
		this->dynamic_array.add(current_tutorial);
		return 1;
	}

}

int Repository::update_tutorial(const Tutorial& current_tutorial, const Tutorial& new_tutorial)
{
	int position_element_in_array = this->dynamic_array.find(current_tutorial);
	if (position_element_in_array == -1)
		return -1;
	else
	{
		this->dynamic_array.update(new_tutorial,position_element_in_array);
		return 1;
	}
}

int Repository::delete_tutorial(const Tutorial& auxiliary_tutorial)
{
	int position_element_in_array = this->dynamic_array.find(auxiliary_tutorial);
	if (position_element_in_array == -1)
		return -1;
	else
	{
		this->dynamic_array.remove(position_element_in_array);
		return 1;
	}
}

DynamicVector<Tutorial> Repository::get_all_tutorials()
{
	return this->dynamic_array;
}