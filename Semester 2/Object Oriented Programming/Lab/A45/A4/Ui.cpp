#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
#include "Ui.h"
#include "Domain.h"

using namespace std;

Ui::~Ui()
{

}

int Ui::get_size()
{
	return this->controller.get_size();
}

void Ui::update_tutorial_ui()
{
	string title_tutorial_to_update, title_new_tutorial, new_presenter, new_link, minutes, seconds, number_likes_string;
	Duration new_duration;
	int new_number_likes;
	cout << "Enter the title of the tutorial you want to update: ";
	getline(cin, title_tutorial_to_update);
	cout << "Enter the new title for the chosen tutorial: ";
	getline(cin, title_new_tutorial);
	cout << "Enter the presenter of the tutorial you want to add: ";
	getline(cin, new_presenter);
	while (1)
	{
		cout << "Enter the duration of the tutorial you want to add.\nEnter the number of minutes: ";
		getline(cin, minutes);
		if (!this->controller.validate_number_input(minutes))
			cout << "Invalid number\n";
		else
		{
			new_duration.minutes = stoi(minutes);
			break;
		}
	}
	while (1)
	{
		cout << "Enter the number of seconds: ";
		getline(cin, seconds);
		if (!this->controller.validate_number_input(seconds))
			cout << "Invalid number\n";
		else
		{
			new_duration.seconds = stoi(seconds);
			break;
		}
	}
	while (1)
	{
		cout << "Enter the number of likes to the tutorial: ";
		getline(cin, number_likes_string);
		if (!this->controller.validate_number_input(number_likes_string))
			cout << "Invalid number\n";
		else
		{
			new_number_likes = stoi(number_likes_string);
			break;
		}
	}
	cout << "Enter the link to the tutorial: ";
	getline(cin, new_link);
	int updated_succesfully = this->controller.update_admin_controller(title_tutorial_to_update, title_new_tutorial, new_presenter, new_duration.minutes, new_duration.seconds, new_number_likes, new_link);
	if (updated_succesfully == -1)
		cout << "The tutorial you want to update doesn't exist!";
	else
		cout << "Tutorial updated succesfully!";
}

void Ui::delete_tutorial_ui()
{
	string title_tutorial_to_delete;
	int deleted_succesfully;
	cout << "Enter the title of the tutorial you want to delete: ";
	getline(cin, title_tutorial_to_delete);
	deleted_succesfully = this->controller.delete_admin_controller(title_tutorial_to_delete);
	if (deleted_succesfully == -1)
		cout << "The tutorial you want to delete doesn't exist!";
	else
		cout << "Tutorial deleted succesfully!";
}


void Ui::add_tutorial_ui()
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
		if (!this->controller.validate_number_input(minutes))
			cout << "Invalid number\n";
		else
		{
			duration.minutes = stoi(minutes);
			break;
		}
	}
	while (1)
	{
		cout << "Enter the number of seconds: ";
		getline(cin, seconds);
		if (!this->controller.validate_number_input(seconds))
			cout << "Invalid number\n";
		else
		{
			duration.seconds = stoi(seconds);
			break;
		}
	}
	while (1)
	{
		cout << "Enter the number of likes to the tutorial: ";
		getline(cin, number_likes_string);
		if (!this->controller.validate_number_input(number_likes_string))
			cout << "Invalid number\n";
		else
		{
			number_likes = stoi(number_likes_string);
			break;
		}
	}
	cout << "Enter the link to the tutorial: ";
	getline(cin, link);
	int added_succesfully = this->controller.add_admin_controller(tutorial_title, tutorial_presenter, duration, number_likes, link);
	if (added_succesfully != -1)
	{
		cout << "Tutorial added succesfully!\n";
		list_tutorials_ui();
	}
	else
		cout << "Error. Duplicate tutorial!\n";
}

void Ui::populate_tutorials_list()
{
	Duration duration;
	duration.minutes = 20;
	duration.seconds = 20;
	this->controller.add_admin_controller("Learn C++", "Geeks for geeks", duration, 10000, "https://www.geeksforgeeks.org/c-plus-plus/");
	this->controller.add_admin_controller("Learn Python", "Geeks for geeks", duration, 10000, "https://www.geeksforgeeks.org/c-plus-plus/");
	this->controller.add_admin_controller("Learn Java", "Geeks for geeks", duration, 10000, "https://www.geeksforgeeks.org/c-plus-plus/");
	this->controller.add_admin_controller("Learn C#", "Geeks for geeks", duration, 10000, "https://www.geeksforgeeks.org/c-plus-plus/");
	this->controller.add_admin_controller("Learn React", "Geeks for geeks", duration, 10000, "https://www.geeksforgeeks.org/c-plus-plus/");
	this->controller.add_admin_controller("Learn HTML", "Geeks for geeks", duration, 10000, "https://www.geeksforgeeks.org/c-plus-plus/");
	this->controller.add_admin_controller("Learn Javascript", "Geeks for geeks", duration, 10000, "https://www.geeksforgeeks.org/c-plus-plus/");
	this->controller.add_admin_controller("Learn SQL", "Geeks for geeks", duration, 10000, "https://www.geeksforgeeks.org/c-plus-plus/");
	this->controller.add_admin_controller("Learn C", "Geeks for geeks", duration, 10000, "https://www.geeksforgeeks.org/c-plus-plus/");
}

void Ui::list_tutorials_ui()
{
	DynamicVector list_tutorials = this->controller.get_all_tutorials_controller();
	for (int index = 0; index < list_tutorials.get_size(); index++)
		cout << list_tutorials.get_element_on_position(index).convert_to_string() << '\n';
}

void Ui::print_admin_menu()
{
	cout << "\n\nChoose one of the following commands:\n";
	cout << "add - Add a tutorial\n";
	cout << "del - Delete a tutorial\n";
	cout << "upt - Update the information of a tutorial\n";
	cout << "list - List tutorials\n";
	cout << "exit - Exit admin mode\n\n";
}

void Ui::enter_admin_mode()
{
	string command;
	cout << "Admin Mode Activated";
	print_admin_menu();
	while (1)
	{
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

void Ui::start()
{
	string start_mode;
	int length;
	while (1)
	{
		cout << "\nChoose one of the given options: admin/user/exit.\n";
		getline(cin, start_mode);
		if (start_mode == "admin")
			enter_admin_mode();
		else
			if (start_mode == "exit")
				break;
			else
				cout << "Wrong command!";
	}
}