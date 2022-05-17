///////Smovzhenko Anton

#pragma once

using namespace std;

template<class T>

class Deque
{
protected:

	Deque(const Deque&) = delete;

	Deque& operator=(const Deque&) = delete;

public:

	Deque() {};
	virtual ~Deque() = 0 {};

	virtual bool empty() const = 0;
	virtual bool full() const = 0;

	virtual void popFront() = 0;
	virtual void popBack() = 0;

	virtual void putFront(const T&) = 0;
	virtual void putBack(const T&) = 0;

	virtual const T& front() const = 0;
	virtual const T& back() const = 0;

	virtual size_t capacity() const = 0;
	virtual size_t size() const = 0;

	class BadDeque
	{
	private:

		string _reason;

	public:

		BadDeque(string reason = "") :_reason(reason){};

		~BadDeque() {};

		void diagnose() const
		{
			cerr << _reason << endl;
		}
	};

};
