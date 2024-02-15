#include "Gui.h"
#include <QtWidgets/QApplication>
#include "Service.h"
#include "Repository.h"
#include "Idea.h"
#include "ScreenWriter.h"

int main(int argc, char *argv[])
{
   QApplication a(argc, argv);
    Repository repo;
    Service service{ repo };
    Model* model = new Model{ service };
    vector<Gui*> guis;
    for (auto writer : service.getWriters())
    {
        Gui* gui = new Gui{ model,writer };
        guis.push_back(gui);
    }
    for (auto gui : guis)
    {
		gui->show();
	}
  
    return a.exec();
}
