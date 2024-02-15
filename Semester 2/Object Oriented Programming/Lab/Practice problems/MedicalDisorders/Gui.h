#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Gui.h"
#include "Service.h"

class Gui : public QMainWindow
{
    Q_OBJECT

public:
    Gui(QWidget *parent = nullptr);
    ~Gui();
    void populate_list();
    void search_by_symptoms();
    void show_symptoms();

private:
    Ui::GuiClass ui;
    Service service;
};
