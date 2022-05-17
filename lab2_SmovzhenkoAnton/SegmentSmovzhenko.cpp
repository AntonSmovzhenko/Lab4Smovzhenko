#include "Segment.h"

#include <iostream>
// Smovzhenko Anton
using namespace std;

//оголошення
int Segment::_freeID = 0;


////////////////////////////////////
Segment::Segment(const Point& a, const Point& b) :
    _a(a), _b(b), _myId(++_freeID) {
#ifndef NDEBUG
    cout << _myId << " Creation of point " << *this;
#endif
}

Segment::Segment(const double x1, const double y1, const double x2, const double y2) :
    _a(x1, y1), _b(x2, y2), _myId(++_freeID) {
#ifndef NDEBUG
    cout << _myId << " Creation of point " << *this;
#endif
}
////////////////////////////////////


///////////////////////////////////////
Segment::Segment(const Segment& s) :
    _a(s._a), _b(s._b), _myId(++_freeID) {
    cout << s._myId << " Copying of segment " << *this << endl;
    return;
}
/// ////////////////////////////////////



//////////////////////////////
Segment::~Segment() {
    cout << _myId << " Deletion of point " << *this << endl;
    return;
}
/////////////////////////////////


Segment& Segment::operator=(const Segment& s) {
    _a = s._a; _b = s._b;
    return *this;
}


//////////////////////
const double& Segment::startX() const {
    return _a.x();
};

const double& Segment::startY() const {
    return _a.y();
};

const Point& Segment::start() const {
    return _a;
};

const double& Segment::endX() const {
    return _b.x();
};

const double& Segment::endY() const {
    return _b.y();
};

const Point& Segment::end() const {
    return _b;
};
//////////////////////////////////


///////////////////////////
Point& Segment::start() {
    return _a;
};

Point& Segment::end() {
    return _b;
};
////////////////////////////


/////////////////////////////////
double& Segment::startX() {
    return _a.x();
};

double& Segment::startY() {
    return _a.y();
};

double& Segment::endX() {
    return _b.x();
};

double& Segment::endY() {
    return _b.y();
};
///////////////////////////////////


/////////////////////calc of length
double Segment::length() const {
    return sqrt((endY() - startY()) * (endY() - startY())+ (endX() - startX()) * (endX() - startX()));
};
////////////////////////

////////////////////////calc of distance
double Segment::distance(const Point& p) const {
    return abs((endY() - startY()) * p.x() - (endX() - startX()) * p.y() + endX() * startY() - startX() * endY()) / length();
};
///////////////////////////////





//idшнік
const int Segment::getID() const {
    return _myId;
};
///////////////////

//toString
ostream& operator<<(ostream& ostr, const Segment& s) {
    ostr << "id:" << s.getID() << " start: (" << s.startX() << ", " << s.startY() << "); finish: (" << s.endX() << ", " << s.endY() << ")";
    return ostr;
};