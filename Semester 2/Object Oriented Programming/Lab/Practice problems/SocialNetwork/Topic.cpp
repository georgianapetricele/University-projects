#include "Topic.h"
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

Topic::Topic()
{
}

Topic::~Topic()
{
}

void Topic::setDescription(string description)
{
	this->description = description;
}

string Topic::getDescription()
{
	return this->description;
}

void Topic::setUsers(string users)
{
	this->users = users;
}

string Topic::getUsers()
{
	return this->users;
}

vector<string> tokenize1(string str, char delimiter)
{
	vector<string> result;
	stringstream ss(str);
	string token;
	while (getline(ss, token, delimiter))
		result.push_back(token);
	return result;
}

istream& operator>>(istream& is, Topic& topic)
{
	string line;
	getline(is, line);
	vector<string> tokens = tokenize1(line, ',');
	if (tokens.size() != 2)
		return is;
	topic.description = tokens[0];
	topic.users = tokens[1];
	return is;
}

ostream& operator<<(ostream& os, Topic& topic)
{
	os << topic.description << "," << topic.users;
	return os;
}


bool Topic::search_for_user(string username)
{
	vector<string> users = tokenize1(this->users, ' ');
	for (auto user : users)
		if (user == username)
			return true;
	return false;
}