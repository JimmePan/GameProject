#pragma once

#pragma once
#include "Effect.h"
class BoomEffect01 final :
	public Effect
{
protected:
	int _imgCount;		
	
public:
	BoomEffect01();		
	virtual ~BoomEffect01() = default;
	bool update() override;
	void draw() const override;
};
