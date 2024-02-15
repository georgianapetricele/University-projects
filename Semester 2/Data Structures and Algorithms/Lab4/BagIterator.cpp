#include <exception>
#include "BagIterator.h"
#include "Bag.h"

using namespace std;

//Best Case: Theta(1)
//Worst Case: Theta(1)
//Total Complexity: O(1)
BagIterator::BagIterator(const Bag& c) : bag(c)
{
	//implement the constructor
	this->position = 0;
	this->freq = 0;
	this->first();
}

//Best Case: Theta(1)
//Worst Case: Theta(capacity)
//Total Complexity: O(capacity)
void BagIterator::first()
{
	//TODO - Implementation
	//implement the first function
	if (this->bag.isEmpty())
		return;
	this->position = 0;
	this->freq = 0;
	while (this->position < this->bag.m && this->bag.hashtable[this->position] == NULL)
		this->position++;
	if (this->position == this->bag.m)
		this->freq = 0;
	else
		this->freq = 1;
}

//Best Case: Theta(1)
//Worst Case: Theta(capacity)
//Total Complexity: O(capacity)
void BagIterator::next() {
	//TODO - Implementation
	if (this->bag.isEmpty() || this->freq == 0)
		throw exception();
	if (this->freq < this->bag.hashtable[this->position]->frequency)
		this->freq++;
	else
	{
		this->freq = 1;
		this->position++;
		while (this->position < this->bag.m && this->bag.hashtable[this->position] == NULL)
			this->position++;
		if (this->position == this->bag.m)
			this->freq = 0;
	}
}

//Best Case: Theta(1)
//Worst Case: Theta(1)
//Total Complexity: O(1)
bool BagIterator::valid() const {
	//TODO - Implementation
	return this->freq > 0;
}


//Best Case: Theta(1)
//Worst Case: Theta(1)
//Total Complexity: O(1)
TElem BagIterator::getCurrent() const
{
	//TODO - Implementation
	if (this->valid())
		return this->bag.hashtable[this->position]->elem;
	else
		throw exception();
}
