#include "Gui.h"
#include <QMessageBox>

Gui::Gui(Researcher& researcher,Model* model,QWidget *parent)
    : researcher{ researcher }, model{ model },QWidget(parent)
{
    ui.setupUi(this);
    string input = researcher.get_name() + " - " + researcher.get_position();
    this->position_current = researcher.get_position();
    this->name = researcher.get_name();
    setWindowTitle(input.c_str());
    ui.lineEdit->setText(QString::fromStdString(researcher.get_position()));
    ui.tableView->setModel(model);
    if (model->has_accepted_idea(researcher) == false)
        ui.pushButton_3->setDisabled(true);
    connect_add_idea();
    connect_selection();
    connect_save_all_button();
    connect_line_edit();
    connect_develop_idea();

}

Gui::~Gui()
{}

void Gui::connect_add_idea()
{
    QObject::connect(ui.pushButton, &QPushButton::clicked, [&]() {
		string title = ui.lineEdit_2->text().toStdString();
        string description = ui.lineEdit_3->text().toStdString();
        int duration = ui.lineEdit_4->text().toInt();
        string creator = this->name;
        string status = "proposed";
        try
		{
			model->add_idea(title, description, status, creator, duration);
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
            if(position_current!= "senior")
                QMessageBox::critical(this, "Error", "You are not a senior!");
            else
            {
                if (ui.tableView->selectionModel()->selectedIndexes().isEmpty() || windowTitle().toStdString() != "senior")
                    return;
                QModelIndex index = ui.tableView->selectionModel()->selectedIndexes().at(0);
                int row = index.row();
                Idea idea = model->get_ideas()[row];
            }

		});
}

void Gui::connect_save_all_button()
{
    QObject::connect(ui.pushButton_2, &QPushButton::clicked, [&]() {
        model->load_ideas_to_file();
		});
}

void Gui::connect_line_edit()
{
    QObject::connect(ui.lineEdit_5, &QLineEdit::textChanged, [&]() 
        {
		    this->description = ui.lineEdit_5->text().toStdString();
		});
}


void Gui::connect_develop_idea()
{
   
    QObject::connect(ui.pushButton_3, &QPushButton::clicked, [&]() 
        {
            vector<Idea> ideas;
            ideas = model->get_ideas_for_researcher(this->name);
           ui.listWidget->clear();
           for (auto idea : ideas)
           {
               ui.listWidget->addItem(idea.to_string().c_str());
		   }


		});


    QObject::connect(ui.listWidget, &QListWidget::itemSelectionChanged, [&]() 
        {
            vector<Idea> ideas;
            ideas = model->get_ideas_for_researcher(this->name);
		if (ui.listWidget->selectedItems().isEmpty())
			return;
     
        int index = ui.listWidget->currentRow();
        Idea idea = ideas[index];
        string description = ui.lineEdit_5->text().toStdString();
        ideas[index].description = this->description;
        ui.listWidget->clear();
        for (auto idea : ideas)
        {
            ui.listWidget->addItem(idea.to_string().c_str());
        }
		});
}

