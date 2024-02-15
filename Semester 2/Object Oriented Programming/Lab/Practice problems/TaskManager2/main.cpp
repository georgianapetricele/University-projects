#include "TaskManager2.h"
#include <QtWidgets/QApplication>
#include <vector>
#include "Repo.h"
#include "Service.h"

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Repo repo{ "programmers.txt", "tasks.txt"};
    Service service{ repo };

    vector<TaskManager2*> windows;
    for (auto programmer : service.getProgrammers())
    {
        TaskManager2* window = new TaskManager2{ programmer, service };
		windows.push_back(window);
        service.addObserver(window);
	}
    for (auto window : windows)
		window->show();
    	return a.exec();
}
