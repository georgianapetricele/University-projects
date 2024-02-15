#include "Presenter.h"
#include <QMessageBox>

Presenter::Presenter(Service& service,QWidget *parent)
	: service{ service },QMainWindow(parent)
{
	ui.setupUi(this);
	this->populate_list();
	this->connect_signals_and_slots();
}

Presenter::~Presenter()
{}

void Presenter::populate_list()
{
	this->ui.listWidget_questions->clear();
		vector<Question> questions = this->service.getQuestions();
		for (auto question : questions)
		{
		this->ui.listWidget_questions->addItem(QString::fromStdString(question.toString()));
	}
}

void Presenter::connect_signals_and_slots()
{
	QObject::connect(ui.pushButton_add, &QPushButton::clicked, this, [&]()
		{
			int id = ui.lineEdit_id->text().toInt();
			string text = ui.lineEdit_text->text().toStdString();
			string correct_answer = ui.lineEdit_answer->text().toStdString();
			int score = ui.lineEdit_score->text().toInt();
			try
			{
				this->service.addQuestion(id, text, correct_answer, score);
				this->populate_list();
			}
			catch (exception& e)
			{
				QMessageBox::critical(this, "Error", e.what());
			}
		});
}