#include "Fixed.hpp"
#include "Point.hpp"

int main( void )
{
	Point a(5, 0);
	Point b(0, 0);
	Point c(0, 5);
	Point p(0, 3);

	std::cout << "a, b, c are points in triangle" << std::endl;
	std::cout << "a = (" << a.getX() << ", " << a.getY() << ")" << std::endl;
	std::cout << "b = (" << b.getX() << ", " << b.getY() << ")" << std::endl;
	std::cout << "c = (" << c.getX() << ", " << c.getY() << ")" << std::endl;

	std::cout << std::endl;
	std::cout << "p = (" << p.getX() << ", " << p.getY() << ")" << std::endl;

	if (bsp(a, b, c, p))
		std::cout << "Point p is in the triangle" << std::endl;
	else
		std::cout << "Point p is not in triangle" << std::endl;
	return 0;
}