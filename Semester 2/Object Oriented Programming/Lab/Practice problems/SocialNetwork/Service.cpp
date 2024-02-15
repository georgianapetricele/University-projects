#include "Service.h"
#include <algorithm>

void Service::read_from_files()
{
	this->repo.read_from_files();
}

bool compare(Post p1, Post p2)
{
	if (p1.getYear() == p2.getYear())
	{
		if (p1.getMonth() == p2.getMonth())
		{
			if (p1.getDay() == p2.getDay())
			{
				if (p1.getHour() == p2.getHour())
				{
					return p1.getMinute() > p2.getMinute();
				}
				return p1.getHour() > p2.getHour();
			}
			return p1.getDay()  > p2.getDay();
		}
		return p1.getMonth() >  p2.getMonth();
	}
	return p1.getYear() > p2.getYear();
}

vector<Post> Service::get_posts_for_user(string username)
{
	vector<Post> posts = this->repo.getPosts();
	vector<Post> posts_for_user;
	for (auto post : posts)
	{
		
			posts_for_user.push_back(post);
	}
	sort(posts_for_user.begin(), posts_for_user.end(), compare);

	return posts_for_user;
}

vector<Topic> Service::get_topics_for_user(string username)
{
	vector<Topic> topics = this->repo.getTopics();
	vector<Topic> topics_for_user;
	for (auto topic : topics)
	{
		if (topic.search_for_user(username))
				topics_for_user.push_back(topic);
	}
	return topics_for_user;
}

void Service::add_post(string text, int year, int month, int day, int hour, int minute, string username)
{
	Post post(text, year, month, day, hour, minute, username);
	this->repo.addPost(post);
	this->notify();
}