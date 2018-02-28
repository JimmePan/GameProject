#pragma once
#include "AbstractEnemy.h"
/*
BigEnemy type:大蝴蝶是否有背景，1代表有，0代表没有
*/
class BigEnemy final :public AbstractEnemy
{
public:
	BigEnemy(float x, float y, int type, int hp);
	~BigEnemy() = default;
	void draw() const override;
protected:
	void setSize() override;
};
