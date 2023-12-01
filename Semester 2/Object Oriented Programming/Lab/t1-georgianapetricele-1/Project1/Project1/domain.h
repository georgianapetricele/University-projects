#pragma once
#include <string>

using namespace std;


typedef struct
{
	int longitude, latitude;
}Adress;

typedef struct
{
	int day, month, year;
}Date_of_visit;

class School
{
private:
	string name;
	Adress adress;
	Date_of_visit date;
	bool was_visited;
public:
	School();
	School(string name, int longitude, int latitude, int year, int month, int day, bool was_visited);
	~School();
	string get_name();
	int get_longitude();
	int get_latitude();
	int get_day();
	int get_month();
	int get_year();
	bool get_was_visited();
	void set_name(string name);
	void set_longitude(int longitude);
	void set_latitude(int latitude);
	void set_day(int day);
	void set_month(int month);
	void set_year(int year);
	void set_was_visited(bool was_visited);
	string convert_to_string();
	bool operator==(const School& school);
};