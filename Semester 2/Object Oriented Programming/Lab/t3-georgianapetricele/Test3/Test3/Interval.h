#pragma once

#include <string>
#include <vector>

#include <sstream>
using namespace std;

class Interval
{
private:
	int start_time, end_time, temperature, precipitations;
	string description;
public:
Interval();
	Interval(int start, int end, int temperature, int precipitations, string description);
	~Interval();
	string toString();
	int get_start() { return this->start_time; }
	int get_end() { return this->end_time; }
	int get_temperature() { return this->temperature; }
	int get_precipitations() { return this->precipitations; }
	string get_description() { return this->description; }
	friend istream& operator>>(istream& input_stream, Interval& interval);
};;