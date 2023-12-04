#include "Fixed.hpp"
#include "Point.hpp"

int main( void )
{
	Point a(5, 5);
	Point b(2, 8);
	Point c(0, 7);
	Point p(3, 1);

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