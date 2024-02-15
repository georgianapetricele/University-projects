#include <iostream>
#include <list>

/*
Iplement in C++ the given container(ADT) using a given representation and a hashtable
with a given  collision  resolution(separate  chaining,  coalesced  chaining,  open  addressing)
as  a  data  structure. You are not allowed to use any container or data structure from STL or from any other 
library.Do not implement a separate class for the hashtable (or dynamic array, or anything), implement the 
container directly!The  hashtable  has  to  be  dynamic:  no  matter  what  collision  resolution  has to  be  used,
set  a threshold for ?nd resize and rehash the table when the actual load factor is higher than ?.
*/

/*
ADT  Bag–using  a  hashtable  with  separate  chaining  in  which  (unique  element,  frequency) pairs are stored.
*/

class Bag 
{
private:
    struct Node {
        int element;
        int frequency;
    };

    int capacity;
    int size;
    std::list<Node>* table;

public:
    Bag() {
        capacity = 10;
        size = 0;
        table = new std::list<Node>[capacity];
    }

    ~Bag() {
        delete[] table;
    }

    void insert(int element) {
        int index = hash(element);
        for (auto it = table[index].begin(); it != table[index].end(); ++it) {
            if (it->element == element) {
                ++it->frequency;
                return;
            }
        }
        Node newNode;
        newNode.element = element;
        newNode.frequency = 1;
        table[index].push_back(newNode);
        ++size;
    }

    void remove(int element) {
        int index = hash(element);
        for (auto it = table[index].begin(); it != table[index].end(); ++it) {
            if (it->element == element) {
                --it->frequency;
                if (it->frequency == 0) {
                    table[index].erase(it);
                }
                --size;
                return;
            }
        }
    }

    int frequency(int element) {
        int index = hash(element);
        for (auto it = table[index].begin(); it != table[index].end(); ++it) {
            if (it->element == element) {
                return it->frequency;
            }
        }
        return 0;
    }

    int count() {
        return size;
    }

private:
    int hash(int element) {
        return element % capacity;
    }
};

int main() {
    Bag bag;

    bag.insert(5);
    bag.insert(10);
    bag.insert(5);

    std::cout << "Frequency of 5: " << bag.frequency(5) << std::endl;
    std::cout << "Frequency of 10: " << bag.frequency(10) << std::endl;
    std::cout << "Frequency of 20: " << bag.frequency(20) << std::endl;
    std::cout << "Count: " << bag.count() << std::endl;

    bag.remove(5);

    std::cout << "Frequency of 5: " << bag.frequency(5) << std::endl;
    std::cout << "Count: " << bag.count() << std::endl;

    return 0;
}