#include "Point.h"
#include <iostream>
// Smovzhenko Anton
using namespace std;

//оголошення
int Point::_freeID = 0;

//creation
Point::Point(const double x, const double y) :
    _x(x), _y(y), _pointID(++_freeID)
{
    cout << "Creation of point " << *this << endl;
    return;
}

// deletion
Point::~Point()
{
    cout << "Deletion of point " << *this << endl;
    return;
}

//copying
Point::Point(const Point& u) :
    _x(u._x), _y(u._y), _pointID(++_freeID)
{
    cout << "Copying of point " << *this << endl;
    return;
}




/// /типу getters
const int Point::getID()const
{
    return _pointID;
}

//////////////coordinates
const double& Point::x()const
{
    return _x;
}
const double& Point::y()const
{
    return _y;
}
////////////////

double& Point::x()
{
    return _x;
}
double& Point::y()
{
    return _y;
}





//////////////
bool operator!=(const Point& u, const Point& v)
{
    return u.x() != v.x() &&
        u.y() != v.y();
}
bool operator==(const Point& u, const Point& v)
{
    return u.x() == v.x() &&
        u.y() == v.y();
}
/// ////////////



/// //////
Point& operator+=(Point& u, const Point& v)
{
    u.x() = u.x() + v.x();
    u.y() = u.y() + v.y();
    return u;
}
const Point operator+(const Point& u, const Point& v)
{
    return Point(u.x() + v.x(),
        u.y() + v.y());
}
Point& Point::operator=(const Point& w)
{
    _x = w._x;
    _y = w._y;
    return *this;
}
//////////////////////




//типу toString
ostream& operator<<(ostream& ostr, const Point& w)
{
    ostr << "id:" << w.getID() << " with coordinates: (" << w.x() << "," << w.y() << ')';
    return ostr;
}