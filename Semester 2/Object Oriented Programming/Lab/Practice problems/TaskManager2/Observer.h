#pragma once
#include <vector>
#include <algorithm>

using namespace std;

class Observer
{
public:
	virtual void update() = 0;
	virtual ~Observer() {};
};

class Subject
{
private:
	vector<Observer*> observers;
public:
	virtual ~Subject() {}
	void addObserver(Observer* obs)
	{
		observers.push_back(obs);
	}
	void removeObserver(Observer* obs)
	{
		auto it = find(observers.begin(), observers.end(), obs);
		if (it != observers.end())
		observers.erase(remove(observers.begin(), observers.end(), obs), observers.end());
	}
	void notify()
	{
		for (auto obs : observers)
			obs->update();
	}
};