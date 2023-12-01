#pragma once
#include "Controller.h"


class Ui
{
private:
	Controller controller;

public:
	void start();

	~Ui();

	int get_size();

	void print_admin_menu();

	void enter_admin_mode();

	void add_tutorial_ui();

	void delete_tutorial_ui();

	void list_tutorials_ui();

	void update_tutorial_ui();

	void populate_tutorials_list();

};
