#pragma once


#include <iostream>
using namespace std;


#include "Point.h"
#include "Segment.h"



class Triangle
{
public:
	class Segment;
	struct BadTriangle;

	Triangle(const double x1 = 0,
		const double y1 = 0,
		const double x2 = 1,
		const double y2 = 0,
		const double x3 = 0,
		const double y3 = 1);

	Triangle(const Point& a,
		const Point& b,
		const Point& c);

	Triangle(const Triangle&);

	~Triangle();

	Triangle& operator= (const Triangle&);

//вершини
	const Point& apexA() const { return _a; };
	const Point& apexB() const { return _b; };
	const Point& apexC() const { return _c; };

	Point& apexA(Point& p) {
		_bc = 0;
		_a = p;
		checkTriangle(_a, _b, _c);

		return _a;
	};

	Point& apexC(Point& p) {
		_ab = 0;
		_c = p;
		checkTriangle(_a, _b, _c);

		return _c;
	};

	Point& apexB(Point& p) {
		_ca = 0;
		_b = p;
		checkTriangle(_a, _b, _c);

		return _b;
	};

	


	const Segment& side_a() const;
	const Segment& side_b() const;
	const Segment& side_c() const;

	double length_a() const;
	double length_b() const;
	double length_c() const;

	const Segment& mediana_a() const;
	const Segment& mediana_b() const;
	const Segment& mediana_c() const;

private:
	Point _a, _b, _c;
	mutable Segment* _ab, * _bc, * _ca;
	mutable Segment* _medianaA, * _medianaB, * _medianaC;
	void checkTriangle(Point& a, Point& b, Point& c);
};

struct Triangle::BadTriangle {
	Point _a;
	Point _b;
	Point _c;
	BadTriangle(Point& a, Point& b, Point& c) :_a(a),
		_b(b),
		_c(c) {
		return;
	};
};

ostream& operator<<(ostream&, const Triangle&);

ostream& operator<<(ostream& os, const Triangle::BadTriangle& bt);


class Triangle::Segment
{
private:
	static int _freeID;
	const int _myId;
	Point _a;
	Point _b;


public:

	Segment(const double x1 = 0, const double y1 = 0,
		const double x2 = 1, const double y2 = 0);

	Segment(const Point& start, const Point& end);

	Segment(const Segment&);

	~Segment();


	Segment& operator=(const Segment&);

	const Point& start() const { return _a; };
	const Point& end() const { return _b; };

	Point& start() { return _a; };
	Point& end() { return _b; };
	/// <summary>
	/// ////////////////////////////////
	/// </summary>
	/// <returns></returns>
	const double& startX() const { return _a.x(); };
	const double& startY() const { return _a.y(); };

	const double& endX() const { return _b.x(); };
	const double& endY() const { return _b.y(); };

	/// <summary>
	/// //////////////////////////////
	/// </summary>
	/// <returns></returns>
	double& startX() { return _a.x(); };
	double& startY() { return _a.y(); };

	double& endX() { return _b.x(); };
	double& endY() { return _b.y(); };

	double length() const;


	double distance(const Point&) const;

	const int getID() const { return _myId; };
};

ostream& operator<<(ostream&, const Triangle::Segment&);