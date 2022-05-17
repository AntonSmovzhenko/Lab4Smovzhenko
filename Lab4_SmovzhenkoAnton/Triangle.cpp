#include <iostream>
using namespace std;

#include "Triangle.h"

int Triangle::Segment::_freeID = 0;




Triangle::Triangle(const double x1, const double y1, const double x2, const double y2, const double x3, const double y3) :
	_a(x1, y1),
	_b(x2, y2),
	_c(x3, y3),
	_ab(0),
	_bc(0),
	_ca(0),
	_medianaA(0),
	_medianaB(0),
	_medianaC(0) {
	checkTriangle(_a, _b, _c);

	cout << "Triangle by coordinates " << *this << endl;

	return;
}




Triangle::Triangle(const Point& a, const Point& b, const Point& c) :
	_a(a), _b(b), _c(c),
	_ab(0), _bc(0), _ca(0), _medianaA(0), _medianaB(0), _medianaC(0) {
	checkTriangle(_a, _b, _c);

	cout << "Triangle by points:  " << *this << endl;

	return;
}



Triangle::Triangle(const Triangle& t) :
	_a(t._a), _b(t._b), _c(t._c),
	_ab(0), _bc(0), _ca(0), _medianaA(0), _medianaB(0), _medianaC(0) {

	cout << "coping " << *this << endl;

	return;
}



Triangle::~Triangle() {
	delete _ab;
	delete _bc;
	delete _ca;
	delete _medianaA;
	delete _medianaB;
	delete _medianaC;


	_ab = nullptr;
	_bc = nullptr;
	_ca = nullptr;
	_medianaA = nullptr;
	_medianaB = nullptr;
	_medianaC = nullptr;

	cout << "Triangle deleted: " << *this << endl;

	return;
};

void Triangle::checkTriangle(Point& a, Point& b, Point& c) {
	double ab = a.length(b);
	double bc = b.length(c);
	double ca = c.length(a);
	//сума двох сторін трикутника має бути меншою або рівною третій
	if (((ab + bc) <= ca) || ((ab + ca) <= bc) || ((bc + ca) <= ab)) {
		throw BadTriangle(a, b, c);
	}
	return;
}




//////////////////////////////
Triangle& Triangle::operator=(const Triangle& t) {

	delete _ab;
	delete _bc;
	delete _ca;
	delete _medianaA;
	delete _medianaB;
	delete _medianaC;

	_ab = nullptr;
	_bc = nullptr;
	_ca = nullptr;
	_medianaA = nullptr;
	_medianaB = nullptr;
	_medianaC = nullptr;

	_a = t.apexA();
	_b = t.apexB();
	_c = t.apexC();
	return *this;
}
//////////////////////////////

double Triangle::length_a() const {
	return side_a().length();
}
double Triangle::length_b() const {
	return side_b().length();
}
double Triangle::length_c() const {
	return side_c().length();
}

const Triangle::Segment& Triangle::side_a() const {
	if (!_bc) {
		_bc = new Segment(_b, _c);
	}
	return *_bc;
}
const Triangle::Segment& Triangle::side_b() const {
	if (!_ca) {
		_ca = new Segment(_c, _a);
	}
	return *_ca;
}

const Triangle::Segment& Triangle::side_c() const {
	if (!_ab) {
		_ab = new Segment(_a, _b);
	}
	return *_ab;
}



	Point midA(0, 0);
	Point midB(0, 0);
	Point midC(0, 0);


	//toStrings
ostream& operator<<(ostream& os, const Triangle& t) {
	return os << "{" << t.apexA() << ";" << t.apexB() << ";" << t.apexC() << "}";
}

ostream& operator<<(ostream& os, const Triangle::BadTriangle& bt) {
	return os << "Wrong triangle {" << bt._a << ";" << bt._b << ";" << bt._c << "}";
}

//////////////////////////////


void mediana(const Point& start, const Point& end, Point& mid) {
	double midX = (start.x() + end.x()) / 2;
	double midY = (start.y() + end.y()) / 2;

	
	mid.y() = midY;
	mid.x() = midX;
}

Triangle::Segment::Segment(const Segment& s) :
	_a(s._a),
	_b(s._b),
	_myId(++_freeID) {
	cout << "Segment №" << _myId << " coping to " << *this << endl;
	return;
}

Triangle::Segment::Segment(const Point& start, const Point& end) :
	_a(start),
	_b(end), 
	_myId(++_freeID) {
	cout << "Segment №" << _myId << " : " << *this << endl;
	return;
}

//////////////////////////////

Triangle::Segment::~Segment() {
	cout << "Segment №" << _myId << " deleting" << endl;
	return;
}

Triangle::Segment::Segment(double x1, double y1, double x2, double y2) :
	_a(x1, y1),
	_b(x2, y2),
	_myId(++_freeID) {
	cout << "Segment №" << _myId << " : " << *this << endl;
	return;
}

//////////////////////////////

double Triangle::Segment::length()const {
	double valueX = pow(endX() - startX(), 2);
	double valueY = pow(endY() - startY(), 2);
	return sqrt(valueX + valueY);
}

const Triangle::Segment& Triangle::mediana_a() const {
	if (!_medianaA)
	{
		mediana(apexB(), apexC(), midA);
		_medianaA = new Segment(apexA(), midA);
	}
	return *_medianaA;

}

const Triangle::Segment& Triangle::mediana_b() const {
	if (!_medianaB)
	{
		mediana(apexA(), apexC(), midB);
		_medianaB = new Segment(apexB(), midB);
	}
	return *_medianaB;
}

const Triangle::Segment& Triangle::mediana_c() const {
	if (!_medianaC)
	{
		mediana(apexB(),
			apexA(),
			midC);
		_medianaC = new Segment(apexC(), midC);
	}
	return *_medianaC;
}


ostream& operator<<(ostream& ostr, const Triangle::Segment& s) {
	ostr << s.start() << " --> " << s.end();
	return ostr;
}

Triangle::Segment& Triangle::Segment::operator=(const Triangle::Segment& a)
{
	_a = a._a;
	_b = a._b;
	return *this;
}