#pragma once
#include <iostream>
using namespace std;


class String {

private:
	size_t _len;
	char* _allocator;
public:

	String(); // default
	String(const char*); //C-string
	String(const string&); // STL-string
	String(const String&); // Copy
	String(String&&) noexcept; // Move
	~String();

	String& operator=(const String&); // Copy
	String& operator=(String&&) noexcept; // Move

	operator string() const;

	// selector-modifier
	size_t len() const { return _len; }
	// selector
	const char* allocator() const { return _allocator; }

	const char& operator[](const size_t) const;

	String& operator+=(const String&);
	String& operator+=(const char*);
};

bool operator==(const String&, const String&);
bool operator!=(const String&, const String&);

String operator+(const String&, const String&);
ostream& operator<<(ostream&, const String&);