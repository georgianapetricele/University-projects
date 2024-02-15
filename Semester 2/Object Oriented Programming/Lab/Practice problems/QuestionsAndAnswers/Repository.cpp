#include "Repository.h"

#include <fstream>

Repository::Repository()
{
	this->read_from_files();
}

Repository::~Repository()
{
}

void Repository::add_question(Question q)
{
	this->questions.push_back(q);
}

void Repository::add_answer(Answer a)
{
	this->answers.push_back(a);
}

vector<Question> Repository::get_questions()
{
	return this->questions;
}

vector<User> Repository::get_users()
{
	return this->users;
}

vector<Answer> Repository::get_answers()
{
	return this->answers;
}

void Repository::read_from_files()
{
	ifstream questions_file("questions.txt");
	Question q;
	while (questions_file >> q)
		this->questions.push_back(q);
	questions_file.close();
	ifstream users_file("users.txt");
	User u;
	while (users_file >> u)
		this->users.push_back(u);
	users_file.close();
	ifstream answers_file("answers.txt");
	Answer a;
	while (answers_file >> a)
		this->answers.push_back(a);
	answers_file.close();
}