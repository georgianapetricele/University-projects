#pragma once
#include "Topic.h"
#include "User.h"
#include "Post.h"
#include <vector>

using namespace std;

class Repo
{
private:
	vector<User> users;
	vector<Topic> topics;
	vector<Post> posts;
public:
	Repo();
	~Repo();
	void read_from_files();
	vector<User> getUsers() { return this->users; }
	vector<Topic> getTopics() { return this->topics; }
	vector<Post> getPosts() { return this->posts; }
	void addPost(Post post)
	{
		this->posts.push_back(post);
	}

};

