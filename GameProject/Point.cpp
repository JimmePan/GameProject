#include "Point.h"



Point::Point()
{
}

Point::Point(float posX, float posY)
{
	x = posX;
	y = posY;
}


Point::~Point()
{
}

Vector Point::getVec(Point p)
{
	return Vector(p.getX()-x,p.getY()-y);
}

float Point::distance(Point p2)
{
	return sqrt((x-p2.getX())*(x - p2.getX())+(y-p2.getY())*(y - p2.getY()));
}
