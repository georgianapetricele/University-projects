#pragma once
#include "Utils.h"
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Idea
{
private:
	string description, status, creator, act;
public:
	Idea();
	Idea(string desc, string status, string creator, string act) :description(desc), status(status),
		creator(creator), act(act) {}
	~Idea();
public:
	string getDescription() const;
	void setDescription(string description);

	string getStatus() const;
	void setStatus(string status);

	string getCreator() const;
	void setCreator(string creator);

	string getAct() const;
	void setAct(string act);

	string toString();

	vector<string> tokenize(string input)
	{
		stringstream stream(input);
		vector<string> tokens;
		string token;
		while (getline(stream, token, ','))
			tokens.push_back(token);
		return tokens;
	}

	bool operator==(const Idea& idea)
	{
		if (idea.act == this->act && idea.description == this->description)
			return true;
		return false;
	}

	friend istream& operator>>(istream& stream, Idea& idea)
	{
		string input;
		getline(stream, input);
		vector<string> tokens = idea.tokenize(input);
		if (tokens.size() != 4)
			return stream;
		idea.description = tokens[0];
		idea.status = tokens[1];
		idea.creator = tokens[2];
		idea.act = tokens[3];

		return stream;
	}
};
