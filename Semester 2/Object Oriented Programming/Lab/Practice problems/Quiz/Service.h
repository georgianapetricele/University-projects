#pragma once
#include "Repo.h"
#include "Observer.h"
class Service: public Subject
{
private:
	Repository& repo;
public:
	Service(Repository& repo);
	~Service();
	vector<Question> getQuestions();
	vector<Question> getQuestions_descending();
	vector<Participant> getParticipants();
	void addQuestion(int id, string text, string answer, int score);
	void read_from_file();
};

