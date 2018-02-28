#pragma once
#include "AbstractEnemy.h"
/*
BigEnemy type:������Ƿ��б�����1�����У�0����û��
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
