#pragma once
#include <string>
#include <vector>

using namespace std;
class Idea
{
private:
	string title, creator;
	int duration;
public:
	string status, description;
	Idea()
	{
		this->title = "";
		this->description = "";
		this->status = "";
		this->creator = "";
		this->duration = 0;
	}

	string get_title()
	{
		return title;
	}

	string get_description()
	{
		return description;
	}

	string get_status()
	{
		return status;
	}
	string get_creator()
	{
		return creator;
	}

	int get_duration()
	{
		return duration;
	}

	void set_title(string title)
	{
		this->title = title;
	}

	void set_description(string description)
	{
		this->description = description;
	}

	void set_status(string status)
	{
		this->status = status;
	}

	void set_creator(string creator)
	{
		this->creator = creator;
	}

	void set_duration(int duration)
	{
		this->duration = duration;
	}



	Idea(string title, string description, string status, string creator, int duration)
	{
		this->title = title;
		this->description = description;
		this->status = status;
		this->creator = creator;
		this->duration = duration;
	}
	~Idea();
	friend istream& operator>>(istream& is, Idea& idea);
	friend ostream& operator<<(ostream& os, Idea& idea);

	string to_string()
	{
		return this->title + "," + this->description + "," + this->status + "," + this->creator + "," + std::to_string(this->duration);
	}
};

