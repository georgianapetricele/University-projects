#pragma once

#include <QWidget>
#include "ui_AdminGui.h"
#include "Controller.h"

class AdminGui : public QWidget
{
	Q_OBJECT

public:
	explicit AdminGui(Controller &service, QWidget *parent = nullptr);
	~AdminGui();
	void connect_signals_and_slots();
	void connect_selection();
	void connect_add_button();
	void connect_remove_button();
	void connect_update_button();
	void connect_exit_button();
	void populate_list();

private:
	Ui::AdminGuiClass ui;
	Controller &service;
};
