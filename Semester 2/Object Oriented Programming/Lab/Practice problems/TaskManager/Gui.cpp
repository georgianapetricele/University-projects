#include "Gui.h"

Gui::Gui(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    service.read_from_file();
	populate_list();
	show_with_priority();
}

Gui::~Gui()
{}

void Gui::populate_list()
{
	this->ui.listWidget->clear();
	vector<Task> tasks = this->service.get_all_tasks_sorted();
	for (auto task : tasks)
		if (task.getPriority() == 1)
		{
			QListWidgetItem* item = new QListWidgetItem(QString::fromStdString(task.toString()));
			item->setBackground(Qt::red);
			item->setFont(QFont("Times", 9, QFont::Bold));
			this->ui.listWidget->addItem(item);
		}
		else
			this->ui.listWidget->addItem(QString::fromStdString(task.toString()));
}

void Gui::show_with_priority()
{
	//connect with qlineedit 
	QObject::connect(this->ui.lineEdit, &QLineEdit::textChanged, [&]() 
		{
		string text = this->ui.lineEdit->text().toStdString();
		if (text == "")
		{
			this->populate_list();
			return;
		}
		this->ui.listWidget->clear();
		vector<Task> tasks = this->service.get_all_tasks();
		for (auto task : tasks)
			if(task.getPriority() == stoi(text))
				this->ui.listWidget->addItem(QString::fromStdString(task.toString()));	
		});
}

