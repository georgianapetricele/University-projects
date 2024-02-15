#include "Service.h"


Service::Service(Repository& repo) : repo{ repo }
{
}

Service::~Service()
{
}

vector<Driver> Service::getDrivers()
{
	return this->repo.getDrivers();
}

vector<Report> Service::getReports()
{
	return this->repo.getReports();
}

vector<Report> Service::get_reports_by_region(int latitude, int longitude)
{
	vector<Report> reports = this->repo.getReports();
	vector<Report> reports_by_region;
	for (auto report : reports)
	{
		if (abs(report.getLatitude()-latitude)<=10 && abs(report.getLongitude()-longitude) <= 10)
			reports_by_region.push_back(report);
	}
	return reports_by_region;
}

void Service::add_report(Driver driver,string description, string reporter, int latitude, int longitude)
{
	if(description == "")
		throw exception("Description cannot be empty!");
	if(abs(driver.getLongitude()-longitude) > 20 || abs(driver.getLatitude()-latitude) > 20)
		throw exception("Report is too far away from driver!");
	Report report{ description,reporter,latitude,longitude,false };
	this->repo.add_report(report);
}

void Service::validate_report(Report report, Driver driver)
{
	if (report.getValidated())
		throw exception("Report already validated!");
	
}

vector<Report> Service::get_reports_in_radius(Driver driver,int lower_bound, int upper_bound)
{
	vector<Report> reports = this->repo.getReports();
	vector<Report> reports_in_radius;
	int latitude = driver.getLatitude();
	int longitude = driver.getLongitude();
	for (auto report : reports)
	{
		if (abs(report.getLatitude()-latitude)<=upper_bound && abs(report.getLongitude()-longitude)<= upper_bound)
			reports_in_radius.push_back(report);
	}
	return reports_in_radius;
}