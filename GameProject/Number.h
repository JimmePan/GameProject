#pragma once
#include "Cirno.h"
/*������ʾ��*/
class Number
{
public:
	Number();
	Number(float number,int x,int y,int digit,int decimal);
	~Number();
	void draw();
private:
	float _number;	//��������
	int _x;
	int _y;
	int _digit;	//������ʾ����λ��
	int _decimal;	//С����ʾ����λ��

};

