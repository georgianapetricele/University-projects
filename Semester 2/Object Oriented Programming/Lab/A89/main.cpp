#include "GUI.h"
#include <iostream>
#include "Ui.h"
#include "Tests.h"
#include <crtdbg.h>
#include <QtWidgets/QApplication>
#include "MainGui.h"
#include "AdminGui.h"
#include "UserGui.h"

using namespace std;

int main(int argc, char* argv[])
{
	QApplication a(argc, argv);
	
	Repository repo{ "tutorials.txt" };
	Repository* watch_list = new Repository("watchlist.txt");

	Controller controller{ repo };
	UserController user_controller{ repo,watch_list };
	Validators validator{};

	//test_all();
	AdminGui admin_gui{ controller };
	UserGui user_gui{ user_controller };
	//UserGui user_gui{ user_controller };
	MainGui main{ admin_gui, user_gui};
	main.show();
	return a.exec();

	//string start_mode;
	//while (1)
	//{
	//	cout << "\nChoose one of the given options: admin/user/exit.\n";
	//	getline(cin, start_mode);
	//	if (start_mode == "admin")
	//	{
	//		

	//		//enter_admin_mode();
	//	}
	//	else
	//		if (start_mode == "user")
	//		{
	//			Ui ui{ controller,user_controller,validator };
	//			ui.enter_user_mode();
	//		}
	//		else
	//			if (start_mode == "exit")
	//				break;
	//			else
	//				cout << "Invalid command!";
	//}
	//	
	//
	////ui.populate_tutorials_list();


	//	
	//	int length;
	//	try
	//	{
	//		this->controller.read_from_file();
	//	}
	//	catch (FileException& exception)
	//	{
	//		cout << exception.what();
	//		exit(1);
	//	}
	
	//test_all();

}