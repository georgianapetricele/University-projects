#include "ui.h"
#include "domain.h"


using namespace std;

UI::UI()
{
}

UI::~UI()
{
}

void UI::remove_school_with_given_name_and_adress()
{
	string given_name;
	int longitude;
	int latitude;
	cout << "Enter the name of the school you want to remove: ";
	getline(cin, given_name);
	cout << "Enter the longitude of the school you want to remove: ";
	cin>>longitude;
	cout << "Enter the latitude of the school you want to remove : ";
	cin >> latitude;
	int succesfully_removed = this->service.delete_school(given_name, longitude, latitude);
	if (succesfully_removed == 1)
		cout << "School deleted successfully\n";
	else
		cout << "School not found\n";
}

void UI::show_all_schools()
{
	cout << "\n";
	for (auto school : this->service.get_all_sorted())
		cout << school.convert_to_string() << "\n";
}

void UI::show_all_schools_to_visit_after_given_date()
{
	vector<School> schools_to_visit_after_given_date;
	int day, month, year;
	cout << "Enter the day: ";
	cin >> day;
	cout << "Enter the month: ";
	cin >> month;
	cout << "Enter the year: ";
	cin >> year;
	for (auto school : this->service.get_all())
	{
		if (school.get_year() < year)
			school.set_was_visited(true);
		else
		{
			if (school.get_year() == year)
			{
				if (school.get_month() < month)
					school.set_was_visited(true);
				else
					if (school.get_month() == month)
					{
						if (school.get_day() <= day)
							school.set_was_visited(true);
						else
							schools_to_visit_after_given_date.push_back(school);
					}
					else
						schools_to_visit_after_given_date.push_back(school);
			}
			else
				schools_to_visit_after_given_date.push_back(school);
		}
	}
	for (auto school : schools_to_visit_after_given_date)
		if(school.get_was_visited()==false)
			cout << school.convert_to_string() << "\n";
}

void UI::run_ui()
{
	this->service.add_school(School("Cosbuc", 30, 20, 2023, 10, 14, false));
	this->service.add_school(School("Avram Iancu", 46, 23, 2023, 10, 15, false));
	this->service.add_school(School("Vaida", 40, 23, 2023, 10, 05, false));
	this->service.add_school(School("Transilvania", 40, 10, 2023, 10, 02, true));
	while (true)
	{
		cout << "\n1. Remove school with given name and adress(longitude and latitude)\n";
		cout<<"2. Show all schools\n";
		cout << "3. Show all schools left to visit after given date\n";
	    
		string user_option;
		cout << "Enter your option: ";
		getline(cin, user_option);
		if (user_option == "1")
			this->remove_school_with_given_name_and_adress();
		else
			if (user_option == "2")
				this->show_all_schools();
			else
				if (user_option == "3")
					this->show_all_schools_to_visit_after_given_date();
	}
}

void UI::test_show_all_schools_to_visit_after_given_date()
{
	this->service.add_school(School("Avram Iancu", 46, 23, 2023, 04, 15, true));
	this->service.add_school(School("Cosbuc", 30, 20, 2023, 10, 14, false));
	this->service.add_school(School("Vaida", 40, 23, 2023, 10, 5, true));
	this->show_all_schools_to_visit_after_given_date();
}
