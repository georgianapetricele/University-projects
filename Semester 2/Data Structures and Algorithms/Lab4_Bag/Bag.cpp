#include "Bag.h"
#include "BagIterator.h"
#include <exception>
#include <iostream>
using namespace std;

//Best Case: Theta(M) - because it initializez the hashtable with m distinct positions
//Worst Case: Theta(M) - because it initializez the hashtable with m distinct positions
//Total Complexity: O(M) - because it initializez the hashtable with m distinct positions
Bag::Bag() 
{
	//TODO - Implementation
	this->m = 200; //initialize the number of distinct elements associated to a key in the hash table with 200
	this->nr_elements = 0; //initialize the number of elements with 0
	this->hashtable = new struct Node* [this->m]; //create a hashtable with m distinct positions 
	for (int index = 0; index < this->m; index++)
		this->hashtable[index] = NULL;
}

//Best Case: Theta(1)
//Worst Case: Theta(1)
//Total Complexity: O(1)
TElem Bag::hash_function(TElem elem) const
{
	int modulo = elem % this->m;
	if (modulo < 0)
		return modulo + this->m;
	else
		return modulo;

}

//Best Case: Theta(M) - when every key has a list with only one element
//Worst Case: Theta(M*length) - because it parses for every key in the hash table the list associated to it
//Total Complexity: O(M*length) - because it parses for every key in the hash table the list associated to it
void Bag::resize()
{
	this->m *= 2; //double the number of distinct elements associated to a key in the hash table

	TElem* copy_elems = new TElem[this->nr_elements];
	int* copy_freq = new int[this->nr_elements];
	int k = 0; 
	for (int i = 0; i < this->m / 2; i++) {  //copy all the elements from the old hash table into the new one
		struct Node* current_node = this->hashtable[i];
		while (current_node != NULL) {
			copy_elems[k] = current_node->elem;
			copy_freq[k++] = current_node->frequency;
			current_node = current_node->next;
		}
	}

	for (int i = 0; i < this->m / 2; i++) { //delete the old hash table
		struct Node* current_node = this->hashtable[i];
		while (current_node != NULL) {
			struct Node* next_node = current_node->next;
			delete current_node;
			current_node = next_node;
		}
	}
	delete[] this->hashtable;

	this->nr_elements = 0;
	this->hashtable = new struct Node* [this->m];
	for (int i = 0; i < this->m; i++) {
		this->hashtable[i] = NULL;
	}

	for (int i = 0; i < k; i++) {    //add all the elements from the old hash table into the new one 
		for (int j = 0; j < copy_freq[i]; j++) {  //add the element copy_elems[i] copy_freq[i] times
			this->add(copy_elems[i]);
		}
	}

	delete[] copy_elems;

}

//Best Case: Theta(1) - the element is found on the first position in the list
//Worst Case: Theta(M*length^2) - when it has to resize the hash table and it has to parse the list associated to the key
//Total Complexity: O(M*length^2) 
void Bag::add(TElem elem)
{
	//TODO - Implementation
	double load_factor = this->nr_elements / this->m; //load factor= the number of elements divided by the number of distinct elements associated to a key in the hash table
	if (load_factor >= 1)
		this->resize(); 

	TElem position = this->hash_function(elem); //get the position in the hashtable where the element should be added 

	struct Node* current_node = this->hashtable[position]; // get the first node in the list associated to the key
	while(current_node!=NULL && elem!=current_node->elem)
		current_node = current_node->next; 

	if (current_node == NULL) //if the element is not in the list, add it 
	{
		current_node = this->hashtable[position]; 
		struct Node* prev_node = NULL;
		struct Node* new_node = new struct Node;
		new_node->elem = elem;
		new_node->frequency = 1;
		while (current_node != NULL)
		{
			prev_node = current_node;
			current_node = current_node->next;
		}
		if (prev_node == NULL)
		{
			new_node->next = this->hashtable[position]; //if the list is empty, add the new node as the first node
			this->hashtable[position] = new_node;
		}
		else
		{
			new_node->next = current_node;
			prev_node->next = new_node;
		}
	}
	else
		current_node->frequency++;
	this->nr_elements++;
}

//Best Case: Theta(1) - the element is found on the first position in the list
//Worst Case: Theta(length) - when a key is associated to a list with only one element and the element is not found
//Total Complexity: O(length) 
bool Bag::remove(TElem elem) {
	//TODO - Implementation
	TElem position = this->hash_function(elem); //get the position in the hashtable where the element should be removed
	struct Node* current_node = this->hashtable[position];
	struct Node* prev_node = NULL;

	while (current_node != NULL && current_node->elem != elem) // go to the node that contains the element
	{
		prev_node = current_node;
		current_node = current_node->next;
	}

	if (current_node == NULL)
		return false;
	else 
	{
		if (current_node->frequency == 1) //if the element appears only once in the list, delete the node
		{
			if (prev_node == NULL)
				this->hashtable[position] = this->hashtable[position]->next;
			else
				prev_node->next = current_node->next;
		}
		else
			current_node->frequency--;   //if the element appears more than once in the list, decrease the frequency 
		this->nr_elements--;
		return true;
	}
}

//Best Case: Theta(1) - the element is found on the first position in the list
//Worst Case: Theta(length) - all elements have the same hash value and it parses the entire list
//Total Complexity: O(length)
bool Bag::search(TElem elem) const
{
	//TODO - Implementation
	//find the position in the hashtable where the element should be
	TElem position = this->hash_function(elem);
	struct Node* current_node = this->hashtable[position];

	while (current_node != NULL && current_node->elem != elem)
		current_node = current_node->next;

	if (current_node == NULL)
		return false;
	else
		return true;

}

//Best Case: Theta(1) - the element is found on the first position in the list
//Worst Case: Theta(length) - when it parses the entire list and the element is not found
//Total Complexity: O(length)
int Bag::nrOccurrences(TElem elem) const 
{
	//TODO - Implementation
	TElem position = this->hash_function(elem); //get the position in the hashtable where the element should be
	struct Node* current_node = this->hashtable[position];

	while (current_node != NULL && current_node->elem != elem)
		current_node = current_node->next;

	if (current_node == NULL)
		return 0;
	else
		return current_node->frequency;
}


//Best Case: Theta(1)
//Worst Case: Theta(1)
//Total Complexity: O(1)
int Bag::size() const 
{
	//TODO - Implementation
	return this->nr_elements;
}

//Best Case: Theta(1)
//Worst Case: Theta(1)
//Total Complexity: O(1)
bool Bag::isEmpty() const 
{
	//TODO - Implementation
	if(this->nr_elements ==0)
		return true;
	return false;
}

//Best Case: Theta(1)
//Worst Case: Theta(1)
//Total Complexity: O(1)
BagIterator Bag::iterator() const {
	return BagIterator(*this);
}

//Best Case: Theta(M) - when every key is associated to a list with only one element
//Worst Case: Theta(M*length) - when every key is associated to a list with N elements
//Total Complexity: O(M*length)
Bag::~Bag() 
{
	//TODO - Implementation
	for (int i = 0; i < this->m / 2; i++)
	{
		struct Node* current_node = this->hashtable[i];
		while (current_node != NULL)
		{
			struct Node* next_node = current_node->next;
			delete current_node;
			current_node = next_node;
		}
	}
	delete[] this->hashtable;
}

//Best Case: Theta(M) - when every key is associated to a list with only one element
//Worst Case: Theta(M*length) - when every key is associated to a list with length elements
//Total Complexity: O(M*length)
int Bag::distinctCount() const
{
	int count = 0;
	for (int i = 0; i < this->m; i++)
	{
		struct Node* current_node = this->hashtable[i];
		while (current_node != NULL)
		{
			count++;
			current_node = current_node->next;
		}
	}
	return count;
}