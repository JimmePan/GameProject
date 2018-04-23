#pragma once
#include "Cirno.h"
/*数字显示类*/
class Number
{
public:
	Number();
	Number(float number,int x,int y,int digit,int decimal);
	~Number();
	void draw();
private:
	float _number;	//具体数字
	int _x;
	int _y;
	int _digit;	//整数显示部分位数
	int _decimal;	//小数显示部分位数

};

