#include "Sensor.h"

SmokeSensor::SmokeSensor()
{

}

SmokeSensor::SmokeSensor(string producer, double recordings)
{
	this->producer = producer;
	this->recordings = recordings;
}

SmokeSensor::~SmokeSensor()
{
}


string SmokeSensor::tostring()
{
	return this->producer + " " + "SmokeSensor" + " " + to_string(this->recordings);
}