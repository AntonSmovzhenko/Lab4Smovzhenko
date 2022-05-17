///////Smovzhenko Anton

#define _ARRAY_

#include <string>
#include <iostream>
using namespace std;

typedef int Elem;
class Array
{
public:
	class BadArray;
	class BadIndex;
	explicit Array(size_t);
	~Array();

	Elem& operator[] (size_t index);
	const Elem& operator[] (size_t index) const;
	size_t size() const;

private:

	const size_t _size;
	Elem* _pElem;

	bool operator== (const Array&) const;

	Array(const Array&);

	Array& operator= (const Array&);

};

class Array::BadArray
{

private:
	string _reason;
	size_t _ID;

public:

	BadArray(string reason = "", size_t index = 0)
		:_reason(reason), _ID(index)
	{
		return;
	};
	~BadArray() {};
	void diagnose() const
	{
		cerr << _reason << endl;
		if (_ID != 0)

			cerr << ' ' << _ID;
		cerr << endl;
	}
};

ostream& operator<<(ostream& ostr, const Array& seq);

