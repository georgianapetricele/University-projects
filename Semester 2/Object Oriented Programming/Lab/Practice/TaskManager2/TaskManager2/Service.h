#pragma once
#include <string>
#include <vector>
#include "Programmer.h"
#include "Repo.h"
#include "Observer.h"

class Service: public Subject
{
private:
	Repo& repo;
public:
	Service(Repo& repo);
	~Service();
	vector<Programmer> getProgrammers();
	vector<Task> getTasks();
	void add_task(Task& task);
	void remove_task_with_description(string description);
};

