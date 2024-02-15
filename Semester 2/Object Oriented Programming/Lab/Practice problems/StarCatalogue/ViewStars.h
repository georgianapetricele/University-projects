#pragma once

#include <QWidget>
#include "ui_ViewStars.h"

class ViewStars : public QWidget
{
	Q_OBJECT

public:
	ViewStars(QWidget *parent = nullptr);
	~ViewStars();

private:
	Ui::ViewStarsClass ui;
};
