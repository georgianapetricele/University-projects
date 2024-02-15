#include "Gui.h"
#include <QtWidgets/QApplication>
#include "Repo.h"
#include "Service.h"
#include "Presenter.h"
#include "Gui.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Repository repo{"questions.txt","participants.txt"};
    Service service{repo};
    Presenter presenter{service};
    presenter.show();
    vector<Gui*> guis;
    for (auto participant : service.getParticipants())
    {
		Gui* gui = new Gui{ service,participant };
		guis.push_back(gui);
        service.addObserver(gui);
	}
    for (auto gui : guis)
        gui->show();
    return a.exec();
}
