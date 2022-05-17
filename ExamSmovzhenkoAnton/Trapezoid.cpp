///////Smovzhenko Anton

#include "Trapezoid.h"
#include "Segment.h"

#define TOLERANCE 0.0000001

Trapezoid::Trapezoid(Point point1, Point point2, Point point3, Point point4)
{

	_points[0] = point1;
	_points[1] = point2;
	_points[2] = point3;
	_points[3] = point4;

	_clear_segments();

	this->_validateTrapezoid();

}

Trapezoid::Trapezoid(const Trapezoid& trapez)
{

	_points[0] = trapez._points[0];
	_points[1] = trapez._points[1];
	_points[2] = trapez._points[2];
	_points[3] = trapez._points[3];

	_clear_segments();

}

Trapezoid::Trapezoid(Trapezoid&& trapez)
{

	_points[0] = trapez._points[0];
	_points[1] = trapez._points[1];
	_points[2] = trapez._points[2];
	_points[3] = trapez._points[3];

	for (size_t i = 0; i < 4; i++)
	{
		_segments[i] = trapez._segments[i];
		trapez._segments[i] = nullptr;
	}

}

Trapezoid::~Trapezoid()
{
	for (size_t i = 0; i < 4; i++)
	{
		if (_segments[i] != nullptr) delete _segments[i];
	}

}

Trapezoid& Trapezoid::operator=(const Trapezoid& trapez)
{
	if (this == &trapez)
		return *this;
	_points[0] = trapez._points[0];
	_points[1] = trapez._points[1];
	_points[2] = trapez._points[2];
	_points[3] = trapez._points[3];
	for (size_t i = 0; i < 4; i++)
	{
		_segments[i] = new Segment(*trapez._segments[i]);
	}
	return *this;
}

Trapezoid& Trapezoid::operator=(Trapezoid&& trapez)
{
	if (this == &trapez)
		return *this;
	_points[0] = trapez._points[0];
	_points[1] = trapez._points[1];
	_points[2] = trapez._points[2];
	_points[3] = trapez._points[3];
	for (size_t i = 0; i < 4; i++)
	{
		_segments[i] = trapez._segments[i];
		trapez._segments[i] = nullptr;
	}
	return *this;
}

double Trapezoid::area() const
{
	double sumSides = getBC().length() + getAD().length();
	double height = getAD().distan(getB());
	return (sumSides * height / 2);
}

double Trapezoid::perimeter() const
{
	double sum = 0;
	for (size_t i = 0; i < 4; i++)
	{
		sum += _getSegment(i)->length();
	}
	return sum;
}

void Trapezoid::_setPoint(size_t i, Point&& point)
{
	_points[i] = point;
	this->_validateTrapezoid();
	_clear_segments();
}


Segment* Trapezoid::_getSegment(size_t i) const
{
	if (_segments[i] == nullptr) {
		if (i == 3) _segments[i] = new Segment(_points[0], _points[3]);
		else  _segments[i] = new Segment(_points[i], _points[i + 1]);
	}
	return _segments[i];
}


void Trapezoid::_validateTrapezoid()
{
	double xAD = getD().x() - getA().x();
	double yBC = getC().y() - getB().y();
	
	double xBC = getC().x() - getB().x();
	double yAD = getD().y() - getA().y();


	if (fabs(yBC / xBC - yAD / xAD) > TOLERANCE) {
		throw BadTrapezoid("CB isn't parallel to DA");
	}
}

void Trapezoid::_clear_segments()
{
	for (size_t i = 0; i < 4; i++)
	{
		_segments[i] = nullptr;
	}
}
