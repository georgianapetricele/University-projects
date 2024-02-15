#include "Programmer.h"
#include <sstream>

Programmer::Programmer()
{
	this->name = "";
	this->id = 0;
}

Programmer::Programmer(string name, int id)
{
	this->name = name;
	this->id = id;
}

Programmer::~Programmer()
{
}

string Programmer::getName()
{
	return this->name;
}

int Programmer::getId()
{
	return this->id;
}

bool Programmer::operator==(const Programmer& p)
{
	return this->name == p.name && this->id == p.id;
}

vector<string> tokenize(string str, char delimiter)
{
	vector<string> result;
	stringstream ss(str);
	string token;
	while (getline(ss, token, delimiter))
		result.push_back(token);
	return result;
}

istream& operator>>(istream& is, Programmer& p)
{
	string line;
	getline(is, line);
	vector<string> tokens = tokenize(line, ',');
	if (tokens.size() != 2)
		return is;
	p.name = tokens[0];
	p.id = stoi(tokens[1]);
	return is;
}

string Programmer::toString()
{
	return this->name + "," + to_string(this->id);
}