#include "Gui.h"
#include <QtWidgets/QApplication>
#include "Repository.h"
#include "Service.h"
#include "Model.h"
#include "Gui.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Repository repo;
    Service service{ repo };
    Model* model = new Model{ service };
    vector<Gui*> guis;
    for (auto researcher : service.get_researchers())
    {
        Gui* gui = new Gui{ researcher,model };
		guis.push_back(gui);
    }
    for (auto gui : guis)
        gui->show();
    return a.exec();
}
