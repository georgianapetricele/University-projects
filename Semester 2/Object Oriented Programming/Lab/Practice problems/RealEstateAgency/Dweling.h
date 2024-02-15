#pragma once


class Dwelling
{
private:
	double price;
	bool isProfitable;
public:
	Dwelling()
	{

	}
	Dwelling(double price, bool isProfitable)
	{
		this->price = price;
		this->isProfitable = isProfitable;
	}

	bool get_isProfitable()
	{
		return this->isProfitable;
	}

	double get_price()
	{
		return this->price;
	}
};