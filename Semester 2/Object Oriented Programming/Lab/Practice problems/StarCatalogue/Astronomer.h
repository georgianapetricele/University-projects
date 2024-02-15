#include <string>
#include <iostream>
#include <vector>
#pragma once

using namespace std;

class Astronomer
{
private:
	string name, constel;
public:
	Astronomer() {}
	Astronomer(string name, string constel) :name{ name }, constel{ constel } {}

	string getName() { return name; }
	string getConstellation() { return constel; }

	//string toString();
	friend istream& operator>>(std::istream& stream, Astronomer& d);
	friend ostream& operator<<(std::ostream& stream, const Astronomer& d);

};