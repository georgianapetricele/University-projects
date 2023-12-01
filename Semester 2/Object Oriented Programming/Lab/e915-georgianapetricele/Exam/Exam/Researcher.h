#pragma once
#include <string>
#include <vector>

using namespace std;
class Researcher
{
private:
	string name, position;
public:
	Researcher()
	{
		this->name = "";
		this->position = "";
	}

	Researcher(string name, string position)
	{
		this->name = name;
		this->position = position;
	}
	~Researcher()
	{

	}
	string get_name()
	{
		return name;
	}
	string get_position()
	{
		return this->position;
	}
	friend istream& operator>>(istream& is, Researcher& researcher);

};

