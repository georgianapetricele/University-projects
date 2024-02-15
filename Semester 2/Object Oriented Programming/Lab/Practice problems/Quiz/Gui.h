#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Gui.h"
#include "Service.h"
#include "Participant.h"
#include "Observer.h"

class Gui : public QMainWindow, public Observer
 {
	Q_OBJECT

public:
    Gui(Service& service,Participant& participant, QWidget *parent = nullptr);
    void populate_list_participants();
    ~Gui();
    void update() override
    {
		this->populate_list_participants();
	}
    void connect_signals_and_slots2();

private:
    Ui::GuiClass ui;
    Service& service;
    Participant& participant;
};
