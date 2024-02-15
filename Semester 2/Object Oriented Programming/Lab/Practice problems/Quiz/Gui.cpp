#include "Gui.h"

Gui::Gui(Service& service,Participant& participant, QWidget *parent)
    : service{ service }, participant{ participant }, QMainWindow(parent)
{
    ui.setupUi(this);
    this->populate_list_participants();
	this->connect_signals_and_slots2();
}

Gui::~Gui()
{}

void Gui::populate_list_participants()
{
	this->ui.listWidget->clear();
	vector<Question> questions = this->service.getQuestions_descending();
	for (auto question : questions)
	{
		string output=to_string(question.getId()) + "," + question.getText() + "," +to_string(question.getScore());
		this->ui.listWidget->addItem(QString::fromStdString(output));
	}
}

void Gui::connect_signals_and_slots2()
{
	QObject::connect(ui.listWidget, &QListWidget::itemSelectionChanged, this, [&]()
		{
			int index = ui.listWidget->currentIndex().row();
			Question question = this->service.getQuestions_descending()[index];
			string answer = ui.lineEdit->text().toStdString();


		});
}