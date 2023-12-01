#include "AdminGui.h"
#include <QMessageBox>

AdminGui::AdminGui(Controller& service,QWidget *parent)
	: service{ service },QWidget(parent)
{
	ui.setupUi(this);
	service.read_from_file();
	populate_list();
	connect_signals_and_slots();
}

AdminGui::~AdminGui()
{}

void AdminGui::connect_selection()
{
	connect(ui.listWidget_tutorials, &QListWidget::itemSelectionChanged, [&]() {
		int selectedIndex = ui.listWidget_tutorials->currentRow();
		if (selectedIndex < 0)
			return;
		Tutorial tutorial = service.get_all_tutorials_controller()[selectedIndex];
		ui.lineEdit_title->setText(QString::fromStdString(tutorial.get_title()));
		ui.lineEdit_presenter->setText(QString::fromStdString(tutorial.get_presenter()));
		ui.lineEdit_duration_minutes->setText(QString::fromStdString(std::to_string(tutorial.get_duration_minutes())));
		ui.lineEdit_duration_seconds->setText(QString::fromStdString(std::to_string(tutorial.get_duration_seconds())));
		ui.lineEdit_number_likes->setText(QString::fromStdString(std::to_string(tutorial.get_number_likes())));
		ui.lineEdit_link->setText(QString::fromStdString(tutorial.get_link()));
		});
}

void AdminGui::connect_add_button()
{
	connect(ui.pushButton_add, &QPushButton::clicked, [&]() {
		std::string title = ui.lineEdit_title->text().toStdString();
		std::string presenter = ui.lineEdit_presenter->text().toStdString();
		int duration_minutes = ui.lineEdit_duration_minutes->text().toInt();
		int duration_seconds = ui.lineEdit_duration_seconds->text().toInt();
		int number_likes = ui.lineEdit_number_likes->text().toInt();
		std::string link = ui.lineEdit_link->text().toStdString();
		try
		{
			service.add_admin_controller(title, presenter, { duration_minutes, duration_seconds }, number_likes, link);
			populate_list();
		}
		catch (std::exception& exception)
		{
			QMessageBox::critical(this, "Error", exception.what());
		}
		});
}

void AdminGui::connect_remove_button()
{
	connect(ui.pushButton_remove, &QPushButton::clicked, [&]() {
		std::string title = ui.lineEdit_remove_title->text().toStdString();
		try
		{
			service.delete_admin_controller(title);
			populate_list();
		}
		catch (std::exception& exception)
		{
			QMessageBox::critical(this, "Error", exception.what());
		}
		});
}

void AdminGui::connect_update_button()
{
	connect(ui.pushButton_update, &QPushButton::clicked, [&]()
		{
			string title_tutorial_to_update = ui.lineEdit_update_title->text().toStdString();
			string title_new_tutorial = ui.lineEdit_title->text().toStdString();
			string presenter_new_tutorial = ui.lineEdit_presenter->text().toStdString();
			int minutes = ui.lineEdit_duration_minutes->text().toInt();
			int seconds = ui.lineEdit_duration_seconds->text().toInt();
			int number_likes = ui.lineEdit_number_likes->text().toInt();
			string link = ui.lineEdit_link->text().toStdString();
			try
			{
				service.update_admin_controller(title_tutorial_to_update, title_new_tutorial, presenter_new_tutorial, minutes, seconds, number_likes, link);
				populate_list();
			}
			catch (std::exception& exception)
			{
				QMessageBox::critical(this, "Error", exception.what());
			}

		});
}

void AdminGui::connect_exit_button()
{
	connect(ui.pushButton_exit, &QPushButton::clicked, [&]() {
		close();
		});
}

void AdminGui::connect_signals_and_slots()
{
	connect_selection();
	connect_add_button();
	connect_remove_button();
	connect_update_button();
	connect_exit_button();
}

void AdminGui::populate_list()
{
	ui.listWidget_tutorials->clear();
	for (auto& tutorial : service.get_all_tutorials_controller())
	{
		QString item = QString::fromStdString(tutorial.convert_to_string());
		ui.listWidget_tutorials->addItem(item);
	}
}