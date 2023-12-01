#pragma once

#include <QWidget>
#include "ui_newGUI.h"

class newGUI : public QWidget
{
	Q_OBJECT

public:
	newGUI(QWidget *parent = nullptr);
	~newGUI();

private:
	Ui::newGUIClass ui;
};
