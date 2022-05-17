///////Smovzhenko Anton

#pragma once

#include "DequeUnboundedArray.h"

#include "Peek.h"

#include <iostream>

using namespace std;

template<class T>

class UnboundedPeekDequeArray : public DequeUnboundedArray<T>, public Peek<T>

{

public:

	UnboundedPeekDequeArray() : DequeUnboundedArray<T>()
	{
		cout << "Peek unbounded array deque has just created" << endl;
	}

	~UnboundedPeekDequeArray()
	{
		cout << "Peek unbounded array deque has just deleted" << endl;
	}

	const T& peek(size_t ID) const

	{
		if (ID >= BoundedDequeArray<T>::_size)
		{
			throw Deque<T>::BadDeque("----------BAD ID----------");
		}
		return BoundedDequeArray<T>::_array->operator[]((BoundedDequeArray<T>::_front + ID) % BoundedDequeArray<T>::_array->length());
			
	}

};
