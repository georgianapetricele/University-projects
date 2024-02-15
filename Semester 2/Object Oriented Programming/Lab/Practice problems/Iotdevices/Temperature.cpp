#include "Sensor.h"



TempSensor::TempSensor()
{
}

TempSensor::TempSensor(string producer, double recordings, double diameter, double length)
{
	this->producer = producer;
	this->recordings = recordings;
	this->diameter = diameter;
	this->length = length;
}

TempSensor::~TempSensor()
{
}

string TempSensor::tostring()
{
	return this->producer + " " + "TemperatureSensor" + " " + to_string(this->recordings) + " " + to_string(this->diameter) + " " + to_string(this->length);
}