#pragma once
#include <string>
#include <vector>
using namespace std;

class Task
{
private:
	string description;
	int duration, priority;
public:
	Task() {};
	Task(string description, int duration, int priority);
	~Task();
	string getDescription();
	int getDuration();
	int getPriority();
	string toString();
	friend istream& operator>>(istream& is, Task& t);
};

