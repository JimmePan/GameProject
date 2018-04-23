#pragma once
#include "Effect.h"

class GrazeEffect final :
	public Effect
{
public:
	GrazeEffect(float x, float y);	
	virtual ~GrazeEffect() = default;
	bool update() override;
	void draw() const override;
private:
	float _speed;
};