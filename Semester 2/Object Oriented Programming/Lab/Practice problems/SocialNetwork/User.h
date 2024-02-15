#pragma once
#include <string>
#include <iostream>
using namespace std;

class User
{
private:
	string name;
public:

	User();
	~User();
	void setName(string name);
	string getName();
	friend istream& operator>>(istream& is, User& user);

};
