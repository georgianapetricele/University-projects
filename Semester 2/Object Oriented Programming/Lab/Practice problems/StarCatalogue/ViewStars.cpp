#include "ViewStars.h"

ViewStars::ViewStars(Service& serv,QWidget *parent)
	: serv{ serv },QWidget(parent)
{
	ui.setupUi(this);
}

ViewStars::~ViewStars()
{}

void viewWidget::paintEvent(QPaintEvent* event)
{
	vector<Star> stars = service.getByConstel(s.getConstel());
	QPainter painter(this);
	for (auto it : stars)
	{
		if (it.getName() == s.getName())
		{
			painter.setBrush(Qt::red);
		}
		else
		{
			painter.setBrush(Qt::black);
		}
		painter.drawEllipse(it.getRA(), it.getDec(), it.getDiam(), it.getDiam());
	}
}