#pragma once
#include <iostream>
using namespace std;

class Point
{
private:

	const int _pointID;
	static int _freeID;

	double _x;
	double _y;

public:

	Point(double x = 0, double y = 0);
	Point(const Point&);

	~Point();
	Point& operator=(const Point&);

	
	const double& x()const {
		return _x;
	};

	const double& y()const {
		return _y;
	};

	double& y() {
		return _y;
	};

	double& x() {
		return _x;
	};
	
	static int amount() {
		return _freeID;
	}

	const int getID() const {
		return _pointID;
	};

	double length(const Point& p) {
		return sqrt((p.x() - x()) * (p.x() - x()) + (p.y() - y()) * (p.y() - y()));
	}
};

ostream& operator<<(ostream&, const Point&);

const Point operator+ (const Point& u, const Point& v);

Point& operator+=(Point&, const Point&);

bool operator!=(const Point& u, const Point& v);

bool operator==(const Point& u, const Point& v);
