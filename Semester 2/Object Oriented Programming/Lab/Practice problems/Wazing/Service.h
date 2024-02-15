#pragma once
#include "Repository.h"
#include "Driver.h"
#include "Report.h"

class Service
{
private:
	Repository& repo;
public:
	Service(Repository& repo);
	~Service();
	vector<Driver> getDrivers();
	vector<Report> getReports();
	vector<Report> get_reports_by_region(int latitude, int longitude);
	void add_report(Driver driver,string description, string reporter, int latitude, int longitude);
	void validate_report(Report report, Driver driver);
	vector<Report> get_reports_in_radius(Driver driver,int lower_bound, int upper_bound);
};

