#pragma once
#include "Repo.h"
#include <algorithm>

class Service
{
private:
	Repo& repo;
public:
	Service(Repo& repo) :repo{ repo } {}
	~Service() {}
	vector<Star> getStars()
	{
		vector<Star> stars = repo.getStars();
		sort(stars.begin(), stars.end(), [](Star s1, Star s2) {return s1.getConstellation() < s2.getConstellation(); });
		return stars;
	}
	vector<Astronomer> getAstronomers() { return repo.getAstronomers(); }

	void add_star(string name, string constellation, int RA, int Dec, int diameter);
	vector<Star> getStars_on_costelation(string constellation)
	{
		vector<Star> stars;
		for (auto star : stars)
			if (star.getConstellation() == constellation)
				stars.push_back(star);
		return stars;
	}
	string get_astronomer_constellation(string name)
	{
		return repo.get_astronomer_constellation(name);
	}
};

