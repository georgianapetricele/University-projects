#include "Gui.h"
#include "Observer.h"

Gui::Gui(Service& service,User& user,QWidget *parent)
    : service{ service }, user{ user },QWidget(parent)
{
    ui.setupUi(this);
    setWindowTitle(QString::fromStdString(user.getName()));
    populate_lists();
    connect_add_post();
}

Gui::~Gui()
{}

void Gui::populate_lists()
{
    ui.listWidget_posts->clear();
    ui.listWidget_subscription->clear();
    string username = windowTitle().toStdString();
    for (auto post : service.get_posts_for_user(username))
    {
		ui.listWidget_posts->addItem(QString::fromStdString(post.toString()));
	}
    for (auto topic : service.get_topics_for_user(username))
    {
		ui.listWidget_subscription->addItem(QString::fromStdString(topic.getDescription()));
	}
}

void Gui::connect_add_post()
{
    QObject::connect(ui.pushButton, &QPushButton::clicked, [&]() 
		{
		string username = windowTitle().toStdString();
		string text = ui.lineEdit->text().toStdString();
		int year = ui.lineEdit_3->text().toInt();
		int month = ui.lineEdit_4->text().toInt();
		int day = ui.lineEdit_5->text().toInt();
		int hour = ui.lineEdit_6->text().toInt();
		int minute = ui.lineEdit_7->text().toInt();
		service.add_post(text, day, month, year, hour, minute, username);
		populate_lists();
		});
}
