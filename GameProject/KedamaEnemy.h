#pragma once
#pragma once
#include "AbstractEnemy.h"
/*
KedamaEnemyë�� typeȡֵ��Χ0,1,2,3
*/
class KedamaEnemy final :public AbstractEnemy
{
public:
	KedamaEnemy(float x, float y, int type, int hp, int movePatternID, int shotPatternID, int itemPatternID);
	~KedamaEnemy() = default;
	void draw() const override;
protected:
	void setSize() override;
};