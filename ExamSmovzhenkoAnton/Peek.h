///////Smovzhenko Anton

#pragma once

using namespace std;

template<class T>

class Peek

{
public:

	Peek() {};

	virtual ~Peek() = 0 {};

	virtual const T& peek(size_t) const = 0;

};