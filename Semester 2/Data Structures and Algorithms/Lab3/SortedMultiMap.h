#pragma once
//DO NOT INCLUDE SMMITERATOR

//DO NOT CHANGE THIS PART
#include <vector>
#include <utility>
typedef int TKey;
typedef int TValue;
typedef std::pair<TKey, TValue> TElem;
#define NULL_TVALUE -111111
#define NULL_TELEM pair<TKey, TValue>(-111111, -111111);
using namespace std;
class SMMIterator;
typedef bool(*Relation)(TKey, TKey);


class SortedMultiMap 
{
    friend class SMMIterator;
private:
    //TODO - Representation

    struct Node 
    {
        int value = NULL_TVALUE;
        Node* next;
    };

    struct DLLA 
    {
        Node* array;
        int capacity;
        int size;
        int first_free;
        int head;
        int tail;

        DLLA()
        {
            capacity = 2;
            size = 0;
            first_free = 0;
            head = -1;
            tail = -1;
            for (int index = 0; index < capacity - 1; index++) 
            {
                nodes[index].next = index + 1;
                nodes[index].prev = index - 1;
            }
            nodes[capacity - 1].next = -1;
            nodes[capacity - 1].prev = capacity - 2;
        }

        ~DLLA() {
            if (nodes == nullptr) {
                return;
            }
            nodes = nullptr;
        }
    };

    DLLA< pair<TKey, DLLA<TValue> > > keys;
    Relation relation;
    int number_of_pairs;
    
public:

    // constructor
    SortedMultiMap(Relation r);

    //adds a new key value pair to the sorted multi map
    void add(TKey c, TValue v);

    //returns the values belonging to a given key
    vector<TValue> search(TKey c) const;

    //removes a key value pair from the sorted multimap
    //returns true if the pair was removed (it was part of the multimap), false if nothing is removed
    bool remove(TKey c, TValue v);

    //returns the number of key-value pairs from the sorted multimap
    int size() const;

    //verifies if the sorted multi map is empty
    bool isEmpty() const;

    // returns an iterator for the sorted multimap. The iterator will returns the pairs as required by the relation (given to the constructor)	
    SMMIterator iterator() const;

    // destructor
    ~SortedMultiMap();
};
