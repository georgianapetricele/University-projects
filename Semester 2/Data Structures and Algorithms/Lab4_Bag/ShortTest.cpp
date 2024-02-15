#include "ShortTest.h"
#include <assert.h>
#include "Bag.h"
#include "BagIterator.h"
#include <iostream>


void testAll() {
	Bag b;
	assert(b.isEmpty() == true);
	assert(b.size() == 0);
	b.add(5);
	b.add(1);
	b.add(10);
	b.add(7);
	b.add(1);
	b.add(11);
	b.add(-3);
	assert(b.size() == 7);
	assert(b.search(10) == true);
	assert(b.search(16) == false);
	assert(b.nrOccurrences(1) == 2);
	assert(b.nrOccurrences(7) == 1);
	assert(b.remove(1) == true);
	assert(b.remove(6) == false);
	assert(b.size() == 6);
	assert(b.nrOccurrences(1) == 1);
	BagIterator it = b.iterator();
	it.first();
	while (it.valid()) {
		TElem e = it.getCurrent();
		it.next();
	}
		Bag b2;
		assert(b2.isEmpty() == true);
		assert(b2.size() == 0);
		b2.add(5);
		b2.add(1);
		assert(b2.distinctCount() == 2);
		b2.add(5);
		b2.add(5);
		b2.add(1);
		b2.add(201);
		b2.add(401);
		b2.add(10);
		b2.add(201);
		b2.add(205);
		assert(b2.size() == 10);
		assert(b2.distinctCount() == 6);
		std::cout << "Here";
}
