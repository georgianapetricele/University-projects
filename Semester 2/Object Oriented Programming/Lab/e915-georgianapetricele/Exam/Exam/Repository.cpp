#include "Repository.h"
#include <fstream>


Repository::Repository()
{
	read_from_files();
}

Repository::~Repository()
{

}

void Repository::read_from_files()
{
	ifstream file("researchers.txt");
	Researcher researcher;
	while (file >> researcher)
		researchers.push_back(researcher);
	file.close();
	ifstream file2("ideas.txt");
	Idea idea;
	while (file2 >> idea)
		ideas.push_back(idea);
	file2.close();
}
bool compare(Idea i1, Idea i2)
{
	return i1.get_duration() < i2.get_duration();
}
vector<Idea> Repository::get_ideas()
{
	
		sort(ideas.begin(), ideas.end(), compare);
		return ideas;
}

void Repository::update_idea(Idea idea)
{
	for (int index = 0; index < ideas.size(); index++)
		if (ideas[index].get_title() == idea.get_title() && ideas[index].get_status() == "proposed")
			ideas[index].status = "accepted";
}

void Repository::load_ideas_to_file()
{
	
	ofstream file_output("output.txt");
	for (auto idea : ideas)
	{

		if (idea.get_status() == "accepted")
		file_output << idea;
	}
	file_output.close();
}

bool Repository::has_accepted_ideas(Researcher researcher)
{
	bool is_researcher = false;
	for(auto idea: ideas)
		if (researcher.get_name() == idea.get_creator())
			is_researcher = true;
	if(is_researcher == false)
		return false;
	for (auto idea : ideas)
		if (idea.get_creator() == researcher.get_name() && idea.get_status() == "accepted")
			return true;
	return false;
}

vector<Idea> Repository::get_ideas_for_researcher(string name)
{
	vector<Idea> ideas_for_researcher;
	for (auto idea : ideas)
		if (idea.get_creator() == name)
			ideas_for_researcher.push_back(idea);
	return ideas_for_researcher;
}

