///////Smovzhenko Anton

#pragma once

#include "Point.h"

class Segment
{
private:

	static int _freeID;
	const int _ID;

	Point _a;
	Point _b;

public:
	Segment(const double x1 = 0, const double y1 = 0, const double x2 = 1, const double y2 = 0);
		

	Segment(const Point& Start, const Point& End);

	Segment(const Segment&);

	~Segment();

	Segment& operator=(const Segment&);

	const Point& Start() const;
	const Point& End() const;


	Point& Start();
	Point& End();


	const double& StartX() const;
	const double& EndX() const;

	const double& StartY() const;
	const double& EndY() const;


	double& StartX();
	double& EndX();

	double& StartY();
	double& EndY();



	double length() const;

	double distan(const Point&) const;

	const int getId() const;
};

ostream& operator<<(ostream&, const Segment&);