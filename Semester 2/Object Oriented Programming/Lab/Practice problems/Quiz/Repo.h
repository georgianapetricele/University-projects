#pragma once
#pragma once
#include <vector>
#include "Participant.h"
#include "Question.h"

using namespace std;
class Repository
{
private:
	vector<Question> questions;
	vector<Participant> participants;
	string file_qustions, file_participants;
public:
	Repository();
	Repository(string file_questions, string file_participants);
	~Repository();
	vector<Question> getQuestions();
	vector<Participant> getParticipants();
	void read_from_file();
	void addQuestion(Question question);
};

