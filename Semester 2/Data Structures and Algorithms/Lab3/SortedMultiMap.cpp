#include "SMMIterator.h"
#include "SortedMultiMap.h"
#include <iostream>
#include <vector>
#include <exception>
using namespace std;


SortedMultiMap::SortedMultiMap(Relation r) {
	//TODO - Implementation
	this->relation = r;
	this->number_of_pairs = 0;
}

void SortedMultiMap::add(TKey c, TValue v) {
	//add a new key value pair to the sorted multi map
	//TODO - Implementation
	if (!this->isEmpty())
	{
		int current = this->keys.head;
		while (current != -1)
		{
			if(this->keys.nodes[])
		}
	}

}

vector<TValue> SortedMultiMap::search(TKey c) const {
	//TODO - Implementation

	//return vector<TValue>();
}

bool SortedMultiMap::remove(TKey c, TValue v) {
	//TODO - Implementation
	return false;
}


int SortedMultiMap::size() const {
	//TODO - Implementation
	return 0;
}

bool SortedMultiMap::isEmpty() const {
	//TODO - Implementation

	if(this->elems.head == -1)
		return true;
	return false;
}

SMMIterator SortedMultiMap::iterator() const {
	return SMMIterator(*this);
}

SortedMultiMap::~SortedMultiMap() {
	//TODO - Implementation
}

