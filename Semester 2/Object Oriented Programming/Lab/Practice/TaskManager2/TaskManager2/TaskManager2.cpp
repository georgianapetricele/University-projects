#include "TaskManager2.h"
#include <QtWidgets/QApplication>
#include <vector>
#include <qmessagebox.h>

using namespace std;

TaskManager2::TaskManager2(Programmer& programmer, Service& service, QWidget* parent)
	: programmer{ programmer }, service{ service }, QWidget(parent)
{
	ui.setupUi(this);
	this->setWindowTitle(QString::fromStdString(programmer.getName()));
	populate_tasks_list();
	connectSignalsAndSlots();
}

TaskManager2::~TaskManager2()
{}

void TaskManager2::connect_add()
{
	QObject::connect(ui.button_add, &QPushButton::clicked, [&]() {
		string description = ui.line_description->text().toStdString();
		string status = "open";
		int id = ui.line_id->text().toInt();
		Task task{ description, status, id};
		service.add_task(task);
		populate_tasks_list();
		});
}

void TaskManager2::connect_remove()
{
	QObject::connect(ui.button_remove, &QPushButton::clicked, [&]() {
		string description = ui.line_description->text().toStdString();
		service.remove_task_with_description(description);
		populate_tasks_list();
		});
}

void TaskManager2::connect_selection()
{
	QObject::connect(ui.list_tasks, &QListWidget::itemSelectionChanged, [&]() {
		int index = ui.list_tasks->currentIndex().row();
		if (index < 0)
			return;
		vector<Task> tasks = service.getTasks();
		Task task = tasks[index];
		try
		{
			if(task.getStatus() == "open")

}
		catch (exception& e)
		{
			QMessageBox::critical(this, "Error", e.what());
		}
		});
}

void TaskManager2::connectSignalsAndSlots()
{
	connect_add();
	connect_remove();
	connect_selection();
}

void TaskManager2::populate_tasks_list()
{
	ui.list_tasks->clear();

	for (auto task : service.getTasks())
	{
		auto item = new QListWidgetItem(QString::fromStdString(task.toString()));
		ui.list_tasks->addItem(item);
	}
}

