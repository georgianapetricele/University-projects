#include "Interval.h"
#include <sstream>


Interval::Interval()
{
}

Interval::Interval(int start, int end, int temperature, int precipitations, string description)
{
	this->start = start;
	this->end = end;
	this->temperature = temperature;
	this->precipitations = precipitations;
	this->description = description;
}

int Interval::get_start()
{
	return this->start;
}

int Interval::get_end()
{
	return this->end;
}

int Interval::get_temperature()
{
	return this->temperature;
}

int Interval::get_precipitations()
{
	return this->precipitations;
}

string Interval::get_description()
{
	return this->description;
}

string Interval::toString()
{
	return to_string(this->start) + " ; " + to_string(this->end) + " ; " + to_string(this->temperature) + " ; " + to_string(this->precipitations) + " ; " + this->description;
}

vector<string> tokenize(string str, char delimiter)
{
	vector<string> result;
	stringstream ss(str);
	string token;
	while (getline(ss, token, delimiter))
		result.push_back(token);
	return result;
}

istream& operator>>(istream& is, Interval& interval)
{
	string line;
	getline(is, line);
	vector<string> tokens = tokenize(line, ';');
	if (tokens.size() != 5)
		return is;
	interval.start = stoi(tokens[0]);
	interval.end = stoi(tokens[1]);
	interval.temperature = stoi(tokens[2]);
	interval.precipitations = stoi(tokens[3]);
	interval.description = tokens[4];
	return is;
}