#include <assert.h>

#include "SortedMap.h"
#include "SMIterator.h"
#include "ShortTest.h"
#include <exception>
using namespace std;

bool relatie1(TKey cheie1, TKey cheie2) {
    if (cheie1 <= cheie2) {
        return true;
    }
    else {
        return false;
    }
}

void testAll() {
    SortedMap sm(relatie1);
    assert(sm.size() == 0);
    assert(sm.isEmpty());
    sm.add(1, 2);
    assert(sm.size() == 1);
    assert(!sm.isEmpty());
    assert(sm.search(1) != NULL_TVALUE);
    TValue v = sm.add(1, 3);
    assert(v == 2);
    assert(sm.search(1) == 3);
    SMIterator it = sm.iterator();
    it.first();
    while (it.valid()) {
        TElem e = it.getCurrent();
        assert(e.second != NULL_TVALUE);
        it.next();
    }
    assert(sm.remove(1) == 3);
    assert(sm.isEmpty());

    SortedMap sm2(relatie1);
    sm2.add(100, 101);
    sm2.add(102, 103);
    sm2.add(104, 105);
    sm2.add(105, 106);
    //test the skipksteps function
    SMIterator it2 = sm2.iterator();
    it2.first();
    assert(it2.getCurrent().first == 100);
    it2.skipKSteps(2);
    assert(it2.getCurrent().first == 104);

}

