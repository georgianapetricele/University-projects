#include "gui.h"
#include <QtWidgets/QApplication>
#include "Searchgui.h"
#include "Observer.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Repository repo;
    Service service{ repo };
    vector<gui*> windows;
    Searchgui search{ service };
    search.show();
    for (auto user : service.get_users_service())
    {
       gui* new_gui =  new gui{ user,service };
       windows.push_back(new_gui);
       service.add_observer(new_gui);
    }
    for (auto window : windows)
        window->show();
    return a.exec();
}
