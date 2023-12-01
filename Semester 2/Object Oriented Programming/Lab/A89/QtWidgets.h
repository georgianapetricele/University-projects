#pragma once

#include <QMainWindow>
#include "ui_QtWidgets.h"

class QtWidgets : public QMainWindow
{
	Q_OBJECT

public:
	QtWidgets(QWidget *parent = nullptr);
	~QtWidgets();

private:
	Ui::QtWidgetsClass ui;
};
