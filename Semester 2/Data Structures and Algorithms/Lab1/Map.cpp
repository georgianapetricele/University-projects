#include "Map.h"
#include "MapIterator.h"
//n is total number of pairs found in the dynamic array.
Map::Map() //Complexity theta(1)
{
	length = 0;
	maxCapacity = 1;
	mapArray = new TElem[1];
}

//Complexity theta(n)
void Map::fixDimension()
{
	maxCapacity *= 2;
	TElem *temporaryMapArray = new TElem[maxCapacity];
	for (int i = 0; i < length; i++) {
		temporaryMapArray[i] = mapArray[i];
	}
	delete[]mapArray;
	mapArray = temporaryMapArray;
}

//Worst case = Theta(n) , Best Case = Theta(1) , Average = Theta(n) ==> complexity = O(n)
TValue Map::add(TKey c, TValue v)
{
	if (maxCapacity == length) {
		fixDimension();
	}
	for (int i = 0; i < length; i++) {
		if (mapArray[i].first == c) {
			TValue oldValue = mapArray[i].second;
			mapArray[i].second = v;
			return oldValue;
		}
	}
	TElem newPair;
	newPair.first = c;
	newPair.second = v;
	mapArray[length++] = newPair;
	return NULL_TVALUE;
}

//Worst case = Theta(n) , Best case = Theta(1), Average = Theta(n) ==> complexity = O(n)
TValue Map::search(TKey c) const
{
	for (int i = 0; i < length; i++) {
		if (mapArray[i].first == c) {
			return mapArray[i].second;
		}
	}
	return NULL_TVALUE;
}

//Worst case = Theta(n), Best Case = Theta(1), Average = Theta(n) ==> complexity = O(n)
TValue Map::remove(TKey c)
{
	TValue oldValue = NULL_TVALUE;
	int i = 0;
	while (i < length && mapArray[i].first != c) {
		i++;
	}
	if (i<length){
		oldValue = mapArray[i].second;
		length--;
		for (int j = i ; j < length ; j++)
			mapArray[j] = mapArray[j + 1];
		
	}
	return oldValue;
}

//Complexity theta(1)
int Map::size() const
{
	return length;
}

//Complexity theta(1)
bool Map::isEmpty() const
{
	return length==0;
}

MapIterator Map::iterator() const //Complexity theta(1)
{
	return MapIterator(*this);
}

//Complexity theta(1)
Map::~Map()
{
	delete[] mapArray;
}
