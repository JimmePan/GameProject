#pragma once
#include "Effect.h"

class DelEnemyEffect final : public Effect
{
public:
	DelEnemyEffect(float x, float y, int color);
	virtual ~DelEnemyEffect() = default;
	bool update() override;
	void draw() const override;
};

