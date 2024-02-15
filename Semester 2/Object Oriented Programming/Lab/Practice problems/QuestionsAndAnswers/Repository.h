#pragma once
#include <string>
#include <vector>
#include "Question.h"
#include "User.h"
#include "Answer.h"

class Repository
{
private:
	vector<Question> questions;
	vector<User> users;
	vector<Answer> answers;
public:
	Repository();
	~Repository();
	void add_question(Question q);
	void add_answer(Answer a);
	vector<Question> get_questions();
	vector<User> get_users();
	vector<Answer> get_answers();
	void read_from_files();
	
};

