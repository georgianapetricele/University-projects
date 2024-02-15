#include "Service.h"
#include "algorithm"
#include "Observer.h"
#include "assert.h"

Service::Service(Repo& repo) : repo{ repo }
{
}

Service::~Service()
{
}

vector<Programmer> Service::getProgrammers()
{
	return this->repo.getProgrammers();
}

bool compare(Task t1, Task t2)
{
	return t1.getStatus() < t2.getStatus();
}

vector<Task> Service::getTasks()
{
	vector<Task> tasks = this->repo.getTasks();
	sort(tasks.begin(), tasks.end(), compare);
	return tasks;
}

void Service::add_task(Task& task)
{
	this->repo.add_task(task);
	notify();
}

void Service::remove_task_with_description(string description)
{
	Task new_task = Task(description, "", 0);
	this->repo.remove_task(new_task);
	notify();
}

void test_remove_task()
{
	Repo repo = Repo("programmers.txt", "tasks.txt");
	Service service = Service(repo);
	service.remove_task_with_description("task1");
	assert(service.getTasks().size() == 2);
}