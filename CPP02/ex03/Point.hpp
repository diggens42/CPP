#ifndef POINT_H
#define POINT_H

#include "Fixed.hpp"

class Point {
	private:
		Fixed x;
		Fixed y;
	public:
		Point();
		Point(const float x, const float y);
		Point(const Point &other);
		Point& operator=(const Point &other);
		~Point();

		Fixed	getX() const;
		Fixed	getY() const;

};
Fixed	triangleArea(const Point& p1, const Point& p2, const Point& p3);
bool bsp(Point const a, Point const b, Point const c, Point const point);
#endif // POINT_H
