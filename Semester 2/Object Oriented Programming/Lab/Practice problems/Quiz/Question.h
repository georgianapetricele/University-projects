
#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;
class Question
{
private:
	int id, score;
	string text, answer;
public:
	Question();
	Question(int id, string text, string answer, int score);
	~Question();
	int getId();
	string getText();
	string getAnswer();
	int getScore();
	string toString();
	//friend ostream& operator<<(ostream& os, const Question& q);
	friend istream& operator>>(istream& is, Question& q);
};

