#include "Interval.h"
#include <string>
#include <vector>
#include <sstream>



Interval::Interval()
{
}

Interval::Interval(string start_hour, string end_hour, string temperature, string precipitation_probability, string description)
{
	this->start_hour = start_hour;
	this->end_hour = end_hour;
	this->temperature = temperature;
	this->precipitation_probability = precipitation_probability;
	this->description = description;
}

Interval::~Interval()
{
}

bool Interval::operator==(const Interval& interval)
{
	return this->start_hour == interval.start_hour && this->end_hour == interval.end_hour;
}

string Interval::convert_to_string()
{
	return this->start_hour + ";" + this->end_hour + ";" + this->temperature + ";" + this->precipitation_probability + ";" + this->description;
}

vector<string> tokenize(string given_string, char delimiter)
{
	vector<string> current_parameters;
	stringstream string_stream(given_string);
	string current_token;
	while (getline(string_stream, current_token, delimiter))
		current_parameters.push_back(current_token);
	return current_parameters;
}

istream& operator>>(istream& is, Interval& interval)
{
	string line;
	getline(is, line);
	vector<string> tokens = tokenize(line, ';');
	if(tokens.size() != 5)
		return is;
	interval.start_hour = tokens[0];
	interval.end_hour = tokens[1];
	interval.temperature = tokens[2];
	interval.precipitation_probability = tokens[3];
	interval.description = tokens[4];
	return is;
}