#include "Point.h"



Point::Point()
{
	x_ = 0;
	y_ = 0;
}

Point::Point(int x, int y)
{
	x_ = x;
	y_ = y;
}

Point::Point(int x, int y, Direction direction)
{
	if (direction == TOP)
	{
		x_ = x;
		y_ = y - 1;
	}
	if (direction == RIGHT)
	{
		x_ = x + 1;
		y_ = y;
	}
	if (direction == DOWN)
	{
		x_ = x;
		y_ = y + 1;
	}
	if (direction == LEFT)
	{
		x_ = x - 1;
		y_ = y;
	}
}

Point::~Point()
{
}

int Point::getX() const
{
	return x_;
}
int Point::getY() const
{
	return y_;
}
void Point::setXY(const int x, const int y)
{
	x_ = x;
	y_ = y;
}
void Point::setX(const int x)
{
	x_ = x;
}
void Point::setY(const int y)
{
	y_ = y;
}

void Point::addToX(const int liczba)
{
	x_ += liczba;
}
void Point::addToY(const int liczba)
{
	y_ += liczba;
}

bool Point::equals(const int x, const int y)
{
	return x_ == x && y_ == y;
}

bool Point::aroundPoint(const int x, const int y)
{
	if (x_ + 1 >= x && x_ - 1 <= x && y_ + 1 >= y && y_ - 1 <= y)
	{
		return true;
	}
	return false;
}

