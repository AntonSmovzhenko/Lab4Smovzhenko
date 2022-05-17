///////Smovzhenko Anton

#pragma once

#include "Deque.h"

#include <iostream>

using namespace std;

template<class T>

class BoundedDequeArray : public Deque<T>

{
protected:

	T* _array;

	size_t _size, _front, _back, _capacity;

public:

	BoundedDequeArray(size_t capacity) :

		_size(0), _front(capacity / 2), _back(_front), _capacity(capacity), _array(new T[capacity])

	{
		cout << "Fixed deque array implementation with size " << _capacity << " was created" << endl;

	}

	~BoundedDequeArray()
	{
		delete[] _array;
		cout << "Fixed deque array implementation with size " << _capacity << " was destructed" << endl;
	}

	size_t capacity() const
	{
		return _capacity;
	}

	size_t size() const
	{
		return _size;
	}

	bool empty() const
	{
		return _size == 0;
	}

	bool full() const
	{
		return _size == _capacity;
	}

	const T& front() const
	{
		if (empty())
		{
			throw Deque<T>::BadDeque("No more elements in deque");
		}
		return _array[_front];

	}

	const T& back() const
	{
		if (empty())
		{
			throw Deque<T>::BadDeque("No more elements in deque");
		}

		return _array[_back];

	}

	void putFront(const T& value)
	{
		if (full())
		{
			throw Deque<T>::BadDeque("Array`s full");
		}

		_size++;

		if (!empty())
		{
			_front = (_front == 0) ? (_capacity - 1) : (_front - 1);
		}

		_array[_front] = value;

	}

	void putBack(const T& val)
	{
		if (full())
		{
			throw Deque<T>::BadDeque("Array`s full");
		}
		
		if (!empty())
		{
			_back = (_back < _capacity - 1) ? (_back + 1) : 0;
		}

		_array[_back] = val;

	}

	void popFront()
	{
		if (empty())
		{
			throw Deque<T>::BadDeque("No elements to pop out");
		}
		_size--;

		T& toReturn = _array[_front];

		_front = (_front < _capacity - 1) ? (_front + 1) : 0;

	}

	void popBack()
	{
		if (empty())
		{
			throw Deque<T>::BadDeque("No elements to pop out");
		}

		_size--;

		T& toReturn = _array[_back];

		_back = (_back > 0) ? (_back - 1) : (_capacity - 1);

	}
};
