#include "Disorder.h"
#include <sstream>
#include <vector>
#include <fstream>

using namespace std;

Disorder::Disorder()
{
}

Disorder::Disorder(string category, string name, string symptoms)
{
	this->category = category;
	this->name = name;
	this->symptoms = symptoms;
}

Disorder::~Disorder()
{
}

string Disorder::get_category()
{
	return this->category;
}

string Disorder::get_name()
{
	return this->name;
}

string Disorder::get_symptoms()
{
	return this->symptoms;
}

string Disorder::toString()
{
	return this->category + " | " + this->name + " | " + this->symptoms;
}

vector<string> tokenize(string given_string, char delimiter)
{
	vector<string> current_parameters;
	stringstream string_stream(given_string);
	string current_token;
	while (getline(string_stream, current_token, delimiter))
		current_parameters.push_back(current_token);
	return current_parameters;
}

istream& operator>>(ifstream& is, Disorder& document)
{
	string line;
	getline(is, line);
	vector<string> tokens = tokenize(line, '|');
	if (tokens.size() != 3)
		return is;
	document.category = tokens[0];
	document.name= tokens[1];
	document.name = document.name.substr(0, document.name.size() - 1);
	document.symptoms = tokens[2];
	document.list_symptoms = tokenize(document.symptoms, ',');
	return is;
}
