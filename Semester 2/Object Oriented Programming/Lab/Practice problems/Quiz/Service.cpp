#include "Service.h"
#include <fstream>
#include <algorithm>
#include "Observer.h"

Service::Service(Repository& repo) : repo{ repo }
{
}

Service::~Service()
{
}

vector<Question> Service::getQuestions()
{
	vector<Question> questions =this->repo.getQuestions();
	sort(questions.begin(), questions.end(), [](Question q1, Question q2) {return q1.getScore() < q2.getScore(); });
	return questions;
}

vector<Question> Service::getQuestions_descending()
{
	vector<Question> questions = this->repo.getQuestions();
	sort(questions.begin(), questions.end(), [](Question q1, Question q2) {return q1.getScore()  > q2.getScore(); });
	return questions;
}

vector<Participant> Service::getParticipants()
{
	return this->repo.getParticipants();
}

void Service::read_from_file()
{
	this->repo.read_from_file();
}

void Service::addQuestion(int id, string text, string answer, int score)
{
	Question question{ id,text,answer,score };
	if(text == "")
		throw exception("Invalid text!");
	this->repo.addQuestion(question);
	this->notify();
}