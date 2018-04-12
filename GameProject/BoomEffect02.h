#pragma once
#include "Effect.h"

class BoomEffect02 final :
	public Effect
{
protected:
public:
	BoomEffect02(float x, float y);	
	virtual ~BoomEffect02() = default;
	bool update() override;
	void draw() const override;
};

