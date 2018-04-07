#pragma once
#include "AbstractEnemy.h"
#include "BossMoveControl.h"

class Boss :public AbstractEnemy
{
public:
	Boss(float x, float y, int type,int hp);
	virtual ~Boss() = default;
	
	bool update() override;
	int getBossCounter() const { return _bossCount; }

protected:
	float _dx;
	float _dy;
	int _waitTime;
	int _state;
	int _endTime;
	const int* MOVER;
	const int* SHOTER;
	const int* HP;
	const int* ITEM;
	virtual void reset() = 0;
	virtual void changeMove() = 0;

};
