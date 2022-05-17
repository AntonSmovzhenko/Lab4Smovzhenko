///////Smovzhenko Anton

#pragma once

#define TOLERANCE 0.0000001

#include <iostream>
#include <math.h>
#include "Point.h"
#include "Segment.h"

using namespace std;

class Trapezoid
{
public:
    class BadTrapezoid;

    Trapezoid(const double x1 = 0, const double y1 = 0,
        const double x2 = 1, const double y2 = 0,
        const double x3 = 1, const double y3 = 1,
        const double x4 = 0, const double y4 = 1)

        : Trapezoid(Point(x1, y1), Point(x2, y2),

            Point(x3, y3), Point(x4, y4)) {}

    Trapezoid(Point p1, Point p2,
        Point p3, Point p4);

    Trapezoid(const Trapezoid& trapez);
    Trapezoid(Trapezoid&& trapez);
    ~Trapezoid();

    Trapezoid& operator=(const Trapezoid& trapez);
    Trapezoid& operator=(Trapezoid&& trapez);

    const Point& getA() const { return _points[0]; }
    const Point& getB() const { return _points[1]; }
    const Point& getC() const { return _points[2]; }
    const Point& getD() const { return _points[3]; }

    const Segment& getAB() const { return *_getSegment(0); }
    const Segment& getBC() const { return *_getSegment(1); }
    const Segment& getCD() const { return *_getSegment(2); }
    const Segment& getAD() const { return *_getSegment(3); }

    void setA(const Point& point) { _setPoint(0, Point(point)); }
    void setB(const Point& point) { _setPoint(1, Point(point)); }
    void setC(const Point& point) { _setPoint(2, Point(point)); }
    void setD(const Point& point) { _setPoint(3, Point(point)); }


    void setA(double x, double y) { _setPoint(0, Point(x, y)); }
    void setB(double x, double y) { _setPoint(1, Point(x, y)); }
    void setC(double x, double y) { _setPoint(2, Point(x, y)); }
    void setD(double x, double y) { _setPoint(3, Point(x, y)); }

    void setA(Point&& point) { _setPoint(0, forward<Point>(point)); }
    void setB(Point&& point) { _setPoint(1, forward<Point>(point)); }
    void setC(Point&& point) { _setPoint(2, forward<Point>(point)); }
    void setD(Point&& point) { _setPoint(3, forward<Point>(point)); }

    double area() const;
    double perimeter() const;

private:
    Point _points[4];
    mutable Segment* _segments[4];

    void _setPoint(size_t index, Point&& point);
    Segment* _getSegment(size_t index) const;
    void _validateTrapezoid();
    void _clear_segments();
};

inline bool operator==(const Trapezoid& trapez1, const Trapezoid& trapez2) { return fabs(trapez1.area() - trapez2.area()) <= TOLERANCE; }
inline bool operator!=(const Trapezoid& trapez1, const Trapezoid& trapez2) { return !(trapez1 == trapez2); }

class Trapezoid::BadTrapezoid {

private:

    const string _reason;

public:

    BadTrapezoid
    (const string& reason = "unknown") : _reason(reason) {};
    inline const string& getReason() const {
        return _reason;
    }
};