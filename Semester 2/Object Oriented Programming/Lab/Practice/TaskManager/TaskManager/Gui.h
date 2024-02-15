#pragma once
#include "Service.h"

#include <QtWidgets/QMainWindow>
#include "ui_Gui.h"

class Gui : public QMainWindow
{
    Q_OBJECT

public:
    Gui(QWidget *parent = nullptr);
    void show_with_priority();
    void populate_list();
    ~Gui();

private:
    Ui::GuiClass ui;
    Service service;
};

