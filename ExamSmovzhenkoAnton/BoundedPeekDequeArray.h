///////Smovzhenko Anton

#pragma once

#include "BoundedDequeArray.h"
#include "Peek.h"

#include <iostream>

using namespace std;

template<class T>

class BoundedPeekDequeArray : public BoundedDequeArray<T>, public Peek<T>
{

public:

	BoundedPeekDequeArray(const size_t& capacity) : BoundedDequeArray<T>(capacity)
	{
		cout << "Peek bounded array deque has just created" << endl;
	}

	~BoundedPeekDequeArray()
	{
		cout << "Peek bounded array deque has just deleted" << endl;
	}

	const T& peek(size_t ID) const
	{
		if (ID >= BoundedDequeArray<T>::_size)
		{
			throw Deque<T>::BadDeque("-----BAD ID-----");
		}
		return BoundedDequeArray<T>::_array -> operator[]((BoundedDequeArray<T>::_front + ID) % BoundedDequeArray<T>::_array -> length());
	
	}

};
