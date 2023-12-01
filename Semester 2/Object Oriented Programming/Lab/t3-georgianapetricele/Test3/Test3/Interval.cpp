#include "Interval.h"


#include <sstream>

Interval::Interval()
{ 
	this->start_time = 0;
	this->end_time = 0;
	this->temperature = 0;
	this->precipitations = 0;
	this->description = "";
}

Interval::Interval(int start, int end, int temperature, int precipitations, string description)
{
	this->start_time = start;
	this->end_time = end;
	this->temperature = temperature;
	this->precipitations = precipitations;
	this->description = description;
}

Interval::~Interval()
{
}

string Interval::toString()
{
	return to_string(this->start_time) + " ; " + to_string(this->end_time) + " ; " + to_string(this->temperature) + ";  " + to_string(this->precipitations) + " ; " + this->description;
}

vector<string> tokenize(string given_string, char delimiter)
{
	vector<string> result;
	stringstream string_stream(given_string);
	string token;
	while (getline(string_stream, token, delimiter))
		result.push_back(token);
	return result;
}

istream& operator>>(istream& input_stream, Interval& interval)
{
	string line;
	getline(input_stream, line);
	vector<string> tokens = tokenize(line, ';');
	if (tokens.size() != 5)
		return input_stream;
	interval.start_time = stoi(tokens[0]);
	interval.end_time = stoi(tokens[1]);
	interval.temperature = stoi(tokens[2]);
	interval.precipitations = stoi(tokens[3]);
	interval.description = tokens[4];
	return input_stream;
}