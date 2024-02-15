#pragma once
#include <string>
#include "Engine.h"
#include "TypesEngine.h"

using namespace std;

class Car
{
private:
	string body_style;
	Engine* engine;
	string engine_type;
public:
	Car(string body_style, string engine_type, string fuel_type, int autonomy);
	~Car() {

	}
	string toString();
	double compute_price();
};