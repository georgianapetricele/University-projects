#pragma once
#include "Domain.h"


typedef Tutorial TElem;

class DynamicVector
{
private:
	TElem* elems;
	int size, capacity;
public:
	DynamicVector(int capacity);

	DynamicVector();

	DynamicVector(const DynamicVector& v);

	~DynamicVector();

	DynamicVector& operator=(const DynamicVector& v);

	DynamicVector& operator+(const TElem& elem);

	TElem get_element_on_position(int position);

	void resize();

	int get_size();

	int find(const TElem& elem);

	void add(const TElem& elem);

	void remove(const TElem& elem);

	void update(const TElem& new_elem, int position_element_in_array);

};