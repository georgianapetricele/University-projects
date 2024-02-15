#pragma once
#include <string>

using namespace std;
class Topic
{
private:
	string description, users;
public:
	Topic();
	~Topic();
	void setDescription(string description);
	string getDescription();
	void setUsers(string users);
	string getUsers();
	friend istream& operator>>(istream& is, Topic& topic);
	friend ostream& operator<<(ostream& os, Topic& topic);
	bool search_for_user(string username);
};

