#include "gui.h"
#include "Observer.h"
#include <QMessageBox>

gui::gui(User& user, Service& service, QWidget* parent)
    : user{ user }, service{ service }, QWidget(parent)
{
    ui.setupUi(this);
    this->setWindowTitle(QString::fromStdString(user.get_name()));
    populate_list();
    connect_add();
    connect_selection();
}

gui::~gui()
{}

void gui::populate_list()
{
    ui.listWidget->clear();
    for (auto question : service.get_questions_descending())
        ui.listWidget->addItem(QString::fromStdString(question.toString()));
}

void gui::connect_add()
{
    QObject::connect(ui.pushButton,&QPushButton::pressed, this, [&]()
        {
			string text = ui.lineEdit->text().toStdString();
            try
            {
                service.add_question(service.get_questions_descending().size() + 1, text, this->windowTitle().toStdString());
                populate_list();
            }
            catch (exception& e)
            {
				QMessageBox::critical(this, "Error", e.what());
			}
		});
}

void gui::connect_selection()
{
    QObject::connect(ui.listWidget, &QListWidget::itemSelectionChanged, this, [&]()
        {
            int index = ui.listWidget->currentRow();
            if (index < 0 || index >= service.get_questions_descending().size())
                return;
            Question question = service.get_questions_descending()[index];
            ui.listWidget_2->clear();
            for (auto answer : service.get_answers_to_question(question))
            {
                auto item = new QListWidgetItem(QString::fromStdString(answer.toString()));
                if (answer.get_user_name() == this->windowTitle().toStdString())
                    item->setBackground(Qt::yellow);
                ui.listWidget_2->addItem(item);
            }
        });
}