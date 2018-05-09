#pragma once
#include "AbstractEnemy.h"
/*
CycloneEnemy type»°÷µ∑∂Œß0,1,2,3
*/
class CycloneEnemy final :public AbstractEnemy
{
public:
	CycloneEnemy(float x, float y, int type, int hp, int movePatternID, int shotPatternID, int itemPatternID);
	~CycloneEnemy() = default;
	void draw() const override;
protected:
	void setSize() override;
};