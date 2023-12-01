#include "Domain.h"
#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
#include <sstream>

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

bool Tutorial::operator==(const Tutorial& given_tutorial)
{
	if (this->title == given_tutorial.get_title())//&& this->duration.minutes == given_tutorial.get_duration_minutes() && this->duration.seconds == given_tutorial.get_duration_seconds() && this->number_likes == given_tutorial.number_likes && this->link == given_tutorial.link)
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

vector<string> tokenize(string given_string, char delimiter)
{
	vector<string> current_tutorial_parameters;
	stringstream string_stream(given_string);
	string tutorial_current_token;
	while (getline(string_stream, tutorial_current_token, delimiter))
		current_tutorial_parameters.push_back(tutorial_current_token);
	return current_tutorial_parameters;
}

istream& operator>>(istream& input_stream, Tutorial& given_tutorial)
{
	string line;
	getline(input_stream, line);
	vector<string> tokens = tokenize(line, ',');
	if (tokens.size() != 6)
		return input_stream;
	given_tutorial.title = tokens[0];
	given_tutorial.presenter = tokens[1];
	given_tutorial.duration.minutes = stoi(tokens[2]);
	given_tutorial.duration.seconds = stoi(tokens[3]);
	given_tutorial.number_likes = stoi(tokens[4]);
	given_tutorial.link = tokens[5];

	return input_stream;
}

ostream& operator<<(ostream& output_stream, const Tutorial& given_tutorial)
{
	output_stream << given_tutorial.get_title() << "," << given_tutorial.get_presenter() << "," << given_tutorial.get_duration_minutes() << "," << given_tutorial.get_duration_seconds() << "," << given_tutorial.get_number_likes() << "," << given_tutorial.get_link() << "\n";
	return output_stream;
}

string Tutorial::convert_to_string()
{
	string convert_string = "\nTutorial: " + this->title + " | Presenter: " + this->presenter + " | Duration: " + to_string(this->duration.minutes) + " minutes and " + to_string(this->duration.seconds) + " seconds " + " | Likes: " + to_string(this->number_likes) + " | Link : " + this->link;
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