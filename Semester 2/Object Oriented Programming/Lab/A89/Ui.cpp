#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <cstdlib>
#include "Ui.h"
#include "Domain.h"

using namespace std;

Ui_initial::Ui_initial(Controller& controller, UserController& user_controller, Validators& validator) : controller{ controller }, user_controller{ user_controller }, validator{ validator }
{

}

void Ui_initial::update_tutorial_ui()
{
	string title_tutorial_to_update, title_new_tutorial, new_presenter, new_link, minutes, seconds, number_likes_string;
	Duration new_duration;
	int new_number_likes;
	cout << "Enter the title of the tutorial you want to update: ";
	getline(cin, title_tutorial_to_update);
	cout << "Enter the new title for the chosen tutorial: ";
	getline(cin, title_new_tutorial);
	cout << "Enter the new presenter of the tutorial you want to add: ";
	getline(cin, new_presenter);
	while (1)
	{
		cout << "Enter the new duration of the tutorial you want to add.\nEnter the number of minutes: ";
		getline(cin, minutes);
		try
		{
			int is_number = this->validator.validate_number_input(minutes);
			new_duration.minutes = stoi(minutes);
			break;
		}
		catch (InvalidNumberException& exception)
		{
			cout << exception.what() << "\n\n";
		}
	}
	while (1)
	{
		cout << "Enter the new number of seconds: ";
		getline(cin, seconds);
		try
		{
			int is_number = this->validator.validate_number_input(seconds);
			new_duration.seconds = stoi(seconds);
			break;
		}
		catch (InvalidNumberException& exception)
		{
			cout << exception.what() << "\n\n";
		}

	}
	while (1)
	{
		cout << "Enter the new number of likes to the tutorial: ";
		getline(cin, number_likes_string);
		try
		{
			int is_number = this->validator.validate_number_input(number_likes_string);
			new_number_likes = stoi(number_likes_string);
			break;
		}
		catch (InvalidNumberException& exception)
		{
			cout << exception.what() << "\n\n";
		}
	}
	cout << "Enter the new link to the tutorial: ";
	getline(cin, new_link);
	try
	{
		int updated_succesfully = this->controller.update_admin_controller(title_tutorial_to_update, title_new_tutorial, new_presenter, new_duration.minutes, new_duration.seconds, new_number_likes, new_link);
		cout << "Tutorial updated succesfully!";
	}
	//catch unexistent tutorial exception
	catch (UnexistentTutorialException& exception)
	{
		cout << exception.what() << "\n";
	}
	catch (FileException& exception)
	{
		cout << exception.what() << "\n";
	}

}

void Ui_initial::delete_tutorial_ui()
{
	string title_tutorial_to_delete;
	int deleted_succesfully;
	cout << "Enter the title of the tutorial you want to delete: ";
	getline(cin, title_tutorial_to_delete);
	try
	{
		deleted_succesfully = this->controller.delete_admin_controller(title_tutorial_to_delete);
		cout << "Tutorial deleted succesfully!";
	}
	catch (UnexistentTutorialException& exception)
	{
		cout << exception.what() << "\n";
	}
	catch (FileException& exception)
	{
		cout << exception.what() << "\n";
	}

}


void Ui_initial::add_tutorial_ui()
{
	string tutorial_title, tutorial_presenter, link, minutes, seconds, number_likes_string;
	int number_likes;
	Duration duration = {};
	cout << "Enter the title of the tutorial you want to add: ";
	getline(cin, tutorial_title);
	cout << "Enter the presenter of the tutorial you want to add: ";
	getline(cin, tutorial_presenter);
	while (1)
	{
		cout << "Enter the duration of the tutorial you want to add.\nEnter the number of minutes: ";
		getline(cin, minutes);
		try
		{
			int is_number = this->validator.validate_number_input(minutes);
			duration.minutes = stoi(minutes);
			break;
		}
		catch (InvalidNumberException& exception)
		{
			cout << exception.what() << "\n\n";
		}
	}
	while (1)
	{
		cout << "Enter the number of seconds: ";
		getline(cin, seconds);
		try
		{
			int is_number = this->validator.validate_number_input(seconds);
			duration.seconds = stoi(seconds);
			break;
		}
		catch (InvalidNumberException& exception)
		{
			cout << exception.what() << "\n\n";
		}
	}
	while (1)
	{
		cout << "Enter the number of likes to the tutorial: ";
		getline(cin, number_likes_string);
		try
		{
			int is_number = this->validator.validate_number_input(number_likes_string);
			number_likes = stoi(number_likes_string);
			break;
		}
		catch (InvalidNumberException& exception)
		{
			cout << exception.what() << "\n\n";
		}
	}
	cout << "Enter the link to the tutorial: ";
	getline(cin, link);
	bool is_valid = false;
	try
	{
		Tutorial new_tutorial = Tutorial(tutorial_title, tutorial_presenter, duration, number_likes, link);
		this->validator.validate_tutorial(new_tutorial);
		is_valid = true;
	}
	catch (TutorialExceptions& exceptions)
	{
		cout << "\nInvalid tutorial!\n";
		for (auto error : exceptions.get_errors())
			cout << error << "\n";
	}

	if (is_valid == true)
	{
		try
		{
			int added_succesfully = this->controller.add_admin_controller(tutorial_title, tutorial_presenter, duration, number_likes, link);
			cout << "Tutorial added succesfully!\n";
		}
		catch (DuplicateException& exception)
		{
			cout << exception.what() << "\n";
		}
		catch (FileException& exception)
		{
			cout << exception.what() << "\n";
		}
	}

}

//void Ui::populate_tutorials_list()
//{
//	Duration duration;
//	duration.minutes = 20;
//	duration.seconds = 20;
//	this->controller.add_admin_controller("Learn C++", "Geeks for geeks", duration, 10000, "https://www.geeksforgeeks.org/c-plus-plus/");
//	this->controller.add_admin_controller("Learn Python", "Geeks for geeks", duration, 10001, "https://www.geeksforgeeks.org/python-programming-language/");
//	this->controller.add_admin_controller("Learn Java", "Geeks for geeks", duration, 10000, "https://www.geeksforgeeks.org/java/");
//	this->controller.add_admin_controller("Learn C#", "Geeks for geeks", duration, 10000, "https://www.geeksforgeeks.org/c-plus-plus/");
//	this->controller.add_admin_controller("Learn React", "Geeks for geeks", duration, 10000, "https://www.geeksforgeeks.org/c-plus-plus/");
//	this->controller.add_admin_controller("Learn HTML", "Geeks for geeks", duration, 10000, "https://www.geeksforgeeks.org/c-plus-plus/");
//	this->controller.add_admin_controller("Learn Javascript", "Geeks for geeks", duration, 10000, "https://www.geeksforgeeks.org/c-plus-plus/");
//	this->controller.add_admin_controller("Learn SQL", "Geeks for geeks", duration, 10000, "https://www.geeksforgeeks.org/c-plus-plus/");
//	this->controller.add_admin_controller("Learn C", "Geeks for geeks", duration, 10000, "https://www.geeksforgeeks.org/c-plus-plus/");
//}


void Ui_initial::list_tutorials_ui()
{
	try
	{
		vector<Tutorial> list_tutorials = this->controller.get_all_tutorials_controller();
		for (auto tutorial : list_tutorials)
			cout << tutorial.convert_to_string() << '\n';
	}
	catch (FileException& exception)
	{
		cout << exception.what() << "\n";
	}

}

void Ui_initial::print_admin_menu()
{
	cout << "\n\nChoose one of the following commands:\n";
	cout << "add - Add a tutorial\n";
	cout << "del - Delete a tutorial\n";
	cout << "upt - Update the information of a tutorial\n";
	cout << "list - List tutorials\n";
	cout << "exit - Exit admin mode\n\n";
}

void Ui_initial::enter_admin_mode()
{
	string command;
	cout << "Admin Mode Activated";
	while (1)
	{
		print_admin_menu();
		cout << "\nEnter your option: ";
		getline(cin, command);
		if (command == "add")
			add_tutorial_ui();
		else
			if (command == "list")
				list_tutorials_ui();
			else
				if (command == "exit")
					break;
				else
					if (command == "del")
						delete_tutorial_ui();
					else
						if (command == "upt")
							update_tutorial_ui();
						else
							cout << "Invalid command!";
	}
}

void Ui_initial::go_to_next_tutorial()
{
	this->user_controller.go_to_next();
}

void Ui_initial::add_to_watchlist_ui()
{
	try
	{
		int added_succesfully = this->user_controller.add_to_watchlist(this->user_controller.get_tutorial_at_the_top());
		cout << "Tutorial added succesfully!";
	}
	catch (UnexistentTutorialException& exception)
	{
		cout << exception.what() << "\n";
	}

}

void Ui_initial::user_filter_ui()
{
	/*
	*See the tutorials in the database having a given presenter
	(if the presenter name is empty, see all the tutorials),
	one by one. When the user chooses this option, the data of
	the first tutorial (title, presenter, duration, number of likes)
	is displayed and the tutorial is played in the browser.
	If the user likes the tutorial, he/she can choose to add it to his/her tutorial watch list.
	If the tutorial seems uninteresting, the user can choose not to add it to the watch list and continue to the next.
	*/
	string given_presenter, user_option;
	cout << "\n>>Enter the presenter for filtering tutorials: <<\n";
	getline(cin, given_presenter);
	int filtered_succesfully = this->user_controller.filter_by_presenter(given_presenter);
	while (filtered_succesfully != -1)
	{
		//get tutorial at the top
		Tutorial current_tutorial = this->user_controller.get_tutorial_at_the_top();
		cout << current_tutorial.convert_to_string();
		//string url = current_tutorial.get_link();
		//string op = string("start ").append(url);
		//system(op.c_str());

		//Choose what to do with given tutorial
		//Add to watch_list
		//Go to Next
		//Exit
		cout << "\n\nEnter your option for tutorials with given presenter:\n";
		cout << "add - Add current tutorial to the watchlist\n";
		cout << "next - Pass over current tutorial and go to the next\n";
		cout << "exit - Exit filtering the tutorials with given presenter\n\n";
		getline(cin, user_option);
		if (user_option == "add")
		{
			this->add_to_watchlist_ui();
			this->go_to_next_tutorial();
		}
		else
			if (user_option == "next")
				this->go_to_next_tutorial();
			else
				if (user_option == "exit")
					break;
				else
					cout << "Invalid command!";
	}
}

void Ui_initial::user_delete_ui()
{
	/*
	Delete a tutorial from the watch list, after the user watched the tutorial.
	When deleting a tutorial from the watch list, the user can also rate the tutorial (with a like),
	and in this case, the number of likes for the tutorial will be increased.
	*/
	string title_tutorial_to_delete;
	cout << "Enter the title of the tutorial you want to delete from the watch list: ";
	getline(cin, title_tutorial_to_delete);
	try
	{
		int deleted_succesfully = this->user_controller.delete_tutorial_from_watch_list(title_tutorial_to_delete);
		cout << "Tutorial deleted succesfully!";
	}
	catch (UnexistentTutorialException& exception)
	{
		cout << exception.what() << "\n";
	}

}

void Ui_initial::user_see_watchlist()
{
	if (this->user_controller.get_size() == 0)
		cout << "Your Watch List is Empty!!!";
	else
	{
		cout << "\n>>Your Watch List<<\n";
		for (auto tutorial : this->user_controller.get_watchlist())
			cout << tutorial.convert_to_string();
	}
}

void Ui_initial::print_user_menu()
{
	cout << "\n\nChoose one of the following commands:\n";
	cout << "seep - See the tutorials in the database having a given presenter (if presenter name is empty, see all the tutorials)\n";
	cout << "delb - Delete a tutorial from the watch list (and rate it)\n";
	cout << "seel - See the watch list\n";
	cout << "exit - Exit user mode\n";
	cout << "openl - Open the watch list (from CSV or HTML file) with the associated app (Google Chrome or Microsoft Excel)\n\n";
}


void Ui_initial::enter_user_mode()
{
	string command;
	cout << "\n>>User Mode Activated<<\n";
	cout << "Enter your option for storing the watchlist (csv or html): ";
	getline(cin, command);
	if (command == "csv" || command == "html")
		this->user_controller.set_watchlist_file_type(command);
	else
		cout << "Invalid command!";
	while (1)
	{
		print_user_menu();
		cout << "\nEnter your option: ";
		getline(cin, command);
		if (command == "seep")
			user_filter_ui();
		else
			if (command == "delb")
				user_delete_ui();
			else
				if (command == "seel")
					user_see_watchlist();
				else
					if (command == "openl")
						this->user_controller.open_watchlist_in_given_app();
					else
						if (command == "exit")
							break;
						else
							cout << "\nInvalid command!\n";
	}
}
