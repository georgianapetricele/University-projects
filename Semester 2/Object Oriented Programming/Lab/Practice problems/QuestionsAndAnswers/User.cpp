#include "User.h"
#include <sstream>

User::User()
{
}

User::User(string name)
{
	this->name = name;
}

string User::get_name()
{
	return this->name;
}

User::~User()
{
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


istream& operator>>(istream& is, User& u)
{
	string line;
	getline(is, line);
	vector<string> tokens = tokenize(line, ' ');
	if (tokens.size() != 1)
		return is;
	u.name = tokens[0];
	return is;
}
