#pragma once
#include <string>
#include <vector>

using namespace std;


class Sensor
{
protected:
	string producer;
	double recordings;
public:
	Sensor();
	Sensor(string producer, double recordings);
	~Sensor();
	virtual string tostring();

	virtual double get_price() = 0;
	virtual string get_producer()
	{
		return this->producer;
	}
	virtual bool send_alert() = 0;
};



class TempSensor : public Sensor
{
private:
	double diameter;
	double length;
public:
	TempSensor();
	TempSensor(string producer, double recordings, double diameter, double length);
	~TempSensor();
	string tostring() override;
	string get_producer() override
	{
		return this->producer;
	}
	double get_price() override
	{
		if (this->diameter < 3 && this->length < 50)
			return 17;
		return 9;
	}
	bool send_alert() override
	{
		for()
	}
};


class HumiditySensor : public Sensor
{
public:
	HumiditySensor();
	HumiditySensor(string producer, double recordings);
	~HumiditySensor();
	string tostring() override;
	string get_producer() override
	{
		return this->producer;
	}
};

class SmokeSensor : public Sensor
{

public:
SmokeSensor();
	SmokeSensor(string producer, double recordings);
	~SmokeSensor();
	string tostring() override;
	string get_producer() override
	{
		return this->producer;
	}
};;