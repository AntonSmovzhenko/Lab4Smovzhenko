#pragma once
#include "Arrays.h"
#include <iostream>
using namespace std;

//Anton Smovzhenko

const size_t testSize = 8;

template Array<testSize, string>;

template Array<testSize, int>;

/// /////////////////////

template<size_t n, typename T>
Array<n, T>::~Array()
{
	cout << "Destructoring : " << *this;
	delete[] _array;
}


template<size_t n, typename T>

Array<n, T>::Array() : _size(n)
{
	_array = new T[n];
	cout << "Constructoring : " << *this;
}

/// /////////////////////

template<size_t n, typename T>

const T& Array<n, T>::operator[](size_t id) const
{
	if (id < 0 || id > _size) {
		throw WrongArray("Index out of range", id);
	}
	return _array[id];
}


template<size_t n, typename T>

T& Array<n, T>::operator[](size_t id) {
	if (id < 0 || id > _size) {
		throw WrongArray("ID is out of range ", id);
		
	}
	return _array[id];
}


template<size_t n, typename T>

size_t Array<n, T>::size() const
{
	return _size;
}

template<size_t n, typename T>

ostream& operator<<(ostream& ostr, const Array<n, T>& array) {
	ostr << '{';
	for (size_t j = 0; j < array.size() - 1; j++) {
		ostr << array[j] << " , ";
	}
	ostr << array[array.size() - 1] << '}' << endl;
	return ostr;
}


template<size_t size, typename T>

Array<size, T>::WrongArray::WrongArray
(const string& reason, const size_t id)
	:_error(reason), _id(id)
{};


