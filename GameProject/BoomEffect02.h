#pragma once
#include "Effect.h"

class BoomEffect02 final :
	public Effect
{
protected:
public:
	BoomEffect02(float x, float y, float angle);
	virtual ~BoomEffect02() = default;
	bool update() override;
	void draw() const override;
protected:
	float _speed;
	float _baseAngle;
	int _i;
};

