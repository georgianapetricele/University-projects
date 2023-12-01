#pragma once

#include <QtWidgets/QWidget>
#include "ui_Gui.h"
#include "Researcher.h"
#include "Model.h"

class Gui : public QWidget
{
    Q_OBJECT

public:
    string position_current = "";
    string name = "";
    string description = "";
    Gui(Researcher& researcher,Model* model,QWidget *parent = nullptr);
    ~Gui();
    void connect_add_idea();
    void connect_selection();
    void connect_save_all_button();
    void connect_develop_idea();
    void connect_line_edit();

private:
    Ui::GuiClass ui;
    Researcher& researcher;
    Model* model;
};
