#include "String.h"
#include <stdlib.h>
using namespace std;
#pragma warning(disable : 4996);
//*******************************************

//Developed by Heorhii Sanchenko
//on 16.04.2022

//*******************************************

// default constructor
String::String() :
	_len(0),
	_allocator(new char[0])
{
#ifndef NDEBUG
	cout << "Default Constructor: " << *this << endl;
#endif
}

// C-string constructor
String::String(const char* str) :
	_len(strlen(str)),
	_allocator(new char[_len + 1])
{
	strcpy(_allocator, str);
#ifndef NDEBUG
	cout << "C-string Constructor: " << *this << endl;
#endif
}

// STL-string constructor
String::String(const string& s) :
	_len(s.length()),
	_allocator(new char[_len + 1])
{
	strcpy(_allocator, s.c_str());
#ifndef NDEBUG
	cout << "std::string Constructor: " << *this << endl;
#endif
}

// Copy constructor
String::String(const String& s) :
	_len(s.len()),
	_allocator(new char[_len + 1])
{
	strcpy(_allocator, s._allocator);
#ifndef NDEBUG
	cout << "Copy Constructor: " << *this << endl;
#endif
}

// Move constructor
String::String(String&& s) noexcept :
	_len(s._len),
	_allocator(s._allocator)
{
	s._len = 0;
	s._allocator = nullptr;
#ifndef NDEBUG
	cout << "Move Constructor: " << *this << endl;
#endif
}

// Destructor
String::~String() {
#ifndef NDEBUG
	cout << "Destructor: " << *this << endl;
#endif
	delete[] _allocator;
}

// Copy assignment
String& String::operator=(const String& s) {
	if (*this == s) return *this;
	delete[] _allocator;
	_len = s.len();
	_allocator = new char[_len + 1];
	strcpy(_allocator, s.allocator());
#ifndef NDEBUG
	cout << "Copy assignment: " << *this << endl;
#endif
	return *this;
}

// Move assignment
String& String::operator=(String&& s) noexcept {
	if (*this == s) return *this;
	delete[] _allocator;
	_len = s._len;
	_allocator = s._allocator;
	s._len = 0;
	s._allocator = nullptr;
#ifndef NDEBUG
	cout << "Move assignment: " << *this << endl;
#endif
	return *this;
}

//STL-string conversion operator
String::operator string() const {
	return string(_allocator);
}

// Indexing operator
const char& String::operator[](const size_t i) const {
	if (i >= _len || i < 0) throw i;
	return _allocator[i];
}

// combined concatenation assignment
String& String::operator+=(const String& s) {
	// create a longer allocator and copy the old one into it
	char* new_allocator = new char[_len + s.len() + 1];
	strcpy(new_allocator, _allocator);
	// delete the old one and make it point to the new one
	delete[] _allocator;
	_allocator = new_allocator;
	// copy the added string
	strcpy(new_allocator + _len, s.allocator());
	_len += s.len();
	return *this;
}

// combined concatenation assignment for C-string
String& String::operator+=(const char* s) {
	const size_t s_len = strlen(s);
	char* new_allocator = new char[_len + s_len + 1];
	strcpy(new_allocator, _allocator);
	delete[] _allocator;
	_allocator = new_allocator;
	strcpy(new_allocator + _len, s);
	_len += s_len;
	return *this;
}

// equality
bool operator==(const String& u, const String& v) {
	if (u.len() != v.len()) return false;
	for (size_t i = 0; i < v.len(); i++) {
		if (u.allocator()[i] != v.allocator()[i]) return false;
	}
	return true;
}

// inequality
bool operator!=(const String& u, const String& v) {
	return !(u == v);
}

// concatenation
String operator+(const String& u, const String& v) {
	return String(u) += v;
}

//output 
ostream& operator<<(ostream& os, const String& s) {
	for (size_t i = 0; i < s.len(); i++) {
		os << *(s.allocator() + i);
	}
	return os;
}