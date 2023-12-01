#pragma once
#include "Controller.h"
#include "UserController.h"
#include "Exceptions.h"
#include "Validators.h"
#include <iostream>


class Ui_initial
{
private:
	Controller& controller;
	UserController& user_controller;
	Validators& validator;

public:

	Ui_initial(Controller& controller, UserController& user_controller, Validators& validator);

	void start();

	void print_admin_menu();

	void enter_admin_mode();

	void enter_user_mode();

	void print_user_menu();

	void add_tutorial_ui();

	void delete_tutorial_ui();

	void list_tutorials_ui();

	void update_tutorial_ui();

	void populate_tutorials_list();

	void user_filter_ui();

	void add_to_watchlist_ui();

	void user_delete_ui();

	void go_to_next_tutorial();

	void user_see_watchlist();

};