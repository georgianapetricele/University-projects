#include <iostream>
#include "Ui.h"
#include <crtdbg.h>
#include "Tests.h"
#define _CRTDBG_MAP_ALLOC

using namespace std;

int main()
{
	Ui ui;
	ui.populate_tutorials_list();
	ui.start();
	//test_all();
	_CrtDumpMemoryLeaks();

	return 0;
}