#pragma once
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Participant
{
private:
	string name;
	int score;
public:
	Participant();
	Participant(string name, int score);
	~Participant();
	string getName();
	int getScore();
	string toString();
	friend istream& operator>>(istream& is, Participant& p);
};

