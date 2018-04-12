#pragma once
#include "Effect.h"

class BulletBreakEffect final :
	public Effect
{
protected:
public:
	BulletBreakEffect(float x, float y, int color);		//type�ӵ�����00
	virtual ~BulletBreakEffect() = default;
	bool update() override;
	void draw() const override;
};

