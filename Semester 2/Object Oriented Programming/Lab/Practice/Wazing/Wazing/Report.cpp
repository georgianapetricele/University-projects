#include "Report.h"
#include <sstream>

using namespace std;

Report::Report(string description, string reporter, int longitude, int latitude, bool validated)
{
	this->description = description;
	this->reporter = reporter;
	this->longitude = longitude;
	this->latitude = latitude;
	this->validated = validated;
}

Report::~Report()
{
}

string Report::getDescription()
{
	return this->description;
}

string Report::getReporter()
{
	return this->reporter;
}

int Report::getLongitude()
{
	return this->longitude;
}

int Report::getLatitude()
{
	return this->latitude;
}

bool Report::getValidated()
{
	return this->validated;
}

string Report::toString()
{
	return this->description + " " + this->reporter + " " + to_string(this->longitude) + " " + to_string(this->latitude) + " " + to_string(this->validated);
}

vector<string> tokenize_report(string line, char delimiter)
{
	vector<string> result;
	stringstream ss(line);
	string token;
	while (getline(ss, token, delimiter))
		result.push_back(token);
	return result;
}

istream& operator>>(istream& is, Report& report)
{
	string line;
	getline(is, line);
	vector<string> tokens = tokenize_report(line, ',');
	if (tokens.size() != 5)
		return is;
	report.description = tokens[0];
	report.reporter = tokens[1];
	report.longitude = stoi(tokens[2]);
	report.latitude = stoi(tokens[3]);
	string validated = tokens[4];
	if (validated == "yes")
		report.validated = true;
	else
		report.validated = false;
	return is;
}

ostream& operator<<(ostream& os, Report& report)
{
	os << report.description << "," << report.reporter << "," << report.longitude << "," << report.latitude << "," << report.validated << endl;
	return os;
}