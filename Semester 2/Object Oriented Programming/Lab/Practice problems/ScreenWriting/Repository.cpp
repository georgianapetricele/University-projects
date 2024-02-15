#include "Repository.h"
#include <fstream>
#include <algorithm>

vector<ScreenWriter> Repository::get_screenwriters()
{
	return this->screenwriters;
}

vector <Idea> Repository::get_ideas()
{
	sort(ideas.begin(), ideas.end(), [](Idea& idea1, Idea& idea2) {return idea1.getAct() < idea2.getAct(); });
	return this->ideas;
}

void Repository::add_idea(Idea& idea)
{
	auto iter = find(ideas.begin(), ideas.end(), idea);
	if (iter != ideas.end())
		throw std::exception("Idea already exists!");
	this->ideas.push_back(idea);
}
void Repository::read_from_files()
{
	ifstream file_writers("writers.txt");
	ScreenWriter writer;
	while (file_writers >> writer)
		screenwriters.push_back(writer);
	file_writers.close();

	ifstream file_ideas("ideas.txt");
	Idea idea;
	while (file_ideas >> idea)
		ideas.push_back(idea);
	file_ideas.close();
}