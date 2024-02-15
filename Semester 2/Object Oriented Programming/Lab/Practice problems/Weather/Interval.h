#pragma once
#include <string>
#include <vector>
using namespace std;

class Interval
{
	private:
		int start, end, temperature, precipitations;
		string description;
	public:
		Interval();
		Interval(int start, int end, int temperature, int precipitations, string description);
		int get_start();
		int get_end();
		int get_temperature();
		int get_precipitations();
		string get_description();
		string toString();
		friend istream& operator>>(istream& is, Interval& interval);
		~Interval(){}
};

