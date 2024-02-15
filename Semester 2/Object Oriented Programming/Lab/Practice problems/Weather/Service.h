#pragma once
#include "Interval.h"
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;
class Service
{
private:
	vector<Interval> intervals;
	public:
	Service();
	vector<Interval> get_intervals();
	void read_from_file();
	string compute_total(string description, int start_hour);
	~Service(){}
};

