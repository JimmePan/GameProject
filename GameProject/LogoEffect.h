#pragma once
#include "Effect.h"
class LogoEffect final : public Effect
{
public:
	LogoEffect(float x, float y, int num);
	virtual ~LogoEffect() = default;
	bool update() override;
	void draw() const override;
};

