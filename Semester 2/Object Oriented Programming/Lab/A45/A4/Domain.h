#pragma once
#include <cstring>
#include <string>

using namespace std;

struct Duration
{
	int minutes,seconds;
};

class Tutorial
{
private:
	string title, presenter, link;
	Duration duration;
	int number_likes;
public:

	Tutorial(string title, string presenter, struct Duration duration, int number_likes, string link);

	Tutorial();

	~Tutorial();

	string get_title() const;

	string get_presenter() const;

	int get_number_likes() const;

	int get_duration_minutes() const;

	int get_duration_seconds() const;

	void set_presenter(string new_presenter);

	string get_link() const;

	string convert_to_string();
};