#pragma once
#include <string>
#include <vector>
#include <sstream>
using namespace std;

class Post
{
private:
	string text, user;
	int day,month, year, hour, minute;
public:
	Post();
	Post(string text, int day, int month, int year, int hour, int minute, string user)
	{
		this->text = text;
		this->day = day;
		this->month = month;
		this->year = year;
		this->hour = hour;
		this->minute = minute;
		this->user = user;
	}
	~Post();
	void setText(string text) { this->text = text; }
	string getText() { return this->text; }
	string getUser() { return this->user; }
	void setUser(string user) { this->user = user; }
	int getDay() { return this->day; }
	void setDay(int day) { this->day = day; }
	int getMonth() { return this->month; }
	void setMonth(int month) { this->month = month; }
	int getYear() { return this->year; }
	void setYear(int year) { this->year = year; }
	int getHour() { return this->hour; }
	void setHour(int hour) { this->hour = hour; }
	int getMinute() { return this->minute; }
	void setMinute(int minute) { this->minute = minute; }
	friend istream& operator>>(istream& is, Post& post);
	friend ostream& operator<<(ostream& os, Post& post);
	string toString();

};

