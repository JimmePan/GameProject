#pragma once
#include "Effect.h"
class DelEnemyEffect2 final : public Effect
{
public:
	DelEnemyEffect2(float x, float y, int color);
	virtual ~DelEnemyEffect2() = default;
	bool update() override;
	void draw() const override;
};

