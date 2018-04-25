#pragma once
#include "AbstractEnemy.h"
/*
NormalEnemy type»°÷µ∑∂Œß0,1,2,3,8,9,10,11
*/
class NormalEnemy final :public AbstractEnemy
{
public:
	NormalEnemy(float x, float y, int type, int hp, int movePatternID, int shotPatternID, int itemPatternID);
	~NormalEnemy() = default;
	void draw() const override;
protected:
	void setSize() override;
};

