#include "Idea.h"
#include <iostream>
#include <sstream>


Idea::~Idea()
{

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

istream& operator>>(istream& is, Idea& idea)
{
	string line;
	getline(is, line);
	vector<string> tokens = tokenize2(line, ',');
	if (tokens.size() != 5)
		return is;
	idea.title = tokens[0];
	idea.description = tokens[1];
	idea.status = tokens[2];
	idea.creator = tokens[3];
	idea.duration = stoi(tokens[4]);
	return is;
}

ostream& operator<<(ostream& os, Idea& idea)
{
	os << idea.title << "," << idea.description << "," << idea.status << "," << idea.creator << "," << idea.duration << "\n";
	return os;
}
