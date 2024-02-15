#pragma once
#include "RealEstateAgency.h"

class Ui
{
private:
	Agency agency;
public:
	Ui(Agency agency)
	{
		this->agency = agency;
	}
	void start();
	void add_dwelling();
	void remove_client();
	void show_clients();
	void save_clients();
};