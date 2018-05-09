#pragma once
#include "AbstractEnemy.h"
/*
YinyangEnemy type»°÷µ∑∂Œß0,1,2,3
*/
class YinyangEnemy final :public AbstractEnemy
{
public:
	YinyangEnemy(float x, float y, int type, int hp, int movePatternID, int shotPatternID, int itemPatternID);
	~YinyangEnemy() = default;
	void draw() const override;
protected:
	void setSize() override;
};