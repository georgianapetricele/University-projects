#include "Question.h"
#include <string>
#include <vector>
#include <sstream>
using namespace std;

Question::Question()
{
}

Question::Question(int id, string text, string user_name)
{
	this->id = id;
	this->text = text;
	this->user_name = user_name;
}

int Question::get_id()
{
	return this->id;
}

string Question::get_text()
{
	return this->text;
}

string Question::get_user_name()
{
	return this->user_name;
}

Question::~Question()
{
}

string Question::toString()
{
	return to_string(this->id) + " " + this->text + " " + this->user_name;
}

vector<string> tokenize_question(string str, char delimiter)
{
	vector<string> result;
	stringstream ss(str);
	string token;
	while (getline(ss, token, delimiter))
		result.push_back(token);
	return result;
}

istream& operator>>(istream& is, Question& q)
{
	string line;
	getline(is, line);
	vector<string> tokens = tokenize_question(line, ',');
	if (tokens.size() != 3)
		return is;
	q.id = stoi(tokens[0]);
	q.text = tokens[1];
	q.user_name = tokens[2];
	return is;
}