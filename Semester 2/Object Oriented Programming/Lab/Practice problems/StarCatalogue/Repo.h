#pragma once
#include "Star.h"
#include "Astronomer.h"
class Repo
{
private:
	vector<Star> stars;
	vector<Astronomer> astronomers;
public:
	Repo() 
	{
		read_from_files();
	}
	Repo(vector<Star> stars, vector<Astronomer> astronomers) :stars{ stars }, astronomers{ astronomers } 
	{
		read_from_files();
	}
	vector<Star> getStars() { return stars; }
	vector<Astronomer> getAstronomers() { return astronomers; }
	~Repo() {}
	void read_from_files();
	void add_star(Star star);
	string get_astronomer_constellation(string name)
	{
		for (auto astro : astronomers)
				if (astro.getName() == name)
					return astro.getConstellation();
			return "";
	}
};

