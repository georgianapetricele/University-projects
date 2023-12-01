#include "UserGui.h"
#include <qmessagebox.h>
#include <QProcess>
#include <QStringList>
#include <QUrl>
#include <QDesktopServices>
#include <QMessageBox>

UserGui::UserGui(UserController &user_service,QWidget *parent)
	: user_service{ user_service },QMainWindow(parent)
{
	ui.setupUi(this);
    connect_signals_and_slots();
}

UserGui::~UserGui()
{}

void UserGui::connect_signals_and_slots()
{
    populate_presenter_dropdown_menu();
    connect_presenter_dropdown_menu_with_list();
    connect_watchlist_type();
    connect_add_button();
    connect_button_next();
    populate_watchlist();
    connect_selection_for_watchlist();
    connect_delete_button();
    connect_open_button();
}

void UserGui::populate_presenter_dropdown_menu() 
{
    try {
        if (ui.comboBox_presenters->count() > 0) 
        {
            ui.comboBox_presenters->clear();
        }

        auto option = QString::fromStdString("");
        ui.comboBox_presenters->addItem(option);
        for (auto& presenter : this->user_service.get_presenters()) 
        {
            auto option = QString::fromStdString(presenter);
            ui.comboBox_presenters->addItem(option);
        }

        if (ui.comboBox_presenters->count() > 0) {
            ui.comboBox_presenters->setCurrentIndex(0);
            this->user_pager_index = 0;
        }
    }
    catch (AppError& error)
    {
        QMessageBox::critical(this, "Error", error.what());
    }
}

void UserGui::connect_watchlist_type()
{
}

void UserGui::connect_presenter_dropdown_menu_with_list()
{
    connect(ui.lineEdit_file_type, &QLineEdit::returnPressed, [&]()
        {
            string file_type = ui.lineEdit_file_type->text().toStdString();
            this->user_service.set_watchlist_file_type(file_type);
            populate_watchlist();
        });

        this->user_pager_index = 0;

        user_service.read_from_file();
    for (auto& tutorial : this->user_service.get_repository_tutorials())
    {
        auto item = QString::fromStdString(tutorial.convert_to_string());
        ui.listWidget_tutorials_presenter->addItem(item);
    }
    vector<Tutorial> tutorials = this->user_service.get_repository_tutorials();
    Tutorial tutorial = tutorials[this->user_pager_index];
    ui.lineEdit_title->setText(QString::fromStdString(tutorial.get_title()));
    ui.lineEdit_presenter->setText(QString::fromStdString(tutorial.get_presenter()));
    ui.lineEdit_minutes->setText(QString::fromStdString(std::to_string(tutorial.get_duration_minutes())));
    ui.lineEdit_seconds->setText(QString::fromStdString(std::to_string(tutorial.get_duration_seconds())));
    ui.lineEdit_likes->setText(QString::fromStdString(std::to_string(tutorial.get_number_likes())));
    ui.lineEdit_link->setText(QString::fromStdString(tutorial.get_link()));
    connect(ui.comboBox_presenters, &QComboBox::currentTextChanged, [&]()
        {
       
        try {
            string current_presenter = ui.comboBox_presenters->currentText().toStdString();

            ui.listWidget_tutorials_presenter->clear();
            //ui.listWidget_watchlist->clear();
            for (auto& tutorial : this->user_service.get_tutorials_by_presenter(current_presenter))
            {
                auto item = QString::fromStdString(tutorial.convert_to_string());
                ui.listWidget_tutorials_presenter->addItem(item);
            }

            //connect it with the line edits for the current tutorial
            vector<Tutorial> tutorials = this->user_service.get_tutorials_by_presenter_list();
            Tutorial tutorial = tutorials[this->user_pager_index];
            ui.lineEdit_title->setText(QString::fromStdString(tutorial.get_title()));
            ui.lineEdit_presenter->setText(QString::fromStdString(tutorial.get_presenter()));
            ui.lineEdit_minutes->setText(QString::fromStdString(std::to_string(tutorial.get_duration_minutes())));
            ui.lineEdit_seconds->setText(QString::fromStdString(std::to_string(tutorial.get_duration_seconds())));
            ui.lineEdit_likes->setText(QString::fromStdString(std::to_string(tutorial.get_number_likes())));
            ui.lineEdit_link->setText(QString::fromStdString(tutorial.get_link()));
        }
        catch (AppError& error)
        {
            QMessageBox::critical(this, "Error", error.what());
        }
		});
}

void UserGui::connect_button_next()
{
    //connect the next button
    connect(ui.pushButton_next, &QPushButton::clicked, [&]()
        {
            try {
			vector<Tutorial> tutorials = this->user_service.get_tutorials_by_presenter_list();
            if (tutorials.size() == 0)
            {
                vector<Tutorial> tutorials = this->user_service.get_repository_tutorials();
                this->user_pager_index = this->user_pager_index + 1;
                Tutorial tutorial = tutorials[this->user_pager_index];
                ui.lineEdit_title->setText(QString::fromStdString(tutorial.get_title()));
                ui.lineEdit_presenter->setText(QString::fromStdString(tutorial.get_presenter()));
                ui.lineEdit_minutes->setText(QString::fromStdString(std::to_string(tutorial.get_duration_minutes())));
                ui.lineEdit_seconds->setText(QString::fromStdString(std::to_string(tutorial.get_duration_seconds())));
                ui.lineEdit_likes->setText(QString::fromStdString(std::to_string(tutorial.get_number_likes())));
                ui.lineEdit_link->setText(QString::fromStdString(tutorial.get_link()));
            }
            else
            {
                this->user_pager_index = (this->user_pager_index + 1) % tutorials.size();
                Tutorial tutorial = tutorials[this->user_pager_index];
                ui.lineEdit_title->setText(QString::fromStdString(tutorial.get_title()));
                ui.lineEdit_presenter->setText(QString::fromStdString(tutorial.get_presenter()));
                ui.lineEdit_minutes->setText(QString::fromStdString(std::to_string(tutorial.get_duration_minutes())));
                ui.lineEdit_seconds->setText(QString::fromStdString(std::to_string(tutorial.get_duration_seconds())));
                ui.lineEdit_likes->setText(QString::fromStdString(std::to_string(tutorial.get_number_likes())));
                ui.lineEdit_link->setText(QString::fromStdString(tutorial.get_link()));
            }
		}
            catch (AppError& error)
            {
			QMessageBox::critical(this, "Error", error.what());
		}
		});
}

void UserGui::connect_add_button()
{
	//connect the add button
    connect(ui.pushButton_add, &QPushButton::clicked, [&]()
        {
			string title = ui.lineEdit_title->text().toStdString();
			string presenter = ui.lineEdit_presenter->text().toStdString();
            int duration_minutes = ui.lineEdit_minutes->text().toInt();
            int duration_seconds = ui.lineEdit_seconds->text().toInt();
            int number_likes = ui.lineEdit_likes->text().toInt();
            string link = ui.lineEdit_link->text().toStdString();
            Tutorial tutorial{ title,presenter,{duration_minutes,duration_seconds},number_likes,link };
            try {
                this->user_service.add_to_watchlist(tutorial);
                populate_watchlist();
			}
            catch(DuplicateException& error)
            {
				QMessageBox::critical(this, "Error", error.what());
			}
		});
}

void UserGui::populate_watchlist()
{
      ui.listWidget_watchlist->clear();
        for (auto& tutorial : this->user_service.get_watchlist())
        {
			auto item = QString::fromStdString(tutorial.convert_to_string());
			ui.listWidget_watchlist->addItem(item);
		}
}

void UserGui::connect_selection_for_watchlist()
{
    connect(ui.listWidget_watchlist, &QListWidget::itemSelectionChanged, [&]()
        {
            
		});

    connect(ui.pushButton_exit, &QPushButton::clicked, [&]()
        {
            close();
        });
}

void UserGui::connect_delete_button()
{
    connect(ui.pushButton_delete, &QPushButton::clicked, [&]()
        {
			int index = ui.listWidget_watchlist->currentIndex().row();
            if (index < 0)
            {
                return;
            }
            else
            {
                Tutorial tutorial = this->user_service.get_watchlist()[index];
                try {
                    this->user_service.delete_tutorial_from_watch_list(tutorial.get_title());
					populate_watchlist();
				}
                catch (UnexistentTutorialException& error)
                {
					QMessageBox::critical(this, "Error", error.what());
				}
            }
		});
}

void UserGui::connect_open_button()
{
    connect(ui.pushButton_open, &QPushButton::clicked, [&]()
        {
               try 
                {
                    this->user_service.open_watchlist_in_given_app();
                
				}
                catch (AppError& error)
                {
					QMessageBox::critical(this, "Error", error.what());
				}
		});
}