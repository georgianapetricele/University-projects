#include "Repository.h"
#include "Driver.h"
#include "Report.h"
#include <fstream>

using namespace std;

void Repository::read_from_files()
{
	ifstream file_drivers("drivers.txt");
	Driver driver;
	while (file_drivers >> driver)
	{
		this->drivers.push_back(driver);
	}
	file_drivers.close();

	ifstream file_reports("reports.txt");
	Report report;
	while (file_reports >> report)
	{
		this->reports.push_back(report);
	}
	file_reports.close();

}

void Repository::load_to_files()
{

	ofstream file_drivers("drivers.txt");
	for (auto driver : this->drivers)
	{
		file_drivers << driver;
	}
	file_drivers.close();
	ofstream file_reports("reports.txt");
	for (auto report : this->reports)
	{
		file_reports << report;
	}
	file_reports.close();
}