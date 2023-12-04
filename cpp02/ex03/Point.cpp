#include "Point.hpp"

// Orthodox Canonical form
Point::Point() : x(0), y(0) {}

Point::Point(const Point &p) : x(p.getX()), y(p.getY()) {}

Point &Point::operator=(const Point &p)
{
	if (this != &p)
	{
		const_cast<Fixed&>(x) = p.getX();
		const_cast<Fixed&>(y) = p.getY();
	}
	return (*this);
}

Point::~Point() {}

// other member func.
Point::Point(float const x, float const y) : x(x), y(y) {}

Point::Point(Fixed x, Fixed y) : x(x), y(y) {}

Fixed Point::getX(void) const
{
	return (x);
}

Fixed Point::getY(void) const
{
	return (y);
}
