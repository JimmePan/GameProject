#pragma once
#include "AbstractEnemy.h"

class Boss :public AbstractEnemy
{
public:
	Boss(float x, float y, int type, int hp, int movePatternID, int shotPatternID, int itemPatternID);
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
	const int* TIME;
	virtual void reset() = 0;
	virtual void changeMove() = 0;

	mutable bool _spellEffectFlag;

	void drawTime() const;

};
