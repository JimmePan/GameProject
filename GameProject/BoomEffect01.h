#pragma once

#pragma once
#include "Effect.h"
class BoomEffect01 final :
	public Effect
{
protected:
	int _imgCount;
	bool _turnFlag;

public:
	BoomEffect01(int imgCount);
	virtual ~BoomEffect01() = default;
	bool update() override;
	void draw() const override;
};
