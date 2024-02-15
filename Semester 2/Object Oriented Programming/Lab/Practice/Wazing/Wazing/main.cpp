#include "Gui.h"
#include <QtWidgets/QApplication>
#include "Service.h"
#include "Driver.h"
#include "Repository.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Repository repo;
    Service service{ repo };
    vector<Gui*> guis;
    for (auto driver : service.getDrivers())
    {
		Gui* gui = new Gui{ service,driver };
        guis.push_back(gui);
	}
    for (auto gui : guis)
		gui->show();
    return a.exec();
}
