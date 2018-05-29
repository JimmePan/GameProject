
#pragma once
#include "Effect.h"

class SpellCardEffect final : public Effect
{
public:
	SpellCardEffect(int type);
	virtual ~SpellCardEffect() = default;
	bool update() override;
	void draw() const override;
};

