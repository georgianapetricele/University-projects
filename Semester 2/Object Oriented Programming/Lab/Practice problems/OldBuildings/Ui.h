#pragma once
#include "Service.h"

class Ui
{
private:
	Service service;

	public:
	Ui();
	~Ui();
	void add_building();
	void list_all_buildings();
	void save_to_file();
	void list_all_to_be_restored();
	void run();
};