#include "Service.h"

void Service::add_star(string name, string constellation, int RA, int Dec, int diameter)
{
	if(name=="")
		throw exception("Name cannot be empty!");
	Star star{ name,constellation,RA,Dec,diameter };
	this->repo.add_star(star);
}