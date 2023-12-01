#pragma once

#include <QMainWindow>
#include "ui_MainGui.h"
#include "AdminGui.h"
#include "UserGui.h"
#include <qpushbutton.h>


class MainGui : public QMainWindow
{
	Q_OBJECT

public:
	MainGui(AdminGui &admingui,UserGui &usergui,QWidget *parent = nullptr);
	~MainGui();
	void connect_signals_and_slots();



private:
	Ui::MainGuiClass ui;
	AdminGui &admin_gui;
	UserGui &user_gui;


};
