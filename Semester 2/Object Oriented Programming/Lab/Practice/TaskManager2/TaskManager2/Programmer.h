#pragma once
#include <string>
#include <vector>

using namespace std;
class Programmer
{
private:
	string name;
	int id;
public:
	Programmer();
	Programmer(string name, int id);
	~Programmer();
	string getName();
	int getId();
	//void setName(string name);
	//void setId(int id);
	bool operator==(const Programmer& p);
	//friend ostream& operator<<(ostream& os, const Programmer& p);
	friend istream& operator>>(istream& is, Programmer& p);
	string toString();
};

