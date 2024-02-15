#include "Weather.h"
#include <qmessagebox.h>


GUI::GUI(QWidget *parent): QMainWindow(parent)
{
	this->service.read_from_file();
    ui.setupUi(this);
	this->populate_list();
	this->filter();
	this->compute_total_hours();
}

GUI::~GUI()
{}

void GUI::compute_total_hours()
{

	QObject::connect(ui.button_compute_total_hours, &QPushButton::clicked, [&]()
		{
			int total_hours = 0;
			string result = "";

			string given_description = ui.line_edit_description->text().toStdString();
			int start_time = ui.line_edit_start_time->text().toInt();
			for (auto& interval : this->service.get_all_intervals())
			{
				if (interval.get_description() == given_description && stoi(interval.get_end_hour()) >= start_time)
					total_hours += stoi(interval.get_end_hour()) - stoi(interval.get_start_hour());
			}
			if (total_hours == 0)
				result = "Error!No intervals!";
			else
				result = "The total hours of " + given_description + " weather are: " + to_string(total_hours);
			this->ui.list_compute->addItem(QString::fromStdString(result));
		});
}

void GUI::filter()
{
	QObject::connect(ui.line_edit_filter, &QLineEdit::textChanged, [&]() {
		int given_value_for_filter = stoi(ui.line_edit_filter->text().toStdString());
		vector<Interval> intervals = this->service.get_all_intervals();
		ui.list_of_intervals->clear();
		for (auto interval : intervals)
		{
			if(stoi(interval.get_precipitation_probability()) < given_value_for_filter || given_value_for_filter==0)
				ui.list_of_intervals->addItem(QString::fromStdString(interval.convert_to_string()));
		}
	});
}

void GUI::populate_list()
{

	ui.list_of_intervals->clear();
	vector<Interval> intervals = this->service.get_all_intervals();
	for (auto interval : intervals)
	{
		QListWidgetItem* item = new QListWidgetItem(QString::fromStdString(interval.convert_to_string()));
		item->setBackground(QBrush{Qt::yellow, Qt::SolidPattern});
		ui.list_of_intervals->addItem(item);
	}
}