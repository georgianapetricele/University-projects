#include "Controller.h"
#include "Domain.h"
#include <cstring>
#include <string>
#include <ctype.h>


using namespace std;

Controller::Controller(Repository& repo) : repo{ repo }
{

}


int Controller::add_admin_controller(string title, string presenter, struct Duration duration, int number_likes, string link)
{
	Tutorial current_tutorial{ title,presenter,duration,number_likes,link };
	if (this->repo.find_tutorial(current_tutorial))
	{
		throw exception("Tutorial already exists!");
		return -1;
	}
	else
		return this->repo.add_tutorial(current_tutorial);
}

int Controller::delete_admin_controller(string title_tutorial_to_delete)
{
	Tutorial auxiliary_tutorial = Tutorial{ title_tutorial_to_delete,"",{0,0},0,"" };
	return this->repo.delete_tutorial(auxiliary_tutorial);
}

int Controller::update_admin_controller(string title_tutorial_to_update, string title_new_tutorial, string presenter_new_tutorial, int minutes, int seconds, int number_likes, string link)
{
	Tutorial auxiliary_current_tutorial = Tutorial{ title_tutorial_to_update,"",{0,0},0,"" };
	Tutorial auxiliary_new_tutorial = Tutorial{ title_new_tutorial,presenter_new_tutorial,{minutes,seconds},number_likes,link };
	return this->repo.update_tutorial(auxiliary_current_tutorial, auxiliary_new_tutorial);
}

vector<Tutorial> Controller::get_all_tutorials_controller()
{
	return this->repo.get_all_tutorials();
}

void Controller::read_from_file()
{
	this->repo.read_from_file();
}