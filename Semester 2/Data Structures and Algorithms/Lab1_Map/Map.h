#pragma once
#include <vector>
#define NULL_TVALUE -1

typedef int TKey;

typedef int TValue;

typedef std::pair <TKey, TValue> TElem;

class MapIterator;

class Map {

	friend class MapIterator;

private:

	// representation of Map
	TElem *mapArray; 
	int length, maxCapacity;

	void fixDimension();

public:



	// implicit constructor

	Map();



	// adds a pair (key,value) to the map

	//if the key already exists in the map, then the value associated to the key is replaced by the new value and the old value is returned

	//if the key does not exist, a new pair is added and the value null is returned

	

	TValue add(TKey c, TValue v);



	//searches for the key and returns the value associated with the key if the map contains the key or null: NULL_TELEM otherwise

	TValue search(TKey c) const;



	//removes a key from the map and returns the value associated with the key if the key existed ot null: NULL_TELEM otherwise

	TValue remove(TKey c);



	//returns the number of pairs (key,value) from the map

	int size() const;



	//checks whether the map is empty or not

	bool isEmpty() const;



	//returns an iterator for the map

	MapIterator iterator() const;



	// destructor

	~Map();



};
