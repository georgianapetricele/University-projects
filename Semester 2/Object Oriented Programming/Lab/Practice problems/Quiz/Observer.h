#pragma once
#include "Service.h"
#include <vector>

class Observer
{
	public:
	virtual ~Observer() {}
	virtual void update() = 0;

};

class Subject
{
private:
	std::vector<Observer*> observers;

public:
		virtual ~Subject() {}
		void notify()
		{
			for (auto observer : observers)
				observer->update();
		}
		void addObserver(Observer* o)
		{
			observers.push_back(o);
		}
		void removeObserver(Observer* o)
		{
			auto iterator = std::find(observers.begin(), observers.end(), o);
			if (iterator != observers.end())
				observers.erase(iterator);
		}
};