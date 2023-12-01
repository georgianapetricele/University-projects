#pragma once
#include "Repo.h"
#include <cstring>
#include <string>
#include <cstdlib>

using namespace std;

class Controller
{
private:
	Repository& repo;
public:

	explicit Controller(Repository& repo);

	int add_admin_controller(string title, string presenter, struct Duration duration, int number_likes, string link);

	int delete_admin_controller(string title_tutorial_to_delete);

	int update_admin_controller(string title_tutorial_to_update, string title_new_tutorial, string presenter_new_tutorial, int minutes, int seconds, int number_likes, string link);

	vector<Tutorial> get_all_tutorials_controller();

	void read_from_file();
};