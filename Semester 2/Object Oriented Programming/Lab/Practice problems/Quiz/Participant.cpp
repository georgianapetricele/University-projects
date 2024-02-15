#include "Participant.h"
#include <sstream>


Participant::Participant()
{
	this->name = "";
	this->score = 0;
}

Participant::Participant(string name, int score)
{
	this->name = name;
	this->score = score;
}

Participant::~Participant()
{
}

string Participant::getName()
{
	return this->name;
}

int Participant::getScore()
{
	return this->score;
}

string Participant::toString()
{
	return this->name + "," + to_string(this->score);
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

istream& operator>>(istream& is, Participant& p)
{
	string line;
	getline(is, line);
	vector<string> tokens = tokenize2(line, ',');
	if (tokens.size() != 2)
		return is;
	p.name = tokens[0];
	p.score = stoi(tokens[1]);
	return is;
}