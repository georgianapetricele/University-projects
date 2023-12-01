#include "HTMLRepository.h"
#include "Repo.h"
#include <fstream>
#include <windows.h>
#include <shellapi.h>
HTMLRepository::HTMLRepository(): Repository(this->file_name)
{
}

HTMLRepository::~HTMLRepository()
{
}

void HTMLRepository::write_to_file() 
{
	ofstream fout("watchlist.html");
	fout << "<!DOCTYPE html>\n";
	fout << "<html>\n";
	fout << "<head>\n";
	fout << "<title>Tutorials</title>\n";
	fout << "</head>\n";
	fout << "<body>\n";
	fout << "<table border=\"1\">\n";
	fout << "<tr>\n";
	fout << "<td>Title</td>\n";
	fout << "<td>Presenter</td>\n";
	fout << "<td>Duration</td>\n";
	fout << "<td>Likes</td>\n";
	fout << "<td>Link</td>\n";
	fout << "</tr>\n";
	for(auto tutorial : this->dynamic_array)
	{
		fout << "<tr>\n";
		fout << "<td>" << tutorial.get_title() << "</td>\n";
		fout << "<td>" << tutorial.get_presenter() << "</td>\n";
		fout << "<td>" << tutorial.get_duration_minutes() << "</td>\n";
		fout << "<td>" << tutorial.get_duration_seconds() << "</td>\n";
		fout << "<td>" << tutorial.get_number_likes() << "</td>\n";
		fout << "<td><a href = \"" << tutorial.get_link() << "\">Link</a></td>\n";
		fout << "</tr>\n";
	}
	fout << "</table>\n";
	fout << "</body>\n";
	fout << "</html>\n";
	fout.close();
}	

void HTMLRepository::open_in_given_app()
{
	system(R"(explorer.exe C:\Users\petri\OneDrive\Documente\GitHub\a7-georgianapetricele-1\A7\A7\watchlist.html)");
}
