#include "Driver.h"
#include <sstream>

Driver::Driver(string name, string status, int longitude, int latitude, int score)
{
	this->name = name;
	this->status = status;
	this->longitude = longitude;
	this->latitude = latitude;
	this->score = score;
}

Driver::~Driver()
{
}

string Driver::getName()
{
	return this->name;
}

string Driver::getStatus()
{
	return this->status;
}

int Driver::getLongitude()
{
	return this->longitude;
}

int Driver::getLatitude()
{
	return this->latitude;
}

int Driver::getScore()
{
	return this->score;
}

string Driver::toString()
{
	return this->name + "," + this->status + "," + to_string(this->longitude) + "," + to_string(this->latitude) + "," + to_string(this->score);
}

vector<string> tokenize_driver(string line, char delimiter)
{
	vector<string> result;
	stringstream ss(line);
	string token;
	while (getline(ss, token, delimiter))
		result.push_back(token);
	return result;
}

istream& operator>>(istream& is, Driver& driver)
{
	string line;
	getline(is, line);
	vector<string> tokens = tokenize_driver(line,',');
	if(tokens.size()!=5)
		return is;
	driver.name = tokens[0];
	driver.status = tokens[1];
	driver.longitude = stoi(tokens[2]);
	driver.latitude = stoi(tokens[3]);
	driver.score = stoi(tokens[4]);
	return is;
}

ostream& operator<<(ostream& os, Driver& driver)
{
	os << driver.getName() << "," << driver.getStatus() << "," << driver.getLongitude() << "," << driver.getLatitude() << "," << driver.getScore();
	return os;
}