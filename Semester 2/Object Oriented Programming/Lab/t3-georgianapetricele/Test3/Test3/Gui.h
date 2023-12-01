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
    void connect_filter();
    void connect_show_intervals();
    ~Gui();

private:
    Ui::GuiClass ui;
    Service service;
};
