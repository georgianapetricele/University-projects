#include "Gui.h"

Gui::Gui(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    this->service.read_from_file();
    populate_list();
    search_by_symptoms();
    show_symptoms();
}

Gui::~Gui()
{}

void Gui::populate_list()
{
    ui.listWidget->clear();
    for(auto& disorder : this->service.get_medical_disorders())
		ui.listWidget->addItem(QString::fromStdString(disorder.toString()));
}

void Gui::search_by_symptoms()
{
    QObject::connect(ui.lineEdit, &QLineEdit::textChanged, [&]() {
        ui.listWidget->clear();
        for (auto& disorder : this->service.get_medical_disorders())
        {
            if (disorder.get_symptoms().find(ui.lineEdit->text().toStdString()) != string::npos)
                ui.listWidget->addItem(QString::fromStdString(disorder.toString()));
        }
        });

}

void Gui::show_symptoms()
{
    QObject::connect(ui.lineEdit_2, &QLineEdit::textChanged, [&]()
        {
            ui.listWidget_2->clear();
            for (auto& disorder : this->service.get_medical_disorders())
            {
                if (disorder.get_name() == ui.lineEdit_2->text().toStdString())
                {
				    for(auto& symptom : disorder.get_list_symptoms())
                        ui.listWidget_2->addItem(QString::fromStdString(symptom));
				}
			}
        }
    );
}