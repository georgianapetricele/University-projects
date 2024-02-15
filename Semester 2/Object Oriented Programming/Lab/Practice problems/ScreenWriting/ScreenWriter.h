#pragma once
#include <string>
using namespace std;

class ScreenWriter
{
protected:
	string name, expertise;
public:
	ScreenWriter();
	ScreenWriter(string name, string expertise);
	~ScreenWriter();
	string getName();
	string getExpertise();
	void setName(string name)
	{
		this->name = name;
	}
	void setExpertise(string expertise)
	{
		this->expertise = expertise;
	}
	friend istream& operator >> (istream& is, ScreenWriter& sw);
	

};

