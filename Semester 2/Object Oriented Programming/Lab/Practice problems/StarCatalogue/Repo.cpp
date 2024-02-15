#include "Repo.h"
#include <fstream>



void Repo::read_from_files()
{
	ifstream file_stars("stars.txt");
	Star star;
	while(file_stars >> star)
		this->stars.push_back(star);
	file_stars.close();

	ifstream file_astronomers("astronomers.txt");
	Astronomer astronomer;
	while (file_astronomers >> astronomer)
		this->astronomers.push_back(astronomer);
	file_astronomers.close();
}

void Repo::add_star(Star star)
{
	this->stars.push_back(star);
}