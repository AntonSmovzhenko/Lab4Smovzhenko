#include "Point.h"
#include <iostream>
using namespace std;


int Point::_freeID = 0;

Point::Point(const double x, const double y) :

    _x(x), _y(y), _pointID(++_freeID)
 {
    cout <<  "Create " << *this << endl;

    return;
}

Point::~Point()
{
    cout << "Delete " << *this << endl;
    return;
} 
  
Point::Point(const Point& u) :
    _x(u._x), _y(u._y), _pointID(++_freeID)
{
    cout << "Copy " << *this << endl;
    return;
}



const int Point::getID()const {  return _pointID;}

double& Point::x() { return _x; }
double& Point::y() { return _y; }
 
const double& Point ::x()const{ return _x;}
const double& Point::y()const{  return _y;}




 
bool operator==(const Point& u, const Point& v)
{
    return u.x() == v .x() &&
        u.y() == v.y();
}

Point& operator+=(Point& u, const Point& v)
{ 
    u.x() = u.x() + v.x();
    u.y() = u.y() + v.y();
    return u;
} 

bool operator!=(const Point& u, const Point& v)
{
    return u.x() != v.x() &&
        u.y() != v.y();
}


Point& Point::operator=(const Point& w) 
{
    _x = w._x; 
    _y = w._y; 
    return *this;
}

const Point operator+(const Point& u, const Point& v)
{ 
     return Point(u.x() + v.x(),
        u.y() + v.y());
} 



ostream& operator<<(ostream& ostr, const Point& w)
{
    ostr << "id:" << w.getID() << " coordinate: (" << w.x() << "," << w.y() << ')';
    return ostr;
}