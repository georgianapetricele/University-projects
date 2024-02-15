#include <iostream>
#include "Ui.h"

using namespace std;

int main()
{
	Agency agency;

	Ui ui(agency);
	ui.start();
	return 0;
}