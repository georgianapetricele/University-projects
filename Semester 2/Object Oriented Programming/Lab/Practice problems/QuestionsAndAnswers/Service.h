#pragma once
#include "Repository.h"
#include "User.h"
#include "Question.h"
#include "Answer.h"

#include "Observer.h"
class Service: public Subject
{
private:
	Repository& repo;
public:
	Service(Repository& repo) : repo(repo) {}
	~Service();
	void add_question(int id, string text, string user_name);
	vector<User> get_users_service();
	vector<Question> get_questions_descending();
	vector<Answer> get_answers_service();
	int get_number_answers(Question q);
	bool compare(Question q1, Question q2);
	string get_best_matching_question(string question);
	vector<Answer> get_answers_to_question(Question question);

};

