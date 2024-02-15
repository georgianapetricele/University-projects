#pragma once
#include <string>
#include <vector>

using namespace std;

class Task
{
private:
	string description, status;
	int id_programmer;
public:
	Task();
	Task(string description, string status, int id_programmer);
	~Task();
	string getDescription();
	string getStatus();
	int getIdProgrammer();
	bool operator==(const Task& t);
	friend istream& operator>>(istream& is, Task& t);
	string toString();
};

