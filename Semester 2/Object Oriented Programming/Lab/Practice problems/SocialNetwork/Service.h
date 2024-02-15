#pragma once
#include "Repo.h"
#include "Observer.h"
class Service: public Subject
{
private:
	Repo& repo;
public:
	Service(Repo& repo) : repo(repo) {}
	~Service() {}
	//void addPost(Post post);
	void read_from_files();
	vector<User> getUsers() { return this->repo.getUsers(); }
	vector<Topic> getTopics() { return this->repo.getTopics(); }
	vector<Post> getPosts() { return this->repo.getPosts(); }
	vector<Post> get_posts_for_user(string username);
	vector<Topic> get_topics_for_user(string username);
	void add_post(string text,int year,int month,int day,int hour,int minute,string username);
};

