#pragma once
#include "Service.h"
#include "User.h"

#include <QtWidgets/QWidget>
#include "ui_gui.h"
#include "Observer.h"

class gui : public QWidget, public Observer
{
    Q_OBJECT

public:
    gui(User& user,Service& service,QWidget *parent = nullptr);
    ~gui();
    void populate_list();
    void connect_add();
    void connect_selection();
    void update() override
    {
		populate_list();
        connect_selection();

	}

private:
    Ui::guiClass ui;
    Service& service;
    User& user;
};
