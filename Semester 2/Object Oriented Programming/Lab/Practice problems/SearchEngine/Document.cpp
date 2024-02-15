#include "Document.h"

Document::Document()
{
	this->name = "";
	this->keywords = "";
	this->content = "";
}

Document::Document(string name, string keywords, string content)
{
	this->name = name;
	this->keywords = keywords;
	this->content = content;
}

string Document::get_name()
{
	return this->name;
}

string Document::get_keywords()
{
	return this->keywords;
}

string Document::get_content()
{
	return this->content;
}

//tokenize
vector<string> tokenize(string str, char delimiter)
{
	vector<string> result;
	stringstream ss(str);
	string token;
	while (getline(ss, token, delimiter))
		result.push_back(token);
	return result;
}

istream& operator>>(istream& is, Document& document)
{
	string line;
	getline(is, line);
	vector<string> tokens = tokenize(line,'|');
	if (tokens.size() != 3)
		return is;
	document.name = tokens[0];
	document.keywords = tokens[1];
	document.content = tokens[2];

	return is;
}

string Document::toString()
{
		return this->name + " | " + this->keywords + " | " + this->content;
}