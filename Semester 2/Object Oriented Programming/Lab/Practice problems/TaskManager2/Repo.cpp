#include "Repo.h"
#include <fstream>
#include <exception>
#include <assert.h>

Repo::Repo()
{
	this->file_programmers = "";
	this->file_tasks = "";
}

Repo::Repo(string file_programmers,string file_tasks)
{
	this->file_programmers  = file_programmers;
	this->file_tasks = file_tasks;
	read_from_file();
}

Repo::~Repo()
{}

vector<Programmer> Repo::getProgrammers()
{
	return this->programmers;
}

vector<Task> Repo::getTasks()
{
	return this->tasks;
}


void Repo::read_from_file()
{
	Programmer programmer;
	if (this->file_programmers != "")
	{
		ifstream fin(file_programmers);
		while (fin >> programmer)
		{
			programmers.push_back(programmer);
		}
		fin.close();
	}
	else
		throw(exception("No file name!"));

	Task task;
	if (this->file_tasks != "")
	{
		ifstream fin(file_tasks);
		while (fin >> task)
		{
			tasks.push_back(task);
		}
		fin.close();
	}
	else
		throw(exception("No file name!"));

}

void Repo::add_task(Task& task)
{
	this->tasks.push_back(task);
}

void Repo::remove_task(Task& task)
{
	for (int i = 0; i < this->tasks.size(); i++)
	{
		if (this->tasks[i] == task)
		{
			this->tasks.erase(this->tasks.begin() + i);
			break;
		}
	}
}


void test_remove_task_repo()
{
	Repo repo = Repo("programmers.txt", "tasks.txt");
	Task task = Task("task1", "open", 1);
	repo.remove_task(task);
	assert(repo.getTasks().size() == 2);
}