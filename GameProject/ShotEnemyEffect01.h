#pragma once
#include "Effect.h"
class ShotEnemyEffect01 final :
	public Effect
{
public:
	ShotEnemyEffect01(float x, float y);		//type×Óµ¯ÀàÐÍ00
	virtual ~ShotEnemyEffect01() = default;
	bool update() override;
	void draw() const override;
};

