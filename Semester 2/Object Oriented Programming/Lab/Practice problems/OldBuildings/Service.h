#pragma once
#include <vector>
#include <string>
#include "Building.h"
using namespace std;
class Service
{

private:
	vector<Building*> buildings;
public:
	Service();
	~Service();
	void addBuilding(Building* building);
	vector<Building*> get_all();
	vector<Building*> get_all_to_be_restored();
	vector<Building*> get_all_to_be_demolished();
	int write_to_file(string filename);
};