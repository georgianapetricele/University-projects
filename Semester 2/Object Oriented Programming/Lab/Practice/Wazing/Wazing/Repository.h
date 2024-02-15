#pragma once
#include <string>
#include <vector>
#include "Driver.h"
#include "Report.h"

using namespace std;
class Repository
{
private:
	vector<Driver> drivers;
	vector<Report> reports;
public:
	Repository() {
		read_from_files();
	}
	~Repository() {
	}
	void add_report(Report report)
	{
		reports.push_back(report);
		load_to_files();
	}
	vector<Driver> getDrivers() {
		return this->drivers;
	}

	vector<Report> getReports() {
		return this->reports;
	}
	void read_from_files();
	void load_to_files();
};

