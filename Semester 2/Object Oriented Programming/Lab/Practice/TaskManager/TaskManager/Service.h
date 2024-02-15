#pragma once
#include <string>
#include <vector>
#include "Task.h"

using namespace std;

class Service
{
	private:
	vector<Task> tasks;
	public:
		Service();
		~Service();
		vector<Task> get_all_tasks();
		vector<Task> get_all_tasks_sorted();
		void read_from_file();
};

