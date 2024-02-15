#include "Sensor.h"


Sensor::Sensor()
{
}

Sensor::Sensor(string producer, double recordings)
{
	this->producer = producer;
	this->recordings = recordings;
}

Sensor::~Sensor()
{
}

string Sensor::tostring()
{
	return this->producer + " "  + to_string(this->recordings);
}