#pragma once
#include <string>
#include <vector>


using namespace std;

class Interval
{
private:
	string start_hour, end_hour, temperature, precipitation_probability, description;

public:
	Interval();
	Interval(string start_hour, string end_hour, string temperature, string precipitation_probability, string description);
	~Interval();
	string get_description()
	{
		return this->description;
	}
	string get_precipitation_probability() { return this->precipitation_probability; }
	bool operator==(const Interval& interval);
	string get_start_hour() { return this->start_hour; }
	string get_end_hour() { return this->end_hour; }
	friend istream & operator>>(istream & is, Interval & interval);
	string convert_to_string();
};

