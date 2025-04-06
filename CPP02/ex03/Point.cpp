#include "Point.hpp"
#include <iostream>

// Default constructor
Point::Point() : x(0), y(0)
{
}

// Copy constructor
Point::Point(const Point &other) : x(other.x), y(other.y)
{
}
Point::Point(const float x, const float y) : x(x), y(y)
{
}
// Copy assignment operator
Point& Point::operator=(const Point &other)
{
	if (this != &other)
	{
		this->x = other.x;
		this->y = other.y;
	}
	return (*this);
}

// Destructor
Point::~Point()
{
}

Fixed	Point::getX() const
{
	return (this->x);
}

Fixed	Point::getY() const
{
	return (this->y);
}
