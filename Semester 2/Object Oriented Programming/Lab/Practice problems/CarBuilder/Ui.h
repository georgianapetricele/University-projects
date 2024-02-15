#pragma once
#include "Service.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Ui
{
private:
	Service service;
public:
	Ui();
	~Ui();
	void show_cars();
	void add_car();
	void start();
};