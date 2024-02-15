#pragma once
#include "SortedMap.h"
#include <stack>

using namespace std;
//DO NOT CHANGE THIS PART
class SMIterator {
	friend class SortedMap;
private:
	const SortedMap& map;
	SMIterator(const SortedMap& mapionar);

	//TODO - Representation

	//Make the iterator bidirectional - add an extra field to keep the previous node in the stack and implement the previous() operation
	int currentNode;
	int previousNode;
	//previous stack
	stack<int> prevStack;
	stack<int> stack;

public:
	void first();
	void next();
	bool valid() const;
	TElem getCurrent() const;
	//void previous();
	void skipKSteps(int k);
};

