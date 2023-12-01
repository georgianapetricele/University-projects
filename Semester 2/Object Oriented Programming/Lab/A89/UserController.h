#pragma once
#include "Repo.h"
#include <vector>
#include "HTMLRepository.h"
#include "CSVRepository.h"
#include <fstream>
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

	void read_from_file()
	{
		repo.read_from_file();
	}

	vector<Tutorial> get_repository_tutorials()
	{
		return this->repo.get_all_tutorials();
	}

	//bool check_if_have_same_presenter(string given_presenter);

	Tutorial get_tutorial_on_position(int position);

	vector<Tutorial> get_watchlist();

	Tutorial get_tutorial_at_the_top();

	vector<string> get_presenters();

	vector<Tutorial> get_tutorials_by_presenter(string presenter);

	void set_watchlist_file_type(string file_type);
	
	vector<Tutorial> get_tutorials_by_presenter_list()
	{
		return this->tutorials_by_presenter;
	}


};