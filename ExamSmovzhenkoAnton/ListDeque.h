///////Smovzhenko Anton

#pragma once

#include "Deque.h"
#include <iostream>
using namespace std;

template<class T>
class ListDeque : public Deque<T>
{
protected:

	struct Node
	{

		T _value;
		Node* _previous, * _next;

		Node(const T& value, Node* prev, Node* next) :
			_value(value), _previous(prev), _next(next) {}

	};
	Node* _head, * _tail;
	size_t _size;

	void createStartNode(const T& value)
	{
		_head = new Node(value, 0, 0);
		_tail = _head;
	}

public:

	class Iterator;

	ListDeque() : _size(0), _head(0), _tail(0)
	{
		cout << "ListDeque was created" << endl;
	}

	~ListDeque()
	{
		Node* next = _head;
		Node* cur;
		while (next != nullptr)
		{
			cur = next;
			next = next->_next;
			delete cur;
		}
		cout << "ListDeque was deleted" << endl;
	}

	Iterator attach()
	{
		return Iterator(_head);
	}

	bool empty() const
	{
		return _size == 0;
	}

	bool full() const
	{
		return false;
	}

	const T& front() const
	{
		if (empty())
		{
			throw Deque<T>::BadDeque("----- No elements in list deque ------");
		}
		return _head->_value;
	}

	const T& back() const
	{
		if (empty())
		{
			throw Deque<T>::BadDeque("----- No elements in list deque ------");
		}
		return _tail->_value;
	}

	void popFront()
	{
		if (empty())
		{
			throw Deque<T>::BadDeque("----- No elements in list deque ------");
		}
		Node* newHead = _head->_next;

		delete _head;

		_head = newHead;
		_tail->_previous = 0;
		_size--;
	}

	void popBack()
	{
		if (empty())
		{
			throw Deque<T>::BadDeque("----- No elements in list deque ------");
		}
		Node* newTail = _tail->_previous;

		delete _tail;

		_tail = newTail;
		_tail->_next = 0;
		_size--;
	}

	void putFront(const T& val)
	{
		if (empty())
		{
			createStartNode(val);
		}
		else {
			_head->_previous = new Node(val, 0, _head);
			_head = _head->_previous;

		}
		_size++;
		
	}

	void putBack(const T& val)
	{
		if (empty())
		{
			createStartNode(val);
		}else
		{
			_tail->_next = new Node(val, _tail, 0);
			_tail = _tail->_next;
		}
		_size++;
		
	}

	size_t capacity() const
	{
		return _size;
	}

	size_t size() const
	{
		return _size;
	}

};


template<class T>

class ListDeque<T>::Iterator

{
private:


	typename ListDeque<T>::Node* _current;

public:


	Iterator() : _current(0) {}


	Iterator(typename ListDeque<T>::Node* node) : _current(node) {}


	
	Iterator operator++()
	{
		_current = _current->_next;
		return *this;
	}

	bool stop() const
	{
		return _current == 0;
	}

	const T& operator*() const
	{
		return _current->_value;
	}


	T& operator*()
	{
		return _current->_value;
	}

};

