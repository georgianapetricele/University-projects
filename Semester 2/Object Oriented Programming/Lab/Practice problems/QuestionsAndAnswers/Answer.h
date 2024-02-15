#pragma once
#include <string>
#include <vector>

using namespace std;
class Answer
{
private:
	int id,id_question,votes;
	string text, user_name;
public:
	Answer();
	Answer(int id, int id_question, string user_name, string text,int votes);
	int get_id()
	{
		return this->id;
	}
	int get_id_question()
	{
		return this->id_question;
	}
	string get_text()
	{
		return this->text;
	}
	string get_user_name()
	{
		return this->user_name;
	}
	int get_votes()
	{
		return this->votes;
	}
	string toString();
	~Answer();
	friend istream& operator>>(istream& is, Answer& a);
};

