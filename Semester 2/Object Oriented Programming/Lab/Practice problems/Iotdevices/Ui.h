#pragma once
#include "Sensor.h"
#include "Device.h"
#include <iostream>

using namespace std;
class Ui
{
private:
	Device sensors;
public:
	Ui();
	~Ui();
	void add_sensor();
	void show_sensors();
	void save_to_file();
	void run();

};