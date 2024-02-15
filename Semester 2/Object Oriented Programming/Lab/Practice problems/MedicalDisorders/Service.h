#pragma once
#include <vector>
#include <string>
#include "Disorder.h"

using namespace std;

class Service
{
private:
	vector<Disorder> disorders;
public:
	Service();
	~Service();
	vector<Disorder> get_medical_disorders();
	void read_from_file();

};

