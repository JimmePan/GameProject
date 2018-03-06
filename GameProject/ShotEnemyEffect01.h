#pragma once
#include "Effect.h"
class ShotEnemyEffect01 final :
	public Effect
{
protected:
	int _imgCount;		//图像起始位置
public:
	ShotEnemyEffect01(float x,float y);		//type子弹类型
	virtual ~ShotEnemyEffect01() = default;
	bool update() override;
	void draw() const override;
};

