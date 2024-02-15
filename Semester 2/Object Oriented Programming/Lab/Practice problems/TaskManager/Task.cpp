#include "Task.h"
#include <sstream>
#include <vector>

Task::Task(string description, int duration, int priority)
{
	this->description = description;
	this->duration = duration;
	this->priority = priority;
}

Task::~Task()
{}

string Task::getDescription()
{
	return this->description;
}

int Task::getDuration()
{
	return this->duration;
}

int Task::getPriority()
{
	return this->priority;
}

string Task::toString()
{
	return this->description + " | " + to_string(this->duration) + " | " + to_string(this->priority);
}

vector<string> tokenize(string input, char delimiter)
{
	vector<string> tokens;
	stringstream ss(input);
	string token;
	while (getline(ss, token, delimiter))
		tokens.push_back(token);
	return tokens;
}


istream& operator>>(istream& is, Task& t)
{
	string line;
	getline(is, line);
	vector<string> tokens = tokenize(line, '|');
	if(tokens.size() != 3)
		return is;
	t.description = tokens[0];
	t.duration = stoi(tokens[1]);
	t.priority = stoi(tokens[2]);
	return is;

}


