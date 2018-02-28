#pragma once
class CalcUtils
{
public:
	CalcUtils() = delete;

	static float roundPoint(float val, int point);
	static float roundSize(float max,float min,int count);
};

