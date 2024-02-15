#include "User.h"
#include <string>
#include <sstream>
#include <vector>

using namespace std;

User::User()
{
}

User::~User()
{
}

void User::setName(string name)
{
	this->name = name;
}

string User::getName()
{
	return this->name;
}

vector<string> tokenize5(string str, char delimiter)
{
	vector<string> result;
	stringstream ss(str);
	string token;
	while (getline(ss, token, delimiter))
		result.push_back(token);
	return result;
}


istream& operator>>(istream& is, User& user)
{
	string line;
	getline(is, line);
	vector<string> tokens = tokenize5(line, ' ');
	if (tokens.size() != 1)
		return is;
	user.name = tokens[0];
	return is;
}

