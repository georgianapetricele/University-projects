#include "SetIterator.h"
#include "Set.h"
#include <exception>

/*
Best Case: Theta(1)
Worst Case: Theta(1)
Total complexity: O(1)
*/
SetIterator::SetIterator(const Set& m) : set(m)
{
	//TODO - Implementation
	this->_first = m.first;
	this->current = m.first;
}


/*
Best Case: Theta(1)
Worst Case: Theta(1)
Total complexity: O(1)
*/
void SetIterator::first() {
	//TODO - Implementation
	this->current = this->_first;
}


/*
Best Case: Theta(1)
Worst Case: Theta(1)
Total complexity: O(1)
*/
void SetIterator::next() {
	//TODO - Implementation
	if (this->valid())        //valid() function has complexity O(1)
		this->current = this->current->next;
	else
		throw std::exception();
}


/*
Best Case: Theta(1)
Worst Case: Theta(1)
Total complexity: O(1)
*/
TElem SetIterator::getCurrent()
{
	//TODO - Implementation
	if (this->current == nullptr)
		throw std::exception();
	return this->current->value;
}

/*
Best Case: Theta(1)
Worst Case: Theta(1)
Total complexity: O(1)
*/
bool SetIterator::valid() const 
{
	//TODO - Implementation
	if (this->set.size() != 0 && this->current != nullptr)   // size() function has complexity O(1)
		return true;
	return false;
}



