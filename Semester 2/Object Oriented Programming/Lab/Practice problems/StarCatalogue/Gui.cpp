#include "Gui.h"
#include <QMessageBox>

Gui::Gui(Astronomer& astro,Model* model,QWidget *parent)
    : astro{ astro }, model{ model },QWidget(parent)
{
    ui.setupUi(this);
    this->setWindowTitle(QString::fromStdString(this->astro.getName()));
    ui.tableView->setModel(model);
    connect_add();
	connect_selection();
	connect_check_box();
}

Gui::~Gui()
{}


void Gui::connect_add()
{
    QObject::connect(ui.pushButton, &QPushButton::clicked, [&]()
		{
		string name = ui.lineEdit->text().toStdString();
		int RA = ui.lineEdit_2->text().toInt();
		int Dec = ui.lineEdit_3->text().toInt();
		int diameter = ui.spinBox->value();
		string constellation = model->get_astronomer_constellation(this->windowTitle().toStdString());
		try
		{
			this->model->add_star(name, constellation, RA, Dec, diameter);
		}
		catch (exception& e)
		{
			QMessageBox::critical(this, "Error", e.what());
		}
		});
}

void Gui::connect_selection()
{
	QObject::connect(ui.tableView->selectionModel(), &QItemSelectionModel::selectionChanged, [&]()
		{
			
			int row = ui.tableView->selectionModel()->selectedIndexes().at(0).row();
			Star star = this->model->getStars()[row];
			ui.lineEdit->setText(QString::fromStdString(star.getName()));
			ui.lineEdit_2->setText(QString::fromStdString(to_string(star.getRA())));
			ui.lineEdit_3->setText(QString::fromStdString(to_string(star.getDec())));
			ui.spinBox->setValue(star.getDiameter());
		});
}

void Gui::connect_check_box()
{
	QObject::connect(ui.checkBox, &QCheckBox::stateChanged, [&]()
		{
			vector<Star>  stars = this->model->getStars();
			if (ui.checkBox->isChecked())
			{
				string constellation = model->get_astronomer_constellation(this->windowTitle().toStdString());
				
				for(int i=0;i< stars.size();i++)
					if (stars[i].getConstellation() != constellation)
					{
						this->ui.tableView->hideRow(i);
					}
					else
					{
						this->ui.tableView->showRow(i);
					}
			}
			else
			{
				for (int i = 0; i < stars.size(); i++)
				{
					this->ui.tableView->showRow(i);
				}
			}
		});
}