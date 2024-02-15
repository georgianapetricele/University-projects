#include "Gui.h"

Gui::Gui(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    this->service.read_from_file();
    populate_list();
    compute_total_hours();
    filter_list();
}

Gui::~Gui()
{}

void Gui::populate_list()
{
    ui.listWidget->clear();
    for (auto& interval : service.get_intervals())
    {
		ui.listWidget->addItem(QString::fromStdString(interval.toString()));
	}

}

void Gui::filter_list()
{
    QObject::connect(ui.lineEdit_filter, &QLineEdit::textChanged, [&]() 
        {
             auto probability = ui.lineEdit_filter->text().toInt();

            ui.listWidget->clear();
            for (auto& interval : service.get_intervals())
            {
				if (interval.get_precipitations() <= probability)
					ui.listWidget->addItem(QString::fromStdString(interval.toString()));
			}
        });
}


void Gui::compute_total_hours()
{
    QObject::connect(ui.pushButton, &QPushButton::clicked, [&]()
        {
			auto description = ui.lineEdit_2->text().toStdString();
            auto start_time = ui.lineEdit_3->text().toInt();
            string result = service.compute_total(description, start_time);
            ui.lineEdit_4->setText(QString::fromStdString(result));
		});
}