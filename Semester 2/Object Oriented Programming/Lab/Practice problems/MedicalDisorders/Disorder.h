#pragma once
#include <string>
#include <vector>


using namespace std;
class Disorder
{
private:
	string category, name, symptoms;
	vector<string> list_symptoms;
public:
	Disorder();
	Disorder(string category, string name, string symptoms);
	~Disorder();
	string get_category();
	string get_name();
	string get_symptoms();
	vector<string> get_list_symptoms() { return this->list_symptoms; }
	string toString();
	friend istream& operator>>(ifstream& is, Disorder& disorder);
};

