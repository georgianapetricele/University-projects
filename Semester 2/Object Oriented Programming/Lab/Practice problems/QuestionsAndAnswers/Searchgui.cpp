#include "Searchgui.h"
#include <string>

using namespace std;

Searchgui::Searchgui(Service& service,QWidget *parent)
	: service{ service },QWidget(parent)
{
	ui.setupUi(this);
	connect_search();
}

Searchgui::~Searchgui()
{}


void Searchgui::connect_search()
{
	QObject::connect(ui.lineEdit,&QLineEdit::textChanged, this, [&]()
		{

			string question = ui.lineEdit->text().toStdString();
			ui.lineEdit_2->setText(QString::fromStdString(service.get_best_matching_question(question)));
		});
}
