#pragma once
#include "Repository.h"
#include <vector>
#include <string>
#include "ScreenWriter.h"
#include "Idea.h"
class Service
{
private:
	Repository& repo;
public:
	Service(Repository& repo) :repo{ repo } {}
	~Service() {}
	vector<ScreenWriter> getWriters() const;
	vector<Idea> getIdeas() const;
	void addIdea(string description,string creator,string act);
	void update_idea_status(Idea& idea)
	{
		this->repo.update_idea_status(idea);
	}
};

