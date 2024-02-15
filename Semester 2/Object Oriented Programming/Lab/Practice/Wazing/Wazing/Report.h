#pragma once
#include <string>
#include <vector>

using namespace std;

class Report
{
private:
	string description, reporter;
	int longitude,latitude;
	bool validated;
	int count_validators = 0;
public:
	Report() {
		this->description = "";
		this->reporter = "";
		this->longitude = 0;
		this->latitude = 0;
		this->validated = false;
	}
	Report(string description, string reporter, int longitude, int latitude, bool validated);
	~Report();
	string getDescription();
	string getReporter();
	int getLongitude();
	int getLatitude();
	bool getValidated();
	int getCountValidators()
	{
		return this->count_validators;
	}
	string toString();
	
	friend istream& operator>>(istream& is, Report& report);
	friend ostream& operator<<(ostream& os, Report& report);
};

