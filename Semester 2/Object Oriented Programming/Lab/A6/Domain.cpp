#include "Domain.h"
#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>

using namespace std;

Tutorial::Tutorial(string title, string presenter, Duration duration, int number_likes, string link)
{
	this->title = title;
	this->presenter = presenter;
	this->duration.minutes = duration.minutes;
	this->duration.seconds = duration.seconds;
	this->number_likes = number_likes;
	this->link = link;
}

bool Tutorial::operator==(const Tutorial & given_tutorial)
{
	if (this->title == given_tutorial.get_title() )//&& this->duration.minutes == given_tutorial.get_duration_minutes() && this->duration.seconds == given_tutorial.get_duration_seconds() && this->number_likes == given_tutorial.number_likes && this->link == given_tutorial.link)
		return true;
	return false;
}

Tutorial::Tutorial() {
	this->title = "";
	this->presenter = "";
	this->duration.minutes = 0;
	this->duration.seconds = 0;
	this->number_likes = 0;
	this->link = "";
}

string Tutorial::convert_to_string()
{
	string convert_string = "\nTutorial: " + this->title + " | Presenter: " + this->presenter + " | Duration: " + to_string(this->duration.minutes) + " minutes and " + to_string(this->duration.seconds) + " seconds " +
		+"\nLikes: " + to_string(this->number_likes) + " | Link : " + this->link + "\n";
	return convert_string;
}

string Tutorial::get_title() const
{
	return this->title;
}

string Tutorial::get_presenter() const
{
	return this->presenter;
}

string Tutorial::get_link() const
{
	return this->link;
}

int Tutorial::get_duration_minutes() const
{
	return this->duration.minutes;
}


int Tutorial::get_duration_seconds() const
{
	return this->duration.seconds;
}

int Tutorial::get_number_likes() const
{
	return this->number_likes;
}

void Tutorial::set_presenter(string new_presenter)
{
	this->presenter = new_presenter;
}

void Tutorial::set_number_likes(int number_likes)
{
	Tutorial::number_likes = number_likes;
}