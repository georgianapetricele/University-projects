#include "Researcher.h"
#include <iostream>
#include <sstream>

using namespace std;

vector<string> tokenize(string str, char delimiter)
{
	vector<string> result;
	stringstream ss(str);
	string token;
	while (getline(ss, token, delimiter))
		result.push_back(token);
	return result;
}

istream& operator>>(istream& is, Researcher& researcher)
{
	string line;
	getline(is, line);
	vector<string> tokens = tokenize(line, ',');
	if(tokens.size() != 2)
		return is;
	researcher.name = tokens[0];
	researcher.position = tokens[1];
	return is;
}

