#include "Gui.h"
#include <QMessageBox>

Gui::Gui(Model* model, ScreenWriter& writer, QWidget* parent)
    : model{ model }, writer{ writer },QWidget(parent)
{
    ui.setupUi(this);
    ui.tableView->setModel(model);
    model->setWriter(writer);
    setWindowTitle(writer.getName().c_str());
    connect_add();
}

Gui::~Gui()
{}


void Gui::connect_add()
{
    QObject::connect(ui.pushButton, &QPushButton::clicked, [&]() 
        {
		string description = ui.lineEdit->text().toStdString();
	    string act = ui.lineEdit_2->text().toStdString();
        string creator = windowTitle().toStdString();
        try
        {
            model->add_idea(description,creator,act);
        }
        catch (std::exception& e)
        {
			QMessageBox::critical(this, "Error", e.what());
		}
		});
}