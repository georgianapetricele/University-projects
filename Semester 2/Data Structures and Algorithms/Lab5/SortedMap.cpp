#include "SMIterator.h"
#include "SortedMap.h"
#include <exception>
#include <vector>
using namespace std;



/*
Best case: Theta(capacity) - it parses the entire array of nodes for initializing the nodes
Worst case: Theta(capacity) 
Total complexity: Theta(capacity)
*/
SortedMap::SortedMap(Relation r) 
{
	//TODO - Implementation
	this->relation = r;
	this->bst.capacity=10;
	this->bst.root=0;
	this->bst.size=0;
	this->bst.nodes = new BSTNode[this->bst.capacity];
	this->bst.firstEmpty = 0;
	//initialize the nodes of the BST
	for (int i = 0; i < this->bst.capacity; i++) 
	{
		this->bst.nodes[i].info = NULL_TPAIR;
		this->bst.nodes[i].left = NULL_TVALUE;
		this->bst.nodes[i].right = NULL_TVALUE;
	}

}

/*
 Best case: Theta(1) - the key is the root of the BST
 Worst case: Theta(log2n) - the key is a leaf of the BST
 Total complexity: O(log2n)
*/
int SortedMap::searchNode(TKey k) 
{
	int current = this->bst.root;
	while (current != NULL_TVALUE) 
	{
		//if the key is greater than the current node's key, go to the right subtree of the current node
		if (this->relation(this->bst.nodes[current].info.first, k))  
		{
			if (k == this->bst.nodes[current].info.first)
				return current;
			current = this->bst.nodes[current].right;
		}
		else {
			current = this->bst.nodes[current].left;
		}
	}
	return NULL_TVALUE;
}

/*
 Best case: Theta(1) - the key is the root of the BST
 Worst case: Theta(log2n) - the key is a leaf of the BST
 Total complexity: O(log2n)
 */
void SortedMap::recomputeFirstEmpty()
{
	while (this->bst.nodes[this->bst.firstEmpty].info.first != NULL_TVALUE || this->bst.nodes[this->bst.firstEmpty].info.second != NULL_TVALUE)
	{
		this->bst.firstEmpty++;
	}
}

/*
Best Case: Theta(capacity) - it parses the entire array for initializing the nodes
Worst Case: Theta(capacity) - it parses the entire array for initializing the nodes
Total complexity: Theta(capacity)
*/
void SortedMap::resize()
{
	BSTNode* aux = new BSTNode[this->bst.capacity * 2];

	//copy the nodes from the old array to the new one
	for (int i = 0; i < this->bst.capacity; i++) 
	{
		aux[i] = this->bst.nodes[i];
	}
	//initialize the rest of the nodes
	for (int i = this->bst.capacity; i < this->bst.capacity * 2; i++) 
	{
		aux[i].info = NULL_TPAIR;
		aux[i].left = NULL_TVALUE;
		aux[i].right = NULL_TVALUE;
	}
	recomputeFirstEmpty();
	this->bst.capacity *= 2;
	delete[]this->bst.nodes;
	this->bst.nodes = aux;
}

/*
Best Case: Theta(1) - the key is the root of the BST
Worst Case: Theta(n) -  when the tree isn't balanced
Total complexity: O(log2n) - N is the number of nodes in the BST, it traverses the height of the tree to find the appropriate position for inserting
*/
int SortedMap::insert_recursively(int node, TElem e)
{
	//if the node is null, then the first empty node is the current node
	if (node == NULL_TVALUE)
	{
		this->bst.nodes[this->bst.firstEmpty].info = e;
		int old = this->bst.firstEmpty;
		recomputeFirstEmpty();
		return old;
	}
	//if the key is smaller than the current node's key, go to the left subtree of the current node
	else if (!this->relation(this->bst.nodes[node].info.first, e.first)) 
	{
		this->bst.nodes[node].left = insert_recursively(this->bst.nodes[node].left, e);
		return node;
	}
	else {
		this->bst.nodes[node].right = insert_recursively(this->bst.nodes[node].right, e);
		return node;
	}
}

/*
Best Case: Theta(1) - when the BST is empty
Worst Case: Theta(capacity) - occurs when the resize function is called and every element needs to be traversed for insertion or search
Total complexity: O(log2n) - when the tree is balanced
*/
TValue SortedMap::add(TKey k, TValue v) {
	//TODO - Implementation
	// adds a pair (key,value) to the map
	//if the key already exists in the map, then the value associated to the key is replaced by the new value and the old value is returned
	//if the key does not exist, a new pair is added and the value null is returned
	if (search(k) == NULL_TVALUE)
	{
		if (isEmpty()) 
		{
			this->bst.nodes[0].info = make_pair(k, v);
			this->bst.firstEmpty = 1;
			this->bst.size++;
			return NULL_TVALUE;
		}
		if (this->bst.size == this->bst.capacity - 1)
			resize();
		//insert the new node in the BST recursively and return the position of the new node
		this->insert_recursively(this->bst.root, make_pair(k, v));
		this->bst.size++;
		return NULL_TVALUE;
	}
	else
	{
		//replace the old value associated with key k with the new one
		TValue old = search(k);
		int current = this->bst.root;
		while (current != NULL_TVALUE) 
		{
			if (this->relation(this->bst.nodes[current].info.first, k))  
			{
				if (k == this->bst.nodes[current].info.first)
				{
					this->bst.nodes[current].info.second = v;
					return old;
				}
				current = this->bst.nodes[current].right;
			}
			else 
			{
				current = this->bst.nodes[current].left;
			}
		}
		return old;
		
	}
}

/*
Best Case: Theta(1) - when the BST is empty
Worst Case: Theta(capacity) - occurs when tree is not balanced
Total complexity: O(log2n) - when the tree is balanced
*/
TValue SortedMap::search(TKey k) 
{
	//TODO - Implementation
	// returns the value associated with a key, if the key exists in the map, or null: NULL_TVALUE otherwise
	int current = this->bst.root;
	while (current != NULL_TVALUE) {
		if (this->relation(this->bst.nodes[current].info.first, k)) {
			if (k == this->bst.nodes[current].info.first)
				return this->bst.nodes[current].info.second;
			current = this->bst.nodes[current].right;
		}
		else {
			current = this->bst.nodes[current].left;
		}
	}
	return NULL_TVALUE;
}


/*
Best Case: Theta(1) - when the BST is empty
Worst Case: Theta(capacity) - occurs when tree is not balanced
Total complexity: O(log2n) - when the tree is balanced
*/
int SortedMap::minimum(int node)
{
	int current = node;
	while (this->bst.nodes[current].left != NULL_TVALUE)
		current = this->bst.nodes[current].left;
	return current;
}


/*
Best Case: Theta(1) - when the node to be removed is the root of the BST
Worst Case: Theta(log2n) - when node has both left and right children and involves traversing the right subtree to the leftmost node for the replacement
Total complexity: O(log2n)
*/
TValue SortedMap::remove(TKey k) {
	// TODO - Implementation
	// Removes a key from the map and returns the value associated with the key if the key exists, or null: NULL_TVALUE otherwise
	int current = this->bst.root;
	int parent = NULL_TVALUE;

	// Find the node to be removed and its parent node
	while (current != NULL_TVALUE && this->bst.nodes[current].info.first != k) 
	{
		parent = current;
		if (this->relation(this->bst.nodes[current].info.first, k))
			current = this->bst.nodes[current].right;
		else
			current = this->bst.nodes[current].left;
	}

	if (current == NULL_TVALUE)
		return NULL_TVALUE;

	// Save the value of the node to be removed
	TValue value = this->bst.nodes[current].info.second;

	// Case 1: Node has no children
	if (this->bst.nodes[current].left == NULL_TVALUE && this->bst.nodes[current].right == NULL_TVALUE) {
		if (parent == NULL_TVALUE)
			this->bst.root = NULL_TVALUE;
		else if (this->bst.nodes[parent].left == current)
			this->bst.nodes[parent].left = NULL_TVALUE;
		else
			this->bst.nodes[parent].right = NULL_TVALUE;
	}
	// Case 2: Node has only left child
	else if (this->bst.nodes[current].right == NULL_TVALUE) {
		if (parent == NULL_TVALUE)
			this->bst.root = this->bst.nodes[current].left;
		else if (this->bst.nodes[parent].left == current)    //if the node to be removed is the left child of its parent node 
			this->bst.nodes[parent].left = this->bst.nodes[current].left; //then the left child of the parent node becomes the left child of the node to be removed
		else
			this->bst.nodes[parent].right = this->bst.nodes[current].left; //otherwise the right child of the parent node becomes the left child of the node to be removed
	}
	// Case 3: Node has only right child
	else if (this->bst.nodes[current].left == NULL_TVALUE) {
		if (parent == NULL_TVALUE)
			this->bst.root = this->bst.nodes[current].right;
		else if (this->bst.nodes[parent].left == current)
			this->bst.nodes[parent].left = this->bst.nodes[current].right;
		else
			this->bst.nodes[parent].right = this->bst.nodes[current].right;
	}
	// Case 4: Node has both left and right children
	else 
	{
		int successor = this->bst.nodes[current].right; // Find the successor of the node to be removed 
		int successorParent = current;

		// Find the minimum value in the right subtree as the successor of the node to be removed
		while (this->bst.nodes[successor].left != NULL_TVALUE) 
		{
			successorParent = successor;
			successor = this->bst.nodes[successor].left;
		}

		// Replace the key-value pair of the current node with the successor's key-value pair
		this->bst.nodes[current].info = this->bst.nodes[successor].info;

		// Update the parent's left or right child reference to the successor's right child
		if (successorParent == current)
			this->bst.nodes[successorParent].right = this->bst.nodes[successor].right;
		else
			this->bst.nodes[successorParent].left = this->bst.nodes[successor].right;

		current = successor; // Set the current node to the successor for further deletion
	}


	this->bst.nodes[current].info = NULL_TPAIR;
	this->bst.nodes[current].left = NULL_TVALUE;
	this->bst.nodes[current].right = NULL_TVALUE;

	this->bst.size--; // Decrease the size of the map

	return value; // Return the value associated with the removed key
}

/*
Best Case: Theta(1) 
Worst Case: Theta(1)
Total complexity: O(1)
*/
int SortedMap::size() const {
	//TODO - Implementation
	return this->bst.size;
}

/*
Best Case: Theta(1)
Worst Case: Theta(1)
Total complexity: O(1)
*/
bool SortedMap::isEmpty() const {
	//TODO - Implementation
	if (this->bst.size == 0)
		return true;
	return false;
}

/*
Best Case: Theta(1)
Worst Case: Theta(1)
Total complexity: O(1)
*/
SMIterator SortedMap::iterator() const {
	return SMIterator(*this);
}

/*
Best Case: Theta(1)
Worst Case: Theta(capacity)
Total complexity: O(capacity)
*/
SortedMap::~SortedMap() {
	//TODO - Implementation
	delete[]this->bst.nodes;
}
