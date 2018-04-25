#pragma once
#include "Effect.h"

class BulletShotEffect final : public Effect
{
public:
	BulletShotEffect(float x, float y, int color);
	virtual ~BulletShotEffect() = default;
	bool update() override;
	void draw() const override;
};

