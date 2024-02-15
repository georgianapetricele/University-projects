#include "Device.h"
#include <fstream>
#include <algorithm>

Device::Device()
{
}

Device::~Device()
{
}

void Device::add_sensor(Sensor* sensor)
{
	this->sensors.push_back(sensor);
}

vector<Sensor*> Device::get_all()
{
	return this->sensors;
}

void Device::save_to_file()
{
	ofstream file("sensors.txt");
	vector<Sensor*> sensors = this->get_all();
	sort(sensors.begin(),sensors.end(), [](Sensor* s1, Sensor* s2) {return s1->get_producer() < s2->get_producer(); });
	for (auto sensor : sensors)
	{
		file << sensor->tostring() << endl;
	}
	file.close();
}