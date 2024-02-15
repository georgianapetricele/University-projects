#pragma once
#include "Service.h"

#include <QtWidgets/QMainWindow>
#include "ui_Gui.h"

class Gui : public QMainWindow
{
    Q_OBJECT

public:
    Gui(QWidget *parent = nullptr);
    void populate_list();
    void filter_list();
    void compute_total_hours();
    ~Gui();

private:
    Ui::GuiClass ui;
    Service service;
};
