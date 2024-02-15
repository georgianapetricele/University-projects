#include "Service.h"

Service::Service()
{
	
}

vector<Document> Service::get_documents()
{
	return this->documents;
}

void Service::read_from_file()
{
	ifstream file("documents.txt");
	Document document;
	while (file >> document)
	{
		this->documents.push_back(document);
	}
}


Document Service::compute_best_matching(string given_name)
{
	int max_length = -100;
	Document document_to_show;
	documents = this->get_documents();
	for (Document document : documents)
	{
		int length_searched = given_name.length();
		int length_document = document.get_name().length();
		if (length_searched / length_document > max_length)
		{
			max_length = length_searched / length_document;
			document_to_show = document;
		}
	}
	return document_to_show;
}