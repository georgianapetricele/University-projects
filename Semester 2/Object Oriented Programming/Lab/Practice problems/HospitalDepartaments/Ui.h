#pragma once
#include "HospitalDepartament.h"
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
	void add_departament();
	void run();
	void show_departaments();
	void show_efficient_departaments();
	void save_to_file();
};