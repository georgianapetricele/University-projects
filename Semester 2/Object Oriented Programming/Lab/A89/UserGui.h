#pragma once

#include <QMainWindow>
#include "ui_UserGui.h"
#include "UserController.h"
#include "Exceptions.h"

class UserGui : public QMainWindow
{
	Q_OBJECT

private:
	Ui::UserGuiClass ui;
	UserController& user_service;
	int user_pager_index = 0;

public:
	UserGui(UserController &user_service,QWidget *parent = nullptr);
	~UserGui();
	void connect_signals_and_slots();
	void connect_presenter_dropdown_menu_with_list();
	void  populate_presenter_dropdown_menu();
	void connect_add_button();
	void connect_button_next();
	void populate_watchlist();
	void connect_selection_for_watchlist();
	void connect_delete_button();
	void connect_watchlist_type();
	void connect_open_button();
};
