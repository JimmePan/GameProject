#pragma once
#include "Vector.h"
#include "Cirno.h"
class Point
{
public:
	Point();
	Point(float posX, float posY);
	~Point();
	float x;
	float y;

	float getX() { return x; }
	float getY() { return y; }

	Vector getVec(Point p);

	float distance(Point p2);	//¡Ωµ„º‰æ‡¿Î
};

