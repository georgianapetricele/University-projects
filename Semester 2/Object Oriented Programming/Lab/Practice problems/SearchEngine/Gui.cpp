#include "Gui.h"
#include <qdebug.h>

Gui::Gui(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    service.read_from_file();
    populate_list();
    search_documents();
    show_best_matching();
}

Gui::~Gui()
{}


void Gui::populate_list()
{
    this->ui.listWidget->clear();
    for (auto& item : this->service.get_documents())
    {
		this->ui.listWidget->addItem(QString::fromStdString(item.toString()));
	}
}

void Gui::search_documents()
{
    QObject::connect(this->ui.lineEdit, &QLineEdit::textChanged, [&]() 
        {
		string text = this->ui.lineEdit->text().toStdString();
		vector<Document> documents = this->service.get_documents();
		vector<Document> result;
        for (auto& item : documents)
        {
            if (item.get_name().find(text) != string::npos || item.get_keywords().find(text) != string::npos)
            {
				result.push_back(item);
			}
		}
        this->ui.listWidget->clear();
        for (auto& item : result)
        {
			this->ui.listWidget->addItem(QString::fromStdString(item.toString()));
		}
	});
}

void Gui::show_best_matching()
{
    QObject::connect(ui.pushButton, &QPushButton::clicked, [&]()
        {
            string text = ui.lineEdit->text().toStdString();
            qDebug()<< QString::fromStdString(text);
            Document best_matching = service.compute_best_matching(text);
            qDebug() << QString::fromStdString(best_matching.toString());
            ui.listWidget->clear();
            ui.listWidget->addItem(QString::fromStdString(best_matching.toString()));
        });
}
