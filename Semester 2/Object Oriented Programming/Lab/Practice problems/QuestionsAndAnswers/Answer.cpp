#include "Answer.h"
#include <string>
#include <sstream>

using namespace std;

Answer::Answer()
{
}

Answer::Answer(int id, int id_question, string user_name, string text,  int votes)
{
	this->id = id;
	this->id_question = id_question;
	this->user_name = user_name;
	this->text = text;
	this->votes = votes;
}

Answer::~Answer()
{
}

string Answer::toString()
{
	return to_string(this->id) + " " + to_string(this->id_question) + " "  + this->user_name + " "+ this->text + " " + to_string(this->votes);
}

vector<string> tokenize_answer(string str, char delimiter)
{
	vector<string> result;
	stringstream ss(str);
	string token;
	while (getline(ss, token, delimiter))
		result.push_back(token);
	return result;
}

istream& operator>>(istream& is, Answer& a)
{
	string line;
	getline(is, line);
	vector<string> tokens = tokenize_answer(line, ',');
	if (tokens.size() != 5)
		return is;
	a.id = stoi(tokens[0]);
	a.id_question = stoi(tokens[1]);
	a.user_name = tokens[2];
	a.text = tokens[3];
	a.votes = stoi(tokens[4]);
	return is;
}
