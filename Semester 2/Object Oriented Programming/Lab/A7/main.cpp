#include <iostream>
#include "Ui.h"
#include "Tests.h"
#include <crtdbg.h>

#define _CRTDBG_MAP_ALLOC

using namespace std;

int main()
{
	Repository repo{"tutorials.txt"};
	Repository* watch_list = new Repository("watchlist.txt");

	Controller controller{ repo };
	UserController user_controller{ repo,watch_list };
	Validators validator{};
	Ui ui{ controller,user_controller,validator};
	//ui.populate_tutorials_list();
	ui.start();
	//test_all();
	return 0;
}