#pragma once
#include "Effect.h"

class ShotEnemyEffect02 final :
	public Effect
{

public:
	ShotEnemyEffect02(float x, float y);		//type�ӵ�����01
	virtual ~ShotEnemyEffect02() = default;
	bool update() override;
	void draw() const override;
};

