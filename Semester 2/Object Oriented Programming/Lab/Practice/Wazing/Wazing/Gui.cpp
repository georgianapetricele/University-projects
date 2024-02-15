#include "Gui.h"

Gui::Gui(Service& service,Driver& driver,QWidget *parent)
    : service{ service }, driver{ driver },QWidget(parent)
{
    ui.setupUi(this);
    this->set_up_window();
    connect_add();
    connect_selection();
    connect_slider();
}

Gui::~Gui()
{}

void Gui::populate_list_reports()
{
	ui.listWidget->clear();
    for (auto report : this->service.get_reports_by_region(driver.getLatitude(),driver.getLongitude()))
    {
        ui.listWidget->addItem(QString::fromStdString(report.toString()));
	}
}

void Gui::set_up_window()
{
    this->setWindowTitle(QString::fromStdString(driver.getName()));
    string info = "Lat:" + to_string(driver.getLatitude()) + " Long:" + to_string(driver.getLongitude()) + " Score:" + to_string(driver.getScore()) + driver.getStatus();
    ui.lineEdit->setText(QString::fromStdString(info));
    //set window colour with setStyleSheet
    if (driver.getStatus() == "baby")
		this->setStyleSheet("background-color: pink");
	else
        if(driver.getStatus()=="knight")
		this->setStyleSheet("background-color: blue");
		else
			if(driver.getStatus()=="grown-up")
				this->setStyleSheet("background-color: yellow");
    
    this->populate_list_reports();
}


void Gui::connect_selection()
{
    QObject::connect(ui.listWidget, &QListWidget::itemSelectionChanged, [&]() {
		int index = ui.listWidget->currentIndex().row();
        if(index<0)
            return;
		vector<Report> reports = this->service.get_reports_by_region(driver.getLatitude(), driver.getLongitude());
		Report report = reports[index];
		if(report.getValidated() == false)
            service.validate_report(report, driver);
        set_up_window();
		});
}

void Gui::connect_slider()
{
	ui.verticalSlider->setRange(0, 10);
    QObject::connect(ui.verticalSlider, &QSlider::valueChanged, [&]() {
		int value = ui.verticalSlider->value();
       vector<Report> reports=  service.get_reports_in_radius(driver,0, value);
       ui.listWidget_2->clear();
       for (auto report : reports)
       {
           auto item = new QListWidgetItem(QString::fromStdString(report.toString()));
           ui.listWidget_2->addItem(item);
	   }
		set_up_window();
		});
}