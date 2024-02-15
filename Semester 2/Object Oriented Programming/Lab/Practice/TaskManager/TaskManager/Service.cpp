#include "Service.h"
#include <fstream>
#include <algorithm>


Service::Service()
{
}

Service::~Service()
{
}

vector<Task> Service::get_all_tasks()
{
	return this->tasks;
}

bool cmp(Task task1, Task task2)
{
	if(task1.getPriority() == task2.getPriority())
		return task1.getDuration() > task2.getDuration();
	return task1.getPriority() < task2.getPriority();
}

vector<Task> Service::get_all_tasks_sorted()
{
	vector<Task> tasks = this->tasks;
	sort(tasks.begin(), tasks.end(),cmp);
	return tasks;
}

void Service::read_from_file()
{
	ifstream file("tasks.txt");
	Task task;
	while(file>>task)
		this->tasks.push_back(task);
	
	file.close();
}