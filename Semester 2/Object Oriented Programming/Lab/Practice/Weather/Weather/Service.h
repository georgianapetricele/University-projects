#pragma once
#include <vector>
#include "Interval.h"

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
};

