/*
#include "DynamicVector.h"
#include "Domain.h"


DynamicVector::DynamicVector(int capacity)
{
	this->size = 0;
	this->capacity = capacity;
	this->elems = new TElem[capacity];
}

DynamicVector::DynamicVector(const DynamicVector& v)
{
	this->size = v.size;
	this->capacity = v.capacity;
	this->elems = new TElem[this->capacity];
	for (int index = 0; index < this->size; index++)
		this->elems[index] = v.elems[index];
}

DynamicVector& DynamicVector::operator=(const DynamicVector& v)
{
	if (this == &v)
		return *this;

	this->capacity = v.capacity;
	this->size = v.size;

	delete[] this->elems;
	this->elems = new TElem[this->capacity];
	for (int index = 0; index < this->size; index++)
		this->elems[index] = v.elems[index];

	return *this;
}

int DynamicVector::get_size()
{
	return this->size;
}

DynamicVector& DynamicVector::operator+(const TElem& elem)
{
	if (this->size == this->capacity)
		this->resize();
	this->elems[this->size++] = elem;
	return *this;
}

DynamicVector::~DynamicVector()
{
	delete[] this->elems;
}

void DynamicVector::resize() {
	this->capacity += 10;
	TElem* newElems = new TElem[this->capacity];
	for (int index = 0; index < this->size; index++)
		newElems[index] = this->elems[index];

	delete[] this->elems;
	this->elems = newElems;
}

TElem DynamicVector::get_element_on_position(int position)
{
	return this->elems[position];
}

int DynamicVector::find(const TElem& elem) {
	for (int index = 0; index < this->size; index++)
		if (this->elems[0].get_title() == elem.get_title())
			return index;
	return -1;
}

void DynamicVector::add(const TElem& elem) {
	if (this->size == this->capacity)
		this->resize();
	this->elems[this->size++] = elem;
}

void DynamicVector::remove(const TElem& elem) {
	int position_of_element = this->find(elem);
	if (position_of_element == -1)
		return;
	//delete[] this->elems[position_of_element];
	for (int index = position_of_element; index < this->size - 1; index++)
		this->elems[index] = this->elems[index + 1];
	this->size--;
}

void DynamicVector::update(const TElem& new_elem, int position_element_in_array)
{
	this->elems[position_element_in_array] = new_elem;
}

*/

