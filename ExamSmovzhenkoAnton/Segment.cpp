///////Smovzhenko Anton

#include "Segment.h"
#include <cmath>

#include <iostream>

using namespace std;

int Segment::_freeID = 0;

void debug(const Segment& s) {
	cout << "id: " << s.getId() << " Start: " << s.Start() << " End: " << s.End() << endl;
}

Segment::Segment(const double x1, const double y1, const double x2, const double y2) : _ID(_freeID++) {
	_a = Point(x1, y1);
	_b = Point(x2, y2);
	debug(*this);
}

Segment::Segment(const Point& Start, const Point& End) : _ID(_freeID++) {
	_a = Point(Start.x(), Start.y());
	_b = Point(End.x(), End.y());
	debug(*this);
}

Segment::Segment(const Segment& segment) : _ID(_freeID++) {
	_a = Point(segment.StartX(), segment.StartY());
	_b = Point(segment.EndX(), segment.EndY());
	debug(*this);
}

Segment::~Segment() {
	debug(*this);
}

const Point& Segment::Start() const {
	return _a;
};
const Point& Segment::End() const {
	return _b;
};

Point& Segment::Start() {
	return _a;
};
Point& Segment::End() {
	return _b;
};

const double& Segment::StartX() const {
	return _a.x();
};
const double& Segment::StartY() const {
	return _a.y();
};
const double& Segment::EndX() const {
	return _b.x();
};
const double& Segment::EndY() const {
	return _b.y();
};

// Selectors and modifiters of points
double& Segment::StartX() {
	return _a.x();
};
double& Segment::StartY() {
	return _a.y();
};
double& Segment::EndX() {
	return _b.x();
};
double& Segment::EndY() {
	return _b.y();
};

double Segment::length() const {
	return sqrt(pow(_a.x() - _b.x(), 2) + pow(_a.y() - _b.y(), 2));
}

const int Segment::getId() const {
	return _ID;
};

Segment& Segment::operator=(const Segment& segment) {
	_a = segment._a;
	_b = segment._b;
	return *this;
};

ostream& operator<<(ostream& ostr, const Segment& s) {
	ostr << "Start : " << s.Start() << " End : " << s.End();
	return ostr;
}

double Segment::distan(const Point& point) const {

	double Ax = point.x() - this->StartX();
	double Ay = point.y() - this->StartY();

	double Sx = this->EndX() - this->StartX();
	double Sy = this->EndY() - this->StartY();

	const double dotProduct = Ax * Sx + Ay * Sy;
	const double lengthSquare = Sx * Sx + Sy * Sy;
	double projection = -1;
	if (lengthSquare != 0)
		projection = dotProduct / lengthSquare;

	double baseX, baseY;
	baseX = this->StartX() + projection * Sx;
	baseY = this->StartY() + projection * Sy;

	const double lx = point.x() - baseX;
	const double ly = point.y() - baseY;
	return sqrt(lx * lx + ly * ly);
}