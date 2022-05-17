#pragma once
#include <iostream>

//Anton Smovzhenko

using namespace std;
template<size_t n, typename T>
class Array {

private:

	T* _array;
	size_t _size;

public:

	class WrongArray;
	explicit Array();
	~Array();

	T& operator[] (size_t index);

	const T& operator[] (size_t index) const;

	size_t size() const;


};


//toString
template<size_t n, typename T>
ostream& operator<<(ostream&, const Array<n, T>&);

template<size_t size, typename T>
class Array<size, T>::WrongArray {

private:

	const string _error;
	const size_t _id;


public:

	WrongArray
	(const string& error = "null",
		const size_t id = 0);
	inline const string& whyError() const {
		return _error;
	}


};





