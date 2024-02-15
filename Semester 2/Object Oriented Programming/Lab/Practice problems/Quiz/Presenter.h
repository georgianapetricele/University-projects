#pragma once

#include <QMainWindow>
#include "ui_Presenter.h"
#include "Service.h"

class Presenter : public QMainWindow
{
	Q_OBJECT

public:
	Presenter(Service& service,QWidget *parent = nullptr);
	void populate_list();
	void connect_signals_and_slots();
	~Presenter();

private:
	Ui::PresenterClass ui;
	Service& service;
};
