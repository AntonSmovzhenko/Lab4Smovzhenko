#include <iostream>
using namespace std;

#include "Point.h"
int Point::_freeID = 0;

Point::Point(double x, double y) :
	_x(x), 
	_y(y), 
	_pointID(++_freeID) {
	return;
}

Point::Point(const Point& p) :
	_x(p._x), 
	_y(p._y),
	_pointID(++_freeID) {
	return;
}

//toString
ostream& operator<<(ostream& os, const Point& p)
{
	os << "(" << p.x() << ";" << p.y() << ")";
	return os;
}

Point::~Point() {
	return;
}

Point& Point::operator=(const Point& p)
{
	_y = p._y;
	_x = p._x;
	
	return *this;
}

//////////////////////////////
const Point operator+ (const Point& u, const Point& v) {
	return Point(u.x() + v.x(), u.y() + v.y());
}

Point& operator+=(Point& p1, const Point& p2) {
	p1.x() += p2.x();
	p1.y() += p2.y();

	return p1;
}

bool operator==(const Point& u, const Point& v) {

	return (u.x() == v.x()) &&
		(u.y() == v.y());
}

bool operator!=(const Point& u, const Point& v) {
	return u == v ? false : true;
}