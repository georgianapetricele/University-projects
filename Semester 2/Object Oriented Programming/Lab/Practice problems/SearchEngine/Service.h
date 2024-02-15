#pragma once
#include "Document.h"
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;
class Service
{
private:
	vector<Document> documents;
	public:
		Service();
		vector<Document> get_documents();
		void read_from_file();
		Document compute_best_matching(string text);
		~Service(){}

};

