#include <Windows.h>
#include "CSVRepository.h"
#include <fstream>
#include <QProcess>
#include <QStringList>
#include <QUrl>

CSVRepository::CSVRepository()
{
}

CSVRepository::~CSVRepository()
{
}

void CSVRepository::write_to_file()
{
	ofstream fout("watchlist.csv");
	if (fout.is_open())
	{
		for (auto tutorial : this->dynamic_array)
			fout << tutorial.get_title() << "," << tutorial.get_presenter() << "," << tutorial.get_duration_minutes() << "," << tutorial.get_duration_seconds() << "," << tutorial.get_number_likes() << "," << tutorial.get_link() << "\n";
	}
	fout.close();
}

void CSVRepository::open_in_given_app()
{
	QStringList arguments;
	string file_path = "C:\\Users\\petri\\OneDrive\\Documente\\GitHub\\a89-georgianapetricele\\QtWidgetsApplication1\\QtWidgetsApplication1\\watchlist.csv";
	arguments << QString::fromStdString(file_path);
	QProcess::startDetached("notepad.exe", arguments);
	//system(R"(explorer.exe C:\Users\petri\OneDrive\Documente\GitHub\a7-georgianapetricele-1\A7\A7\watchlist.csv)");
}