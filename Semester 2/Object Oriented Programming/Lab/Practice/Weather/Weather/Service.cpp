#include "Service.h"
#include <fstream>
#include <algorithm>

Service::Service()
{
}

Service::~Service()
{
}

bool cmp(Interval i1, Interval i2)
{
	//if (i1.get_start_hour() == i2.get_start_hour())
		//return i1.get_end_hour() < i2.get_end_hour();
	return stoi(i1.get_start_hour()) < stoi(i2.get_start_hour());
}
vector<Interval> Service::get_all_intervals()
{
	vector<Interval> intervals_sorted = this->intervals;
	sort(intervals_sorted.begin(), intervals_sorted.end(),cmp);
	return intervals_sorted;
}

void Service::read_from_file()
{
	ifstream file("input.txt");
	Interval interval;
	while (file >> interval)
	{
		this->intervals.push_back(interval);
	}
	file.close();
}
