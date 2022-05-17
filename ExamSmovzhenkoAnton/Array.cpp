///////Smovzhenko Anton

#include <cassert>
#include <iostream>

using namespace std;

#include "Array.h"

Array::Array(size_t sz) :_size(sz), _pElem(new Elem[_size])
{
	if (_pElem == 0)
		throw BadArray("No more space in the system");
	cout << "Array created (" << _size << ')' << endl;
}

Array::~Array()
{
	cout << "Array of size (" << _size << ") deleted" << endl;
	delete[] _pElem;
}

Elem& Array::operator[] (size_t index)
{
	if (index < 0 || index >= _size)
		throw BadArray("Bad index: ", index);
	return _pElem[index];
}

const Elem& Array::operator[] (size_t index) const
{
	if (index < 0 || index >= _size)
		throw BadArray("Bad index: ", index);
	return _pElem[index];
}

size_t Array::size() const
{
	return _size;
}

//toString
ostream& operator<<(ostream& ostr, const Array& array)
{
	char chr = ' ';
	ostr << "Array of " << array.size();
	for (size_t i = 0; i < array.size(); i++)
	{
		ostr << chr << array[i];
		if (chr = ' ') chr = ',';
	}
	ostr << endl;
	return ostr;
}

