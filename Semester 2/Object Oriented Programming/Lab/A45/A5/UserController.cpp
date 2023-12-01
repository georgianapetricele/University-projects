#include "UserController.h"


UserController::UserController(Repository& repo,Repository& watch_list): repo{ repo }, watch_list{ watch_list }
{
	this->position_current_tutorial = 0;
}

UserController::~UserController()
{
}

void UserController::clear_tutorials_by_presenter()
{
	for (int index = 0; index < this->tutorials_by_presenter.get_size(); index++)
		this->tutorials_by_presenter.remove(index);
}

int UserController::filter_by_presenter(string given_presenter)
{
	this->clear_tutorials_by_presenter();
	if (given_presenter == "")
	{
		for (int index = 0; index < this->repo.get_size(); index++)
			this->tutorials_by_presenter.add(this->repo.get_tutorial_on_position(index));
	}
	else
	{
		for (int index = 0; index < this->repo.get_size(); index++)
			if(this->repo.get_tutorial_on_position(index).get_presenter() == given_presenter)
				this->tutorials_by_presenter.add(this->repo.get_tutorial_on_position(index));
	}
	
	if (this->tutorials_by_presenter.get_size() == 0)
		return -1;
	else
		return 1;
		
}

int UserController::add_to_watchlist(Tutorial given_tutorial)
{
	if (this->watch_list.add_tutorial(given_tutorial) == 1)
		return 1;
	return -1;
}

int UserController::delete_tutorial_from_watch_list(string title_tutorial_to_delete)
{
	Tutorial auxiliary_tutorial { title_tutorial_to_delete, "", { 0,0 }, 0, "" };
	if (this->watch_list.delete_tutorial(auxiliary_tutorial) != -1)
	{
		int tutorial_position = this->repo.get_tutorial_position(auxiliary_tutorial);
		int number_likes = this->repo.get_tutorial_on_position(tutorial_position).get_number_likes();
		this->repo.get_all_tutorials()[tutorial_position].set_number_likes(number_likes + 1);

		return 1;
	}
	return -1;
}

void UserController::go_to_next()
{
	this->position_current_tutorial++;
	if (this->position_current_tutorial == this->tutorials_by_presenter.get_size())
		this->position_current_tutorial = 0;
}

int UserController::get_size()
{
	return this->watch_list.get_size();
}

Tutorial UserController::get_tutorial_at_the_top()
{
	return this->tutorials_by_presenter[this->position_current_tutorial];
}

Tutorial UserController::get_tutorial_on_position(int position)
{
	return this->watch_list.get_tutorial_on_position(position);
}