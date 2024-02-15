#include "Set.h"
#include "SetITerator.h"
#include <exception>

/*
Best Case: Theta(1)
Worst Case: Theta(1)
Total complexity: O(1)
*/
Set::Set()
{
	//TODO - Implementation
	this->first = nullptr;
	this->capacity = 0;
}

/*
Best Case: Theta(1) - when the element already exists in the set on the first position
Worst Case: Theta(nr_elements) - it searches the value to add to check if it isn't already in the set, when it parses all the elements
Total complexity: O(nr_elements)
Space Complexity: O(1) - because of the linked list
*/
bool Set::add(TElem elem) {
	//TODO - Implementation
	if (this->first == nullptr)  //check if the set is empty
	{
		this->capacity++;
		this->first = new Node;
		this->first->value = elem;
		return true;
	}
	else
	if (this->first->next == nullptr)  //check if second position is free
	{
		if (this->first->value == elem)
			return false;
		this->capacity++;
		this->first->next = new Node;
		this->first->next->value = elem;
		return true;
	}

	Node* current = this->first;
	Node* elem_to_add = new Node;
	while (current != nullptr) //parse the list until find free position
	{
		if (current->value == elem)
			return false;
		elem_to_add = current;
		current = current->next;
	}
	current = new Node;
	current->value = elem;
	elem_to_add->next = current;
	this->capacity++;
	return true;
}

/*
Best Case: Theta(1) - when it parses the set until the first element
Worst Case: Theta(nr_elements) - when it parses all the elements, because it does the search for checking if the element is in the set
Total complexity: O(nr_elements)
*/
bool Set::remove(TElem elem) {
	//TODO - Implementation
	if (this->first == nullptr)
		return false;
	else
	if (this->first->value == elem) //if first value is elem
	{
		Node* aux = this->first;
		this->first = this->first->next;
		delete aux;
		this->capacity--;
		return true;
	}
	Node* current = this->first;
	while (current->next != nullptr) //parse until the next value is elem
	{
		if (current->next->value == elem) 
		{
			Node* aux = current->next;
			current->next = aux->next;
			delete aux;
			this->capacity--;
			return true;
		}
		current = current->next;
	}
	return false;
}

/*
Best Case: Theta(1) - when the element exists in the set on the first position
Worst Case: Theta(nr_elements) - when it searches until the last element of the set
Total complexity: O(nr_elements)
*/
bool Set::search(TElem elem) const {
	//TODO - Implementation
	Node* current = this->first;
	while (current != nullptr) 
	{
		if (current->value == elem)
			return true;
		current = current->next;
	}
	return false;
}

/*
Best Case: Theta(1)
Worst Case: Theta(1)
Total complexity: O(1)
*/
int Set::size() const {
	//TODO - Implementation
	return this->capacity;
}


/*
Best Case: Theta(1)
Worst Case: Theta(1)
Total complexity: O(1)
*/
bool Set::isEmpty() const {
	//TODO - Implementation
	if (this->first == nullptr)
		return true;
	return false;
}

/*
Total complexity: O(nr_elements_s * nr_elements_given_set)
*/
void Set::union_sets(const Set& s)
{
	// s - given set
	if(s.size() == 0)
		throw std::exception();
	else
		{
			Node* current1 = s.first;
			while (current1 != nullptr)
			{
				if (search(current1->value) == 0) // it checks if current element isn't already in the set
					this->add(current1->value);
				current1 = current1->next;
			}
		}
}

/*
Best Case: Theta(1) - when it parses just the first element of the set
Worst Case: Theta(nr_elements) - it parses all the elements of the set
Total complexity: O(nr_elements)
*/
Set::~Set() 
{
	//TODO - Implementation
	Node* current = this->first;
	while (current != nullptr) 
	{
		Node* aux = current;
		current = current->next;
		delete aux;
	}
}

SetIterator Set::iterator() const {
	return SetIterator(*this);
}


