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
    void search_documents();
    void show_best_matching();
    ~Gui();

private:
    Ui::GuiClass ui;
    Service service;
};
