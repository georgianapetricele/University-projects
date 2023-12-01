#pragma once
#include <string>

using namespace std;

class Dwelling
{
private:
	double price;
	bool is_profitable;
public:
	Dwelling();
	~Dwelling();
	Dwelling(double price, bool is_profitable);
	double get_price();
	bool get_is_profitable();
	string toString();
};