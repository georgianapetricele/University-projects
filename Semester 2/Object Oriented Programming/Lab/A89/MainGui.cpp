#include "MainGui.h"

MainGui::MainGui(AdminGui& admingui, UserGui& usergui, QWidget* parent): admin_gui{ admingui }, user_gui{ usergui }, QMainWindow(parent)
{
	ui.setupUi(this);
	connect_signals_and_slots();
}

MainGui::~MainGui()
{}



void MainGui::connect_signals_and_slots()
{
	QObject::connect(ui.admin_mode, &QPushButton::clicked, [&]()
		{
			//connect to the GUI 
			this->admin_gui.show();
			
		});
	QObject::connect(ui.user_mode, &QPushButton::clicked, [&]()
		{
			this->user_gui.show();
		});
}