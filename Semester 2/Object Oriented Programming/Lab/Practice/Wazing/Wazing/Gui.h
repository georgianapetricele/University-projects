#pragma once

#include <QtWidgets/QWidget>
#include "ui_Gui.h"
#include "Service.h"
#include "Driver.h"
#include <qmessagebox.h>

class Gui : public QWidget
{
    Q_OBJECT

public:
    Gui(Service& service,Driver& driver,QWidget *parent = nullptr);
    ~Gui();
    void populate_list_reports();
    void set_up_window();
    void connect_add() {
        QObject::connect(ui.pushButton, &QPushButton::clicked, [&]() {
			string description = ui.lineEdit_2->text().toStdString();
			int latitude = ui.lineEdit_3->text().toInt();
			int longitude = ui.lineEdit_4->text().toInt();
            string reporter= driver.getName();
            try
            {
                this->service.add_report(driver,description, reporter, latitude, longitude);
            }
            catch (exception& e)
            {
				QMessageBox::critical(this, "Error", e.what());
			}
			this->populate_list_reports();
			});
	}
    void connect_selection();
    void connect_slider();

private:
    Ui::GuiClass ui;
    Service& service;
    Driver& driver;
};
