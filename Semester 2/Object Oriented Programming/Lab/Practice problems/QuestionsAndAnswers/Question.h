#pragma once
#include <string>
#include <vector>

using namespace std;
class Question
{
private:
	int id;
	string text, user_name;
public:
	Question();
	Question(int id, string text, string user_name);
	int get_id();
	string get_text();
	string get_user_name();
	string toString();
	~Question();
	friend istream& operator>>(istream& is, Question& q);
};

