#include "Gui.h"

Gui::Gui(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    service.read_from_file();
    populate_list();
    connect_filter();
    connect_show_intervals();

}

Gui::~Gui()
{}

void Gui::populate_list()
{
    ui.listWidget->clear();
    for (auto& item : service.get_all_intervals())
    {
		ui.listWidget->addItem(QString::fromStdString(item.toString()));
	}
}

void Gui::connect_filter()
{
    QObject::connect(ui.lineEdit, &QLineEdit::textChanged, [&]() {
        ui.listWidget->clear();
        for (auto& item : service.get_all_intervals())
        {
            int value = ui.lineEdit->text().toInt();
            if (item.get_precipitations() < value)
                ui.listWidget->addItem(QString::fromStdString(item.toString()));
        }
        });
}

void Gui::connect_show_intervals()
{
    QObject::connect(ui.pushButton, &QPushButton::clicked, [&]() {
		ui.listWidget->clear();
        for (auto& item : service.get_all_intervals())
        { 
            string description = ui.lineEdit_2->text().toStdString();
            int start = ui.lineEdit_3->text().toInt();
            qDebug() << QString::fromStdString(description);
            qDebug() << QString::fromStdString(to_string(start));
            string result = service.compute_total_hours(start, description);
            vector<Interval> resulted_intervals;
            for (auto& interv : service.get_all_intervals())
            {
                if (interv.get_start() >= start && interv.get_description() == description)
                    resulted_intervals.push_back(interv);
                else
                    if (interv.get_start() < start && interv.get_end() > start && interv.get_description() == description)
                        resulted_intervals.push_back(interv);
            }
            ui.lineEdit_4->setText(QString::fromStdString(result));
            ui.listWidget->clear();
            for (auto& item : resulted_intervals)
            {
				ui.listWidget->addItem(QString::fromStdString(item.toString()));
			}
		}
		});
}