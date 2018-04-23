#pragma once
class Vector
{
public:
	Vector();
	~Vector();
	float x;
	float y;

	float getX() { return x; }
	float getY() { return y; }

	// 用户构造函数
	Vector(float posX, float posY);
	void absV();
	//矢量加法
	Vector operator+(Vector v);
	//矢量减法
	Vector operator-(Vector v);
	//数乘
	Vector operator*(float n);
	//数除
	Vector operator/(float n);
	//向量点积
	float dotMul(Vector v2);
	//向量叉乘
	float crossMul(Vector v2);
	//获取矢量长度
	float getLength();
	//向量单位化
	void Normalize();
};

