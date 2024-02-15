#include "Task.h"
#include <sstream>

Task::Task()
{
}

Task::Task(string description, string status, int id_programmer)
{
	this->description = description;
	this->status = status;
	this->id_programmer = id_programmer;
}

Task::~Task()
{
}

string Task::getDescription()
{
	return this->description;
}

string Task::getStatus()
{
	return this->status;
}

int Task::getIdProgrammer()
{
	return this->id_programmer;
}

bool Task::operator==(const Task& t)
{
	return this->description == t.description;
}

vector<string> tokenize2(string str, char delimiter)
{
	vector<string> result;
	stringstream ss(str);
	string token;
	while (getline(ss, token, delimiter))
		result.push_back(token);
	return result;
}

istream& operator>>(istream& is, Task& t)
{
	string line;
	getline(is, line);
	vector<string> tokens = tokenize2(line, ',');
	if (tokens.size() != 3)
		return is;
	t.description = tokens[0];
	t.status = tokens[1];
	t.id_programmer = stoi(tokens[2]);
	return is;
}

string Task::toString()
{
	return this->description + "," + this->status + "," + to_string(this->id_programmer);
}

