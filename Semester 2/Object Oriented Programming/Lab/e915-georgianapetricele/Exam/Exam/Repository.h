#pragma once
#include <vector>
#include <string>
#include "Researcher.h"
#include "Idea.h"
#include <algorithm>

using namespace std;
class Repository
{
private:
	vector<Researcher> researchers;
	vector<Idea> ideas;
public:
	Repository();
	~Repository();
	vector<Researcher> get_researchers()
	{
		return researchers;
	}

	vector<Idea> get_ideas();
	void read_from_files();
	void add_idea(Idea idea)
	{
		ideas.push_back(idea);
	}

	void update_idea(Idea idea);
	void load_ideas_to_file();
	bool has_accepted_ideas(Researcher researcher);
	vector<Idea> get_ideas_for_researcher(string name);
	void update_ideas_description(string title, string description)
	{
		for (int index = 0; index < ideas.size(); index++)
			if (ideas[index].get_title() == title)
				ideas[index].description = description;
	}
};

