#pragma once
#include <vector>
#include "Programmer.h"
#include "Task.h"

using namespace std;

class Repo
{
	private:
	vector<Programmer> programmers;
	vector<Task> tasks;
	string file_programmers,file_tasks;
	public:
		Repo();
		Repo(string file_programmers,string file_tasks);
		~Repo();
		void add_task(Task& task);
		void remove_task(Task& task);
		vector<Programmer> getProgrammers();
		vector<Task> getTasks();
		void read_from_file();
};

