#pragma once
#include "Effect.h"
class ShotEnemyEffect01 final :
	public Effect
{
protected:
	int _imgCount;		//ͼ����ʼλ��
public:
	ShotEnemyEffect01(float x,float y);		//type�ӵ�����
	virtual ~ShotEnemyEffect01() = default;
	bool update() override;
	void draw() const override;
};

