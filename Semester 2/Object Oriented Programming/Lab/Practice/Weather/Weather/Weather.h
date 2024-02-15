#pragma once
#include "Service.h"

#include <QtWidgets/QMainWindow>
#include "ui_Weather.h"

class GUI : public QMainWindow
{
    Q_OBJECT

public:
    GUI(QWidget *parent = nullptr);
    void populate_list();
    void filter();
    void compute_total_hours();
    ~GUI();

private:
    Ui::WeatherClass ui;
    Service service;
};
