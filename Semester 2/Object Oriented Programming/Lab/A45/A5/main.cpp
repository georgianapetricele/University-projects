#include <iostream>
#include "Ui.h"
#include "Tests.h"
#include <crtdbg.h>
#define _CRTDBG_MAP_ALLOC

using namespace std;

int main()
{
	Repository repo{};
	Repository watch_list{};

	Controller controller{ repo };
	UserController user_controller{ repo, watch_list};
	Ui ui{ controller,user_controller};
	ui.populate_tutorials_list();
	ui.start();
	//test_all();
	_CrtDumpMemoryLeaks();
	return 0;
}