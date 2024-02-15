#pragma once
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Star
{
private:
	string name, constel;
	int RA, Dec, diam;
public:
	Star() {}
	Star(string name, string constel, int RA, int Dec, int diam) :name{ name }, constel{ constel }, RA{ RA }, Dec{ Dec }, diam{ diam } {}

	string getName() { return name; }
	string getConstellation() { return constel; }
	int getRA() { return RA; }
	int getDec() { return Dec; }
	int getDiameter() { return diam; }

	//string toString();
	friend std::istream& operator>>(std::istream& stream, Star& d);
	friend std::ostream& operator<<(std::ostream& stream, const Star& d);

};