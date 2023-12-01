#pragma once
#include <cstring>
#include <string>
#include <vector>

using namespace std;

struct Duration
{
	int minutes, seconds;
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

	string get_title() const;

	string get_presenter() const;

	int get_number_likes() const;

	int get_duration_minutes() const;

	int get_duration_seconds() const;

	void set_presenter(string new_presenter);

	void set_number_likes(int new_number);

	string get_link() const;

	vector<string> tokenize(string given_string, char delimiter);

	friend istream& operator>>(istream& input_stream, Tutorial& given_tutorial);

	friend ostream& operator<<(ostream& output_stream, const Tutorial& given_tutorial);

	bool operator==(const Tutorial& given_tutorial);

	string convert_to_string();
};