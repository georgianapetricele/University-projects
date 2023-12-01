#pragma once
#include "Repository.h"
class Service
{
private:
	Repository& repo;
public:
	Service(Repository& repo) : repo{ repo } {}
	~Service() {}
	vector<Researcher> get_researchers()
	{
		return repo.get_researchers();
	}
	vector<Idea> get_ideas()
	{
		return repo.get_ideas();
	}
	void read_from_files()
	{
		repo.read_from_files();
	}
	
	void add_idea(string title, string description, string status, string creator, int duration)
	{
		if(title == "")
			throw exception("Title cannot be empty!");
		if (duration != 1 && duration != 2 && duration != 3)
			throw exception("Duration must be 1, 2 or 3!");
		Idea idea{ title, description, status, creator, duration };
		repo.add_idea(idea);
	}

	void update_idea(Idea idea)
	{
		repo.update_idea(idea);
	}
	
	void load_ideas_to_file()
	{
		repo.load_ideas_to_file();
	}

	bool has_accepted_ideas(Researcher researcher)
	{
		return repo.has_accepted_ideas(researcher);
	}

	vector<Idea> get_ideas_for_researcher(string name)
	{
		return repo.get_ideas_for_researcher(name);
	}

	void update_ideas_description(string title, string description)
	{
		repo.update_ideas_description(title, description);
	}
};

