
#pragma once
#include "AbstractEnemy.h"
/*
UFOEnemy UFO type»°÷µ∑∂Œß0,1,2,3
*/
class UFOEnemy final :public AbstractEnemy
{
public:
	UFOEnemy(float x, float y, int type, int hp, int movePatternID, int shotPatternID, int itemPatternID);
	~UFOEnemy() = default;
	void draw() const override;
	mutable float _baseAngle;
protected:
	void setSize() override;

};