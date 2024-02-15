#pragma once
//DO NOT INCLUDE BAGITERATOR
#include <utility>

//DO NOT CHANGE THIS PART
#define NULL_TELEM -111111;
typedef int TElem;
class BagIterator;

/*
ADT  Bag–using  a  hashtable  with  separate  chaining  in  which  (unique  element,  frequency) pairs are stored.
*/

struct Node
{
	TElem elem;
	int frequency = 0;
	struct Node* next;
};

class Bag 
{

private:
	//TODO - Representation
	struct Node** hashtable; 
	int m; //is the number of distinct elements associated to a key in the hash table
	int nr_elements; //is the number of elements in the bag

	//DO NOT CHANGE THIS PART
	friend class BagIterator;
public:
	//constructor
	Bag();

	TElem hash_function(TElem elem) const;

	void resize();

	//adds an element to the bag
	void add(TElem e);

	//removes one occurence of an element from a bag
	//returns true if an element was removed, false otherwise (if e was not part of the bag)
	bool remove(TElem e);

	//checks if an element appearch is the bag
	bool search(TElem e) const;

	//returns the number of occurrences for an element in the bag
	int nrOccurrences(TElem e) const;

	//returns the number of elements from the bag
	int size() const;

	//returns an iterator for this bag
	BagIterator iterator() const;

	//checks if the bag is empty
	bool isEmpty() const;

	int distinctCount() const;

	//destructor
	~Bag();
};