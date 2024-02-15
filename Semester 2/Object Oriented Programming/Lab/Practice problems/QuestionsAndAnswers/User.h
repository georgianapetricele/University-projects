#pragma once
#include <string>
#include <vector>

using namespace std;
class User
{
private:
	string name;
public:
	User();
	User(string name);
	string get_name();
	~User();
	friend istream& operator>>(istream& is, User& u);

};

