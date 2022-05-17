///////Smovzhenko Anton

#pragma once

#include "ListDeque.h"

#include <iostream>

using namespace std;


template<class T>
class QueuePriority

{
private:

	struct Node
	{

		T _value;

		Node* _previous, * _next;

		Node(const T& val, Node* previous, Node* next) : _value(val), _previous(previous), _next(next) {}
			

	};

	Node* _head, * _tail;

	size_t _size;

	void createStartNode(const T& val)
	{
		_head = new Node(val, 0, 0);

		_tail = _head;
	}

	Node* popNode()
	{

		Node* nodeDeletetion = new Node(0, 0, 0);

		Node* current = _head;

		while (current != nullptr)

		{
			if (current->_value > nodeDeletetion->_value)
			{
				nodeDeletetion = current;
			}
			current = current->_next;
		}

		return nodeDeletetion;

	}

public:

	class Iterator
	{
	private:

		Node* _current;

	public:

		Iterator() : _current(0) {}

		Iterator(Node* node) : _current(node) {}

		bool stop() const
		{
			return _current == 0;
		}

		const T& operator*() const
		{
			return _current->_value;
		}

		Iterator operator++()
		{
			_current = _current->_next;
			return *this;
		}

		
		T& operator*()
		{
			return _current->_value;
		}

	};

	class BadQueue
	{

	private:

		string _reason;

	public:

		BadQueue(string reason = "") :_reason(reason) {};

		~BadQueue() {};

		void diagnose() const
		{
			cerr << _reason << endl;
		}
	};

	QueuePriority() : _size(0), _head(0), _tail(0)
	{
		cout << "QueuePriority has just created" << endl;
	}

	~QueuePriority()

	{

		Node* next = _head;
		Node* current;

		while (next != nullptr)
		{
			current = next;
			next = next->_next;
			delete current;
		}
		cout << "QueuePriority has just deleted" << endl;
	}

	Iterator attach()
	{
		return Iterator(_head);
	}

	
	bool full() const
	{
		return false;
	}

	bool empty() const
	{
		return _size == 0;
	}


	const T& back() const

	{
		if (empty())
		{
			throw BadQueue("--------No elements in priority queue--------");
		}
		return _tail -> _value;
	}

	const T& front() const

	{
		if (empty())
		{
			throw BadQueue("-------No elements in priority queue-------");
		}
		return _head -> _value;
	}

	

	void pop()
	{
		if (empty())
		{
			throw BadQueue("-------There is nothing in the list deque-----------");
		}

		Node* nodeDeletion = popNode();
		Node* current = _head;

		while (current != nullptr)
		{
			if (current == nodeDeletion)
			{
				if (current == _head)
				{
					_head->_next -> _previous = 0;
					_head = _head -> _next;
				}
				else if (current == _tail)
				{
					_tail->_previous ->_next = 0;
					_tail = _tail -> _previous;
				}	else
				{

					current -> _previous -> _next = current -> _next;

					current -> _next -> _previous = current -> _previous;
				}

				break;
			}
			current = current -> _next;
		}
		_size--;
	}

	void put(const T& val)
	{
		if (empty())
		{
			createStartNode(val);
		}
		else
		{
			_tail -> _next = new Node(val, _tail, 0);
			_tail = _tail -> _next;
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
ostream& operator<<(ostream& ostr, typename QueuePriority<T>::Iterator& iter)
{

	ostr << '{';

	while (!iter.stop())

	{
			ostr << *iter;

			++iter;

			if (!iter.stop())
			{
				ostr << ", ";
			}
	}

	ostr << '}';

	return ostr;
}

