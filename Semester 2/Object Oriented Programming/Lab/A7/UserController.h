#pragma once
#include "Repo.h"
#include <vector>
#include "HTMLRepository.h"
#include "CSVRepository.h"
class UserController
{
private:
	Repository& repo;
	Repository* watch_list;
	vector <Tutorial> tutorials_by_presenter;
	int position_current_tutorial;
public:
	UserController(Repository& repo, Repository* watch_list);

	~UserController();

	void clear_tutorials_by_presenter();

	int filter_by_presenter(string given_presenter);

	int add_to_watchlist(Tutorial given_tutorial);

	void go_to_next();

	int delete_tutorial_from_watch_list(string title_tutorial_to_delete);

	void open_watchlist_in_given_app();

	int get_size();

	//bool check_if_have_same_presenter(string given_presenter);

	Tutorial get_tutorial_on_position(int position);

	vector<Tutorial> get_watchlist();

	Tutorial get_tutorial_at_the_top();

	void set_watchlist_file_type(string file_type);
};