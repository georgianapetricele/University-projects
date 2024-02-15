#include "Service.h"
#include <algorithm>
#include "Observer.h"


Service::~Service()
{
}

void Service::add_question(int id, string text, string user_name)
{
	if(text == "")
		throw exception("The text cannot be empty!");
	Question q{ id, text, user_name };
	this->repo.add_question(q);
	notify();
}

vector<User> Service::get_users_service()
{
	return this->repo.get_users();
}

vector<Answer> Service::get_answers_service()
{
	return this->repo.get_answers();
}

int Service::get_number_answers(Question q)
{
	int number = 0;
	for (Answer a : get_answers_service())
		if (a.get_id_question() == q.get_id())
			number++;
	return number;
}

bool Service::compare(Question q1, Question q2)
{
	return get_number_answers(q1) > get_number_answers(q1);
}

vector<Question> Service::get_questions_descending()
{
	vector<Question> questions = this->repo.get_questions();
	sort(questions.begin(), questions.end(), [this](Question q1, Question q2) {return this->compare(q1, q2); });
	return questions;
	
}

string Service::get_best_matching_question(string question)
{
	int nr = 0, maxi = -1;
	vector<Question> questions = this->get_questions_descending();
	for (Question q : questions)
	{
		nr = 0;
		int size=min(q.get_text().size(), question.size());
		for (int i = 0; i < size; i++)
			if (q.get_text()[i] == question[i])
				nr++;
		if (nr > maxi)
			maxi = nr;
	}
	for (Question q : questions)
	{
		nr = 0;
		int size = min(q.get_text().size(), question.size());
		for (int i = 0; i < size; i++)
			if (q.get_text()[i] == question[i])
				nr++;
		if (nr == maxi)
			return q.get_text();

	}
}

vector<Answer> Service::get_answers_to_question(Question question)
{
	vector<Answer> answers_to_question;
	for (Answer a : get_answers_service())
		if (a.get_id_question() == question.get_id())
			answers_to_question.push_back(a);
	return answers_to_question;
	notify();
}