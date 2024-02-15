#pragma once
#include <vector>
#include "Sensor.h"

using namespace std;

class Device
{
private:
	vector<Sensor*> sensors;
public:
	Device();
	vector<Sensor*> get_all();
	~Device();
	void add_sensor(Sensor* sensor);
	void save_to_file();
};