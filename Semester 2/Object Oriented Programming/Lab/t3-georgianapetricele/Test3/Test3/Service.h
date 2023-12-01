#pragma once
#include "Interval.h"
#include <vector>
#include <string>

using namespace std;
class Service
{
private:
	vector<Interval> intervals;
public:
	Service();
	~Service();
	vector<Interval> get_all_intervals();
	void read_from_file();
	string compute_total_hours(int start, string description);
};

