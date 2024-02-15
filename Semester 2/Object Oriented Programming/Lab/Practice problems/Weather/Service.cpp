#include "Service.h"

Service::Service()
{
}

vector<Interval> Service::get_intervals()
{
	vector<Interval> intervals_sorted = this->intervals;
	sort(intervals_sorted.begin(), intervals_sorted.end(), [](Interval& i1, Interval& i2) {return i1.get_start() < i2.get_start(); });
	return intervals_sorted;
}

Wvoid Service::read_from_file()
{
	ifstream file("intervals.txt");
	Interval interval;
	while (file >> interval)
	{
		this->intervals.push_back(interval);
	}
	file.close();
}

string Service::compute_total(string description, int start_hour)
{
	int total = 0;
	for (auto& interval : this->intervals)
	{
		if (interval.get_description() == description && interval.get_start() >= start_hour)
			total += interval.get_end() - interval.get_start();
	}
	if(total == 0)
		return "No interval found";
	else
		return "Total is " + to_string(total);
}