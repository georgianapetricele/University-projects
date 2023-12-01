#include "Domain.h"
#include "Tests.h"
#include "Controller.h"
#include "Repo.h"
#include "Ui.h"
#include "Tests.h"
#include <cassert>
#include <vector>
#include "Validators.h"
#include "FakeRepo.h"
#include <iostream>

using namespace std;
void test_domain()
{
	Tutorial tutorial1;
	tutorial1 = Tutorial("Learn C++", "Me", { 15,10 }, 10000, "https//sdvfbg");
	assert(tutorial1.get_title() == "Learn C++");
	assert(tutorial1.get_presenter() == "Me");
	assert(tutorial1.get_number_likes() == 10000);
	assert(tutorial1.get_duration_minutes() == 15);
	assert(tutorial1.get_duration_seconds() == 10);
	assert(tutorial1.get_link() == "https//sdvfbg");
	tutorial1.convert_to_string();
	tutorial1.set_presenter("Not me");
}

void test_repo()
{
	vector<Tutorial> vector1;
	Repository* repo = new Repository();
	Tutorial tutorial1 = Tutorial("Learn C++", "Me", { 15,10 }, 10000, "https//sdvfbg");
	assert(repo->add_tutorial(tutorial1) == 1);
	Tutorial tutorial2 = Tutorial("Learn C", "Me", { 15,10 }, 10000, "https//sdvfbg");
	Tutorial tutorial3 = Tutorial("Learn Java", "Me", { 15,10 }, 10000, "https//sdvfbg");
	assert(repo->add_tutorial(tutorial2) == 1);
	assert(repo->add_tutorial(tutorial3) == 1);
	assert(repo->get_size() == 3);
	Tutorial tutorial_auxiliary = Tutorial("Learn anything", "", { 0,0 }, 0, "");
	assert(repo->add_tutorial(tutorial_auxiliary) == 1);
	assert(repo->delete_tutorial(tutorial_auxiliary) == 1);
	assert(repo->delete_tutorial(tutorial_auxiliary) == -1);
	assert(repo->update_tutorial(tutorial2, tutorial_auxiliary) == 1);
	repo->get_all_tutorials();
}


void test_controller()
{
	vector<Tutorial> vector1;
	Repository* repo = new Repository();
	Controller* controller = new Controller(*repo);
	Validators validator{};
	assert(controller->add_admin_controller("Learn C++", "Me", { 15,10 }, 10000, "https//sdvfbg") == 1);
	controller->add_admin_controller("Learn C", "Me", { 15,10 }, 10000, "https//sdvfbg");
	assert(controller->delete_admin_controller("Learn C++") == 1);
	assert(controller->delete_admin_controller("Learn C++") == -1);
	assert(controller->update_admin_controller("Learn C", "Learn", "Me", 15, 10, 10000, "https//sdvfbg") == 1);
	assert(controller->update_admin_controller("a", "Learn", "Me", 15, 10, 10000, "https//sdvfbg") == -1);
	controller->get_all_tutorials_controller();
	assert(validator.validate_number_input("100") == 1);
	assert(validator.validate_number_input("abc") == 0);

}

void test_user_controller()
{
	vector<Tutorial> vector1;
	Repository repo{ };
	Repository* watch_list = new Repository();
	UserController controller{ repo,watch_list };
	Tutorial tutorial1 = Tutorial("Learn C++", "Me", { 15,10 }, 10000, "https//sdvfbg");
	Tutorial tutorial2 = Tutorial("Learn Java", "Me", { 15,10 }, 10000, "https//sdvfbg");
	Tutorial tutorial3 = Tutorial("Learn C", "Me", { 15,10 }, 10000, "https//sdvfbg");
	assert(controller.add_to_watchlist(tutorial1) == 1);
	repo.add_tutorial(tutorial1);
	repo.add_tutorial(tutorial2);
	assert(controller.add_to_watchlist(tutorial2) == 1);
	assert(controller.add_to_watchlist(tutorial2) == -1);
	assert(controller.get_size() == 2);
	assert(controller.delete_tutorial_from_watch_list("Learn Java") == 1);
	assert(controller.delete_tutorial_from_watch_list("Learn C") == -1);
	assert(controller.filter_by_presenter("") == 1);
	assert(controller.get_tutorial_at_the_top().get_title() == "Learn C++");
	//cout << controller->get_tutorial_on_position(0).get_title();
	assert(controller.get_tutorial_on_position(0).get_title() == "Learn C++");
	//cout << controller->filter_by_presenter("Me");
	assert(controller.filter_by_presenter("Me") == 1);
	assert(controller.filter_by_presenter("NotMe") == -1);
	controller.go_to_next();
}

void test_fake_repo()
{
	int index = 0;
	Repository* fake_repo = new FakeRepo(index);
	Controller* controller1 = new Controller(*fake_repo);
	assert(controller1->add_admin_controller("Learn anything", "Me", { 15,10 }, 10000, "https//sdvfbg") == index);
	try
	{
		assert(controller1->add_admin_controller("Learn anything", "Me", { 15,10 }, 10000, "https//sdvfbg") == index);
	}
	catch (DuplicateException& exception)
	{
		cout << exception.what();
	}
}


void test_all()
{
	//test_domain();
	//test_repo();
	//test_controller();
	//test_user_controller();
	test_fake_repo();
}