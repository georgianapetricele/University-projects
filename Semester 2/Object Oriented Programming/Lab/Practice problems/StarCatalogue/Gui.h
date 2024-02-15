#pragma once

#include <QtWidgets/QWidget>
#include "ui_Gui.h"
#include "Star.h"
#include "Astronomer.h"
#include "Model.h"

class Gui : public QWidget
{
    Q_OBJECT

public:
    Gui(Astronomer& astro,Model* model,QWidget *parent = nullptr);
    ~Gui();
    void connect_add();
    void connect_selection();
    void connect_check_box();

private:
    Ui::GuiClass ui;
    Astronomer& astro;
    Model* model;
};
