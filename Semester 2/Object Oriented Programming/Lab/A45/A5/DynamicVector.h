#pragma once

template <typename T>
class DynamicVector
{
private:
	T* elems;
	int size;
	int capacity;

public:

	DynamicVector(int capacity = 10);


	DynamicVector(const DynamicVector& v);
	~DynamicVector();

	DynamicVector& operator=(const DynamicVector& v);


	T& operator[](int pos);

	void add(T e);

	int get_size() const;

	T get_element(int pos);

	void update(const T& new_e, int position);

	void remove(int pos);

	int find(const T& elem);

private:

	void resize(int factor = 2);
};

template <typename T>
DynamicVector<T>::DynamicVector(int capacity)
{
	this->size = 0;
	this->capacity = capacity;
	this->elems = new T[capacity];
}

template <typename T>
DynamicVector<T>::DynamicVector(const DynamicVector<T>& v)
{
	this->size = v.size;
	this->capacity = v.capacity;
	this->elems = new T[this->capacity];
	for (int i = 0; i < this->size; i++)
		this->elems[i] = v.elems[i];
}

template <typename T>
DynamicVector<T>::~DynamicVector()
{
	delete[] this->elems;
}


template <typename T>
DynamicVector<T>& DynamicVector<T>::operator=(const DynamicVector<T>& v)
{
	if (this == &v)
		return *this;

	this->size = v.size;
	this->capacity = v.capacity;

	delete[] this->elems;

	this->elems = new T[this->capacity];
	for (int i = 0; i < this->size; i++)
		this->elems[i] = v.elems[i];

	return *this;
}

template <typename T>
T& DynamicVector<T>::operator[](int pos)
{
	return this->elems[pos];
}

template <typename T>
void DynamicVector<T>::add(T e)
{
	if (this->size == this->capacity)
		this->resize();
	this->elems[this->size] = e;
	this->size++;
}

template<typename T>
void DynamicVector<T>::remove(int position) 
{
	for (int index = position; index < this->size - 1; index++) {
		this->elems[index] = this->elems[index + 1];
	}
	this->size--;
}

template <typename T>
int DynamicVector<T>::find(const T& elem) 
{
	for (int index = 0; index < this->size; index++)
		if (this->elems[index].get_title() == elem.get_title())
			return index;
	return -1;
}

template <typename T>
void DynamicVector<T>::resize(int factor)
{
	this->capacity *= factor;

	T* auxiliary_element = new T[this->capacity];
	for (int index = 0; index < this->size; index++)
		auxiliary_element[index] = this->elems[index];

	delete[] this->elems;
	this->elems = auxiliary_element;
}

template <typename T>
int DynamicVector<T>::get_size() const
{
	return this->size;
}

template<typename T>
T DynamicVector<T>::get_element(int pos) 
{
	return this->elems[pos];
}

template<typename T>
void DynamicVector<T>::update(const T& new_element , int position)
{
	this->elems[position] = new_element;
}

