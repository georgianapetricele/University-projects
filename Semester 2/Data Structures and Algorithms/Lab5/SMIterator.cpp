#include "SMIterator.h"
#include "SortedMap.h"
#include <exception>

using namespace std;

/*
Best case: Theta(capacity)
Worst case: Theta(capacity) - it parses the entire BST and pushes all the nodes in the stack
Total complexity: O(capacity)
*/
SMIterator::SMIterator(const SortedMap& m) : map(m) {
	//TODO - Implementation
	int node = map.bst.root;

	while (node != NULL_TVALUE) 
	{
		//push the nodes from the root to the leftmost leaf in the stack
		this->stack.push(node);
		node = map.bst.nodes[node].left;
	}
	if (!this->stack.empty()) 
	{
		this->currentNode = stack.top(); //the current node is the leftmost leaf from the BST
		this->previousNode = NULL_TVALUE;
	}
	else {
		this->currentNode = NULL_TVALUE;
		this->previousNode = NULL_TVALUE;

	}
}


/*
Best case: Theta(capacity)
Worst case: Theta(capacity) - it parses the entire BST and pushes all the nodes in the stack
Total complexity: O(capacity)
*/
void SMIterator::first() {
	//TODO - Implementation
	while (!this->stack.empty())
		this->stack.pop(); //empty the stack
	int node = map.bst.root;
	while (node != NULL_TVALUE)  //push the nodes from the root to the leftmost leaf in the stack
	{
		this->stack.push(node);
		node = map.bst.nodes[node].left;
	}
	if (!this->stack.empty()) {
		this->currentNode = this->stack.top();
		this->previousNode = NULL_TVALUE;

	}
	else {
		this->currentNode = NULL_TVALUE;
		this->previousNode = NULL_TVALUE;
	}
}

/*
Best Case: Theta(1) - the current node hasn't a right subtree
Worst Case: Theta(capacity) - it parses the entire BST and pushes all the nodes in the stack
Total complexity: O(capacity)
*/
void SMIterator::next() {
	//TODO - Implementation
	if (!valid())
		throw std::exception();

	int node;
	if(!stack.empty())
		node = this->stack.top();
	else
		node = NULL_TVALUE;
	this->stack.pop();
	if (map.bst.nodes[node].right != NULL_TVALUE)  //if the current node has a right subtree, push the nodes from the root to the leftmost leaf in the stack
	{
		node = map.bst.nodes[node].right;
		while (node != NULL_TVALUE) 
		{
			this->stack.push(node);
			node = map.bst.nodes[node].left;

		}
	}
	if (!this->stack.empty()) {
		this->currentNode = this->stack.top();
		this->previousNode = node;
	}
	else {
		this->currentNode = NULL_TVALUE;
		this->previousNode = NULL_TVALUE;
	}
}

/*
Best Case: Theta(1) 
Worst Case: Theta(1)
Total complexity: O(1)
*/
bool SMIterator::valid() const {
	//TODO - Implementation
	if (map.isEmpty())
		return false;
	return this->currentNode != NULL_TVALUE;

}


/*
Best Case: Theta(1)
Worst Case: Theta(1)
Total complexity: O(1)
*/
TElem SMIterator::getCurrent() const {
	//TODO - Implementation
	if (!valid())
		throw std::exception();
	return map.bst.nodes[this->currentNode].info;
}

/*
Best Case: Theta(1)
Worst Case: Theta(1)
Total complexity: O(1)
*/
//void SMIterator::previous() 
//{
//	//TODO - Implementation
//	if (!valid())
//		throw std::exception();
//	if (this->previousNode == NULL_TVALUE)
//		this->currentNode = NULL_TVALUE;
//	else 
//	{
//		this->currentNode = this->previousNode;
//		this->previousNode = this->stack.top();
//	}
//}


/*
Best Case: Theta(1) - when k = 0
Worst Case: Theta(capacity)
Total complexity: O(capacity)
*/
void SMIterator::skipKSteps(int k)
{
	if (k <= 0 || !valid())
		return;

	while (k > 0 && !stack.empty())
	{
		next();
		k--;
	}

	if(k > 0)
		throw std::exception();
}