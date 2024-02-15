#pragma once
#include <string>
#include <vector>

using namespace std;
class Driver
{
private:
	string name, status;
	int longitude, latitude;
	int score;
public:
	Driver() {
		this->name = "";
		this->status = "";
		this->longitude = 0;
		this->latitude = 0;
		this->score = 0;
	}
	Driver(string name, string status, int longitude, int latitude, int score);
	~Driver();
	string getName();
	string getStatus();
	int getLongitude();
	int getLatitude();
	int getScore();
	string toString();
	friend istream& operator>>(istream& is, Driver& driver);
	friend ostream& operator<<(ostream& os, Driver& driver);

};

