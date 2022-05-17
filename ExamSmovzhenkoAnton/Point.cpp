///////Smovzhenko Anton

#include "Point.h"

#include <cmath>
#include <iostream>

using namespace std;


int Point::_freeID = 0;
Point::Point(double x, double y) : _pointID(_freeID++) {
	_x = x;
	_y = y;

	cout << "Point ID: " << _pointID << " x: " << _x << " y: " << _y << endl;
}

Point::Point(const Point& p) : _pointID(_freeID++) {
	_x = p._x;
	_y = p._y;

	cout << "Point ID: " << _pointID << " x: " << _x << " y: " << _y << endl;

}

Point::~Point() {

	cout << "Point ID: " << _pointID << " x: " << _x << " y: " << _y << endl;
}

const int Point::getId() const {
	return _pointID;
};

int Point::amount() {
	return _freeID;
};

Point& Point::operator=(const Point& p) {
	_x = p.x();
	_y = p.y();
	return *this;
};

double& Point::x() {
	return _x;
};
double& Point::y() {
	return _y;
};
const double& Point::x() const {
	return _x;
};
const double& Point::y() const {
	return _y;
};

ostream& operator<<(ostream& ostr, const Point& point) {
	ostr << "(" << point.x() << ";" << point.y() << ")";
	return ostr;
};
const Point operator+ (const Point& a, const Point& b) {
	const Point res(a.x() + b.x(), a.y() + b.y());
	return res;
};
Point& operator+=(Point& toAdd, const Point& adder) {
	toAdd.x() += adder.x();
	toAdd.y() += adder.y();
	return toAdd;
};
bool operator==(const Point& a, const Point& b) {
	const double precision = 0.000000001;
	return (abs(a.x() - b.x()) < precision) && (abs(a.y() - b.y()) < precision);
};
bool operator!=(const Point& a, const Point& b) {
	const double precision = 0.000000001;
	return (abs(a.x() - b.x()) > precision) || (abs(a.y() - b.y()) > precision);
};

