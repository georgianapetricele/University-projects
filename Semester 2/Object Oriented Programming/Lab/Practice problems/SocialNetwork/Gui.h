#pragma once

#include <QtWidgets/QWidget>
#include "ui_Gui.h"
#include "Service.h"
#include "User.h"
#include "Observer.h"

class Gui : public QWidget,public Observer
{
    Q_OBJECT

public:
    Gui(Service& service,User& user,QWidget *parent = nullptr);
    ~Gui();
    void populate_lists();
    void connect_add_post();
    void update() override { populate_lists(); }

private:
    Ui::GuiClass ui;
    Service& service;
    User& user;
};
