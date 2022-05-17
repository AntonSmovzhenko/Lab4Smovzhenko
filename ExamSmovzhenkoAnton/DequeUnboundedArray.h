///////Smovzhenko Anton

#pragma once

#include "BoundedDequeArray.h"

#include <iostream>

using namespace std;

template<class T>

class DequeUnboundedArray : public BoundedDequeArray<T>

{
private:

	void checkForCapacityDecrement()
	{
		double sizeRelation = static_cast<double>(BoundedDequeArray<T>::_size) / static_cast<double>(BoundedDequeArray<T>::_array->length());
		if (sizeRelation <= 0.25 && BoundedDequeArray<T>::_array->length() >= 10)
		{
			resizeArray(BoundedDequeArray<T>::_array->length() / 2);
		}
	}

	void checkForCapacityIncrement()
	{
		if (BoundedDequeArray<T>::_size == BoundedDequeArray<T>::_array->length())
		{
			resizeArray(BoundedDequeArray<T>::_array->length() * 2);
		}
	}

	void resizeArray(const size_t& length)
	{
		T* _newArray = new T[length];

		//Array<T> _newArray(length);

		const size_t& oldLength = BoundedDequeArray<T>::_array->length();
		const size_t startIndex = length / 4;

		size_t current = BoundedDequeArray<T>::_front, i = 0;
		for (; i < (oldLength < length ? oldLength : BoundedDequeArray<T>::_size); ++i)
		{
			(*_newArray)[startIndex + i] =
				BoundedDequeArray<T>::_array->operator[](current++);
			if (current == oldLength)
			{
				current = 0;
			}
		}
		BoundedDequeArray<T>::_front = startIndex;
		BoundedDequeArray<T>::_back = startIndex + i - 1;
		delete BoundedDequeArray<T>::_array;
		BoundedDequeArray<T>::_array = _newArray;
	}

public:

	DequeUnboundedArray() : BoundedDequeArray<T>(10)
	{
		cout << "Unbounded array deque has just created" << endl;
	}

	~DequeUnboundedArray()
	{
		cout << "Unbounded array deque has just deleted" << endl;
	}

	bool full() const
	{
		return false;
	}

	void popFront()
	{
		BoundedDequeArray<T>::popFront();
		checkForCapacityDecrement();
	}

	void popBack()
	{
		BoundedDequeArray<T>::popBack();
		checkForCapacityDecrement();
	}

	/// ////////////////////////////////////

	void putFront(const T& value)
	{
		if (!BoundedDequeArray<T>::empty())
		{
			BoundedDequeArray<T>::_front = (BoundedDequeArray<T>::_front > 0) ? (BoundedDequeArray<T>::_front - 1) : (BoundedDequeArray<T>::_array->length() - 1);
		}
	
		BoundedDequeArray<T>::_size++;
		checkForCapacityIncrement();
	}

	void putBack(const T& value)
	{
		if (!BoundedDequeArray<T>::empty())
		{
			BoundedDequeArray<T>::_back = (BoundedDequeArray<T>::_back < BoundedDequeArray<T>::_array->length() - 1) ? (BoundedDequeArray<T>::_back + 1) : 0;
		}
	
		BoundedDequeArray<T>::_size++;

		checkForCapacityIncrement();
	}
};

