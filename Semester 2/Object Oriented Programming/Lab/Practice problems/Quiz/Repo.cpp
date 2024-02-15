#include "Repo.h"
#include <fstream>

Repository::Repository()
{
	file_qustions = "";
	file_participants = "";
	read_from_file();
}

Repository::Repository(string file_questions, string file_participants)
{
	this->file_qustions = file_questions;
	this->file_participants = file_participants;
	read_from_file();
}

Repository::~Repository()
{
}

vector<Question> Repository::getQuestions()
{
	return this->questions;
}

vector<Participant> Repository::getParticipants()
{
	return this->participants;
}

void Repository::read_from_file()
{
	ifstream file1(file_qustions);
	ifstream file2(file_participants);
	if (!file1.eof())
	{
		Question question;
		while (file1 >> question)
			this->questions.push_back(question);
		file1.close();
	}
	if (!file2.eof())
	{
		Participant participant;
		while (file2 >> participant)
			this->participants.push_back(participant);
		file2.close();
	}

}

void Repository::addQuestion(Question question)
{
	for(auto q:this->questions)
		if (q.getId() == question.getId())
			throw exception("Question already exists!");
	this->questions.push_back(question);
}