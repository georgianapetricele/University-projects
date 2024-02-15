#pragma once

#include <QWidget>
#include "ui_Searchgui.h"
#include "Service.h"

class Searchgui : public QWidget
{
	Q_OBJECT

public:
	Searchgui(Service& service,QWidget *parent = nullptr);
	~Searchgui();
	void connect_search();

private:
	Ui::SearchguiClass ui;
	Service& service;
};
