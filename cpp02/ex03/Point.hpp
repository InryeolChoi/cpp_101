#pragma once
#include "Fixed.hpp"

class Point
{
	private:
		Fixed const x;
		Fixed const y;
	public:
		// Orthodox Canonical form
		Point();
		Point(const Point &p);
		Point &operator=(const Point &p);
		~Point();

		// other member func.
		Point(Fixed x, Fixed y);
		Point(float const x, float const y);
		Fixed getX(void) const;
		Fixed getY(void) const;
};

bool bsp(Point const a, Point const b, Point const c, Point const p);