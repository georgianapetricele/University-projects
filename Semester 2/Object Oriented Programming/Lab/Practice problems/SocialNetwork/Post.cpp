#include "Post.h"

Post::Post()
{
}

Post::~Post()
{
}

vector<string> tokenize2(string str, char delimiter)
{
	vector<string> result;
	stringstream ss(str);
	string token;
	while (getline(ss, token, delimiter))
		result.push_back(token);
	return result;
}

istream& operator>>(istream& is, Post& post)
{
	string line;
	getline(is, line);
	vector<string> tokens = tokenize2(line, ',');
	if(tokens.size() != 7)
		return is;
	post.text = tokens[0];
	post.day = stoi(tokens[1]);
	post.month = stoi(tokens[2]);
	post.year = stoi(tokens[3]);
	post.hour = stoi(tokens[4]);
	post.minute = stoi(tokens[5]);
	post.user = tokens[6];
	return is;
}

ostream& operator<<(ostream& os, Post& post)
{
	os << post.text << "," << post.day << "," << post.month << "," << post.year << "," << post.hour << "," << post.minute << "," << post.user;
	return os;
}

string Post::toString()
{
	return this->text + "," + to_string(this->day) + "," + to_string(this->month) + "," + to_string(this->year) + "," + to_string(this->hour) + "," + to_string(this->minute) + "," + this->user;
}