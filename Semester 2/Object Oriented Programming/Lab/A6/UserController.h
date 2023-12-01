#pragma once
#include "Repo.h"
#include <vector>
class UserController
{
private:
	Repository& repo;
	Repository& watch_list;
	vector <Tutorial> tutorials_by_presenter;
	int position_current_tutorial;
public:
	UserController(Repository& repo, Repository& watch_list);

	~UserController();

	void clear_tutorials_by_presenter();

	int filter_by_presenter(string given_presenter);

	int add_to_watchlist(Tutorial given_tutorial);

	void go_to_next();

	int delete_tutorial_from_watch_list(string title_tutorial_to_delete);

	int get_size();

	bool check_if_have_same_presenter(string given_presenter);

	Tutorial get_tutorial_on_position(int position);

	Tutorial get_tutorial_at_the_top();
};