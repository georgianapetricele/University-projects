#include "Gui.h"
#include <QtWidgets/QApplication>
#include "Star.h"
#include "Astronomer.h"
#include "Repo.h"
#include "Service.h"
#include "Model.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Repo repo;
    Service service{ repo };
    Model* model = new Model{ service };
    vector<Gui*> guis;
    for (auto astro : repo.getAstronomers())
    {
		Gui* gui = new Gui{ astro,model };
		guis.push_back(gui);
	}
    for (auto gui: guis)
        gui->show();
    return a.exec();
}
