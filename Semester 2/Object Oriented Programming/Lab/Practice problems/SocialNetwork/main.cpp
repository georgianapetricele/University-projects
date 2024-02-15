#include "Gui.h"
#include <QtWidgets/QApplication>
#include "Service.h"
#include "User.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Repo repo;
    Service service{ repo };
    vector<Gui*> guis;
    for (auto user : service.getUsers())
    {
        Gui* gui = new Gui{ service,user };
        guis.push_back(gui);
        service.addObserver(gui);
			
    }
    for(auto gui: guis)
        gui->show();
    return a.exec();
}
