#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

class Document
{
private:
	string name, keywords, content;
public:
	Document();
	Document(string name, string keywords, string content);
	string get_name();
	string get_keywords();
	string get_content();
	friend istream& operator>>(istream& is, Document& document);
	string toString();
	~Document(){}
};

