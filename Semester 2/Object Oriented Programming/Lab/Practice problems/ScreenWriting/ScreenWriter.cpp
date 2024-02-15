#include "ScreenWriter.h"
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;


ScreenWriter::ScreenWriter()
{
}


ScreenWriter::~ScreenWriter()
{
}

ScreenWriter::ScreenWriter(string name, string expertise)
{
	this->name = name;
	this->expertise = expertise;
}

string ScreenWriter::getName()
{
	return this->name;
}

string ScreenWriter::getExpertise()
{
	return this->expertise;
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

istream& operator >> (istream& is, ScreenWriter& sw)
{
	string line;
	getline(is, line);
	vector<string> tokens = tokenize(line, ',');
	if (tokens.size() != 2) 
		return is;
	sw.name = tokens[0];
	sw.expertise = tokens[1];
	return is;
}