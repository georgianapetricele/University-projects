#include "Question.h"

Question::Question()
{
	this->id = 0;
	this->text = "";
	this->answer = "";
	this->score = 0;
}

Question::Question(int id, string text, string answer, int score)
{
	this->id = id;
	this->text = text;
	this->answer = answer;
	this->score = score;
}

Question::~Question()
{
}

int Question::getId()
{
	return this->id;
}

string Question::getText()
{
	return this->text;
}

string Question::getAnswer()
{
	return this->answer;
}

int Question::getScore()
{
	return this->score;
}

string Question::toString()
{
	return to_string(this->id) + "," + this->text + "," + this->answer + "," + to_string(this->score);
}

vector<string> tokenize(string str, char delimiter)
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
	vector<string> tokens = tokenize(line, ',');
	if (tokens.size() != 4)
		return is;
	q.id = stoi(tokens[0]);
	q.text = tokens[1];
	q.answer = tokens[2];
	q.score = stoi(tokens[3]);
	return is;
}