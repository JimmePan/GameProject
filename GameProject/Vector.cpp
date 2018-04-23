#include "Vector.h"
#include "cmath"

Vector::Vector()
{
}
Vector::~Vector()
{
}
Vector::Vector(float posX, float posY)
{
	x = posX;
	y = posY;
}

void Vector::absV()
{
	x = abs(x);
	y = abs(y);
}

Vector Vector::operator+(Vector v)
{
	return Vector(x + v.x, v.y + y);
}
Vector Vector::operator-(Vector v)
{
	return Vector(x - v.x, y - v.y);
}
Vector Vector::operator*(float n)
{
	return Vector(x*n, y*n);
}
Vector Vector::operator/(float n)
{
	return Vector(x / n, y / n);
}
float Vector::dotMul(Vector v2)
{
	return (x*v2.x + y * v2.y);
}
float Vector::crossMul(Vector v2)
{
	return (x*v2.y+y*v2.x);

}
float Vector::getLength()
{
	return (float)sqrt(x*x + y * y);
}
void Vector::Normalize()
{
	float length = getLength();
	x = x / length;
	y = y / length;
}