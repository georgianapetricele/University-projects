#pragma once
#include <string>

using namespace std;


class Building
{
protected:
	string address;
	int constructionYear;
public:
	Building();
Building(string address, int constructionYear);
	~Building();
	string get_address();
	int get_construction_year();
	virtual string toString();
	virtual bool must_be_restored();
	virtual bool can_be_demolished();
};

class Block: public Building
{

private:
	int total_apartments;
	int occupied_apartments;
public:
	Block();
	Block(string address, int constructionYear, int total_apartments, int occupied_apartments);
	~Block();
	string toString();
	bool must_be_restored() override;
	bool can_be_demolished() override;
};

class House : public Building
{
private:
	bool is_historical;
public:
	House();
	House(string address, int constructionYear, bool is_historical);
	~House();
	string toString();
	bool must_be_restored() override;
	bool can_be_demolished() override;
};