#include "Service.h"

vector<ScreenWriter> Service::getWriters() const
{
	return this->repo.get_screenwriters();
}

vector<Idea> Service::getIdeas() const
{
	return this->repo.get_ideas();
}

void Service::addIdea(string description, string creator, string act)
{
	string status = "proposed";
	if(description == "")
		throw std::exception("Description cannot be empty!");
	if(act != "1" && act != "2" && act != "3")
		throw std::exception("Act must be 1, 2 or 3!");
	Idea idea{ description,status,creator,act };
	this->repo.add_idea(idea);
}