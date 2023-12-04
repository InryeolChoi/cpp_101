#include "Point.hpp"

Fixed determinent(Point const v1, Point const v2) 
{
	return (v1.getX() * v2.getY() - v1.getY() * v2.getX());
}

Point vector(Point a, Point b) {
	Point vector = Point(b.getX() - a.getX(), b.getY() - a.getY());
	return vector;
}

int get_sign(Point a, Point b, Point c)
{
	// 벡터 2개를 만든다.
	Point const vec1 = vector(a, b);
	Point const vec2 = vector(b, c);

	// 벡터 2개로 행렬을 만들고, 그 행렬식을 구함.
	Fixed det = determinent(vec1, vec2);
	
	// ab, bc의 행렬식이 양수면 1, 아니면 -1
	if (det == 0)
		return 0;
	return (det > 0 ? 1 : -1);
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	int signs = get_sign(a, b, point) + get_sign(b, c, point) + get_sign(c, a, point);
	return (signs == 3 || signs == -3 ? true : false);
}