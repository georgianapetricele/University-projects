#include "Service.h"
#include <fstream>
#include <algorithm>

Service::Service()
{
}

Service::~Service()
{
}

bool compare(Interval interval1, Interval interval2)
{
	if(interval1.get_start() == interval2.get_start())
		return interval1.get_end() < interval2.get_end();
	return interval1.get_start() < interval2.get_start();
}

vector<Interval> Service::get_all_intervals()
{
	vector<Interval> intervals =  this->intervals;
	sort(intervals.begin(),intervals.end(),compare);
	return intervals;
}

void Service::read_from_file()
{
	ifstream file("intervals.txt");
	Interval interval;
	while(file>>interval)
		intervals.push_back(interval);
	file.close();
}

string Service::compute_total_hours(int start, string description)
{
	vector<Interval> result;
	int number_hours = 0;
	for (auto& interval : this->intervals)
	{
		if(interval.get_start() >= start && interval.get_description() == description)
			number_hours += interval.get_end() - interval.get_start();
		else
			if(interval.get_start() < start && interval.get_end() > start && interval.get_description() == description)
				number_hours += interval.get_end() - start;
	}
	if(number_hours == 0)
		return "No intevals with property!";
	else
		return "There are " +to_string(number_hours) + " hours from " + to_string(start) + " of " + description + " weather";
}