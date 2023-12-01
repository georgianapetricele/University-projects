#include "domain.h"

using namespace std;

School::School()
{
	this->name = "";
	this->adress.longitude = 0;
	this->adress.latitude = 0;
	this->date.day = 0;
	this->date.month = 0;
	this->date.year = 0;
	this->was_visited = false;
}

School::School(string name, int longitude, int latitude, int year, int month, int day, bool was_visited)
{
	this->name = name;
	this->adress.longitude = longitude;
	this->adress.latitude = latitude;
	this->date.day = day;
	this->date.month = month;
	this->date.year = year;
	this->was_visited = was_visited;
}

School::~School()
{
}

string School::get_name()
{
	return this->name;
}

int School::get_longitude()
{
	return this->adress.longitude;
}

int School::get_latitude()
{
	return this->adress.latitude;
}

int School::get_day()
{
	return this->date.day;
}

	
int School::get_month()
{
	return this->date.month;
}

int School::get_year()
{
	return this->date.year;
}

bool School::get_was_visited()
{
	return this->was_visited;
}

void School::set_name(string name)
{
	this->name = name;
}

void School::set_longitude(int longitude)
{
	this->adress.longitude = longitude;
}

void School::set_latitude(int latitude)
{
	this->adress.latitude = latitude;
}

void School::set_day(int day)
{
	this->date.day = day;
}

void School::set_month(int month)
{
	this->date.month = month;
}

void School::set_year(int year)
{
	this->date.year = year;
}

void School::set_was_visited(bool was_visited)
{
	this->was_visited = was_visited;
}

bool School::operator==(const School& school)
{
	return this->name == school.name && this->adress.longitude == school.adress.longitude && this->adress.latitude == school.adress.latitude;
}

string School::convert_to_string()
{
	string output_string = "";
	output_string += this->name + " | ";
	output_string += to_string(this->adress.longitude) + ",";
	output_string += to_string(this->adress.latitude) + " | ";
	output_string += to_string(this->date.year) + ".";
	output_string += to_string(this->date.month) + ".";
	output_string += to_string(this->date.day) + " | ";
	if(this->get_was_visited() == true)
		output_string += "true";
	else
		output_string += "false";
	return output_string;
}