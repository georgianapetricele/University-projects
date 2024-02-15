#include "Sensor.h"


HumiditySensor::HumiditySensor()
{
}

HumiditySensor::HumiditySensor(string producer, double recordings)
{
	this->producer = producer;
	this->recordings = recordings;
}

HumiditySensor::~HumiditySensor()
{

}




string HumiditySensor::tostring()
{
	return this->producer + " " + "HumiditySensor"+ " " + to_string(this->recordings);
}