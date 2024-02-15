#include "Car.h"

Car::Car(string body_style, string engine_type, string fuel_type, int autonomy)
{
	Engine* eng;
	this->body_style = body_style;
	this->engine_type = engine_type;
	if (engine_type == "Turbo")
	{
		if(body_style == "Sedan")
			eng = new Turbo(fuel_type, 11000);
		else
			eng = new Turbo(fuel_type, 12000);
		this->engine = eng;
	}
	else
	{
		if (body_style == "Sedan")
			eng = new Electric(fuel_type, 11000,autonomy);
		else
			eng = new Electric(fuel_type, 12000,autonomy);
		this->engine = eng;
	}
	
}

string Car::toString()
{
	return "| Bodystyle: " + this->body_style + " | Enginetype: " + this->engine_type + this->engine->toString();
}

double Car::compute_price()
{
	return this->engine->get_price();
}