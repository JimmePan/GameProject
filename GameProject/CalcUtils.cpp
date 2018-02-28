#include "CalcUtils.h"
#include <cmath>
#include <DxLib.h>

/*
@brief С�����pointλ�������룬ԭΪ��+point-1����������
*/
float CalcUtils::roundPoint(float val, int point)
{
	float temp;
	temp = val * pow(10.f, + point);
	temp = (int)(temp + 0.5f);
	temp = temp * pow(10.f, - point);
	return temp;

}

float CalcUtils::roundSize(float max, float min, int count)
{
	if (count / 60 % 2>0) {
		return max - count % 60 * ((max - min) / 60);
	}
	else {
		return min + count % 60 * ((max - min) / 60);
	}

}
