#pragma once
#include <vector>
#include "ScreenWriter.h"
#include "Idea.h"

using namespace std;
class Repository
{
	private:
	vector<ScreenWriter> screenwriters;
	vector<Idea> ideas;
public:
	Repository()
	{
		read_from_files();
	}
	~Repository() {}
	void read_from_files();
	vector<ScreenWriter> get_screenwriters();
	vector<Idea> get_ideas();
	void add_idea(Idea& idea);
	void update_idea_status(Idea& idea)
	{
		for (int i = 0; i < ideas.size(); i++)
			if (ideas[i] == idea)
				ideas[i].setStatus("accepted");
	}
};

