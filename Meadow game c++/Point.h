#pragma once
#ifndef POINT_H
#define POINT_H
#include "CONSTS.h"
class Point
{

public:
	Point();
	Point(int x, int y);
	Point(int x, int y, Direction direction);
	~Point();

	int getX() const;
	int getY() const;
	void setXY(const int x, const int y);
	void setX(const int x);
	void setY(const int y);
	void addToX(const int liczba);
	void addToY(const int liczba);
	bool equals(const int x, const int y);
	bool aroundPoint(const int x, const int y); //checks if x,y is near this (near=one distance difference 'circle')

protected:
	bool operator==(const Point& point) const { return this->getX() == point.getX() && this->getY() == point.getY(); }
	int x_;
	int y_;
private:

};

#endif /*POINT_H */