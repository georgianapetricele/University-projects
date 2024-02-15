#include "Repo.h"
#include <fstream>

#include <sstream>
#include <iostream>

using namespace std;

Repo::Repo()
{
	read_from_files();
}

Repo::~Repo()
{
}


void Repo::read_from_files()
{
	ifstream file1("users.txt");
	ifstream file2("topics.txt");
	ifstream file3("posts.txt");
	User user;
	Topic topic;
	Post post;
	while (file1 >> user)
		this->users.push_back(user);
	while (file2 >> topic)
		this->topics.push_back(topic);
	while (file3 >> post)
		this->posts.push_back(post);
	file1.close();
	file2.close();
	file3.close();
}