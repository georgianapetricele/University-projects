#pragma once

#include <QtWidgets/QWidget>
#include "ui_Gui.h"
#include "Model.h"
#include "ScreenWriter.h"

class Gui : public QWidget
{
    Q_OBJECT

public:
    Gui(Model* model,ScreenWriter& writer,QWidget *parent = nullptr);
    ~Gui();
    void connect_add();

private:
    Ui::GuiClass ui;
    Model* model;
    ScreenWriter& writer;
};
