#include "Ui.h"
#include <string>


Ui::Ui()
{

}

Ui::~Ui()
{
}

void Ui::add_sensor()
{
	string producer, recordings, diameter, length, type;
	cout << "Producer: ";
	getline(cin, producer);
	cout << "Recordings: ";
	getline(cin, recordings);
	cout << "Type: ";
	getline(cin, type);
	if (type == "temp")
	{
		cout << "Diameter: ";
		getline(cin, diameter);
		cout << "Length: ";
        getline(cin, length);
		Sensor* sensor = new TempSensor(producer, stod(recordings), stod(diameter), stod(length));
		this->sensors.add_sensor(sensor);
	}
	else if (type == "hum")
	{
		Sensor* sensor = new HumiditySensor(producer, stod(recordings));
	}
	else if (type == "smoke")
	{
		Sensor* sensor = new SmokeSensor(producer, stod(recordings));
	}
	else
	{
		cout << "Invalid type\n";
	}
}

void Ui::show_sensors()
{
	for (auto sensor : this->sensors.get_all())
	{
		cout << sensor->tostring() << "\n";
	}
}

void Ui::save_to_file()
{
	this->sensors.save_to_file();
}

void Ui::run()
{
	Sensor* sensor1 = new TempSensor("Emag", 10, 10, 10);
	Sensor* sensor2 = new HumiditySensor("Anonimus", 20);
	Sensor* sensor3 = new SmokeSensor("Producer432874", 30);
	this->sensors.add_sensor(sensor1);
	this->sensors.add_sensor(sensor2);
	this->sensors.add_sensor(sensor3);
	while (true)
	{
		cout << "1. Add a sensor\n";
		cout << "2. Show all sensors\n";
		cout << "3. Show all sensors that emit alerts\n";
		cout << "4. Save to file\n";
		string option;
		getline(cin, option);
		if (option == "1")
			add_sensor();
		else
			if (option == "2")
				show_sensors();
			else
				if (option == "4")
					save_to_file();
	}
	
}