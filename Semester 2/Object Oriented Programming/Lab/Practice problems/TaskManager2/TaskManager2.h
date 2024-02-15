#pragma once

#include <QtWidgets/QWidget>
#include "ui_TaskManager2.h"
#include "Service.h"
#include "Programmer.h"

class TaskManager2 : public QWidget, public Observer
{
    Q_OBJECT

public:
    TaskManager2(Programmer& programmer, Service& service, QWidget* parent = Q_NULLPTR);
    ~TaskManager2();
    void populate_tasks_list();
    void connectSignalsAndSlots();
    void connect_add();
    void connect_remove();
    void connect_selection();
    void update() override
    {
		populate_tasks_list();
	}

private:
    Ui::TaskManager2Class ui;
    Programmer& programmer;
    Service& service;
};
