///////Smovzhenko Anton

#pragma once

#include "ListDeque.h"

#include "Peek.h"

#include <iostream>

using namespace std;

template<class T>

class ListPeekDeque : public ListDeque<T>, public Peek<T>

{
public:

	ListPeekDeque() : ListDeque<T>()
	{
		cout << "Peekback list deque has just created" << endl;
	}

	~ListPeekDeque()
	{
		cout << "Peekback list deque has just deleted" << endl;
	}

	const T& peek(size_t ID) const
	{
		if (ID >= ListDeque<T>::_size)
		{
			throw Deque<T>::BadDeque("-----BAD ID-----");
		}

		typename ListDeque<T>::Node* current = ListDeque<T>::_head;

			for (size_t i = 0; i < ID; ++i)
			{
				current = current -> _next;
			}

		return current -> _value;
	}

};
