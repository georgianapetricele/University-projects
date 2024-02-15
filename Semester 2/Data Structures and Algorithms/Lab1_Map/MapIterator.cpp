#include "MapIterator.h"
#include <exception>

//Complexity theta(1)
MapIterator::MapIterator(const Map &map) : map(map) {
	currentIndex = 0;
}

//Complexity theta(1)
TElem MapIterator::getCurrent() const
{
	if (valid()) {
		return map.mapArray[currentIndex];
	}
	else {
		throw std::exception(); 
	}
	
}

//Complexity theta(1)
bool MapIterator::valid() const
{
	return currentIndex < map.length;
}

//Complexity theta(1)
void MapIterator::next()
{
	if (valid()) {
		currentIndex++;
	}
	else {
		throw std::exception();
	}
}

//Complexity theta(1)
void MapIterator::first()
{
	currentIndex = 0;
}
