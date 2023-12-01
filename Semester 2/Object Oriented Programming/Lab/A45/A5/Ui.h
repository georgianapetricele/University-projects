#pragma once
#include "Controller.h"
#include "../../A45_5/A45_5/UserController.h"


class Ui
{
private:
	Controller& controller;
	UserController& user_controller;
	
public:

	Ui(Controller& controller, UserController& user_controller);

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
