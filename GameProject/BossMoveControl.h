#pragma once
class BossMoveControl
{
public:
	BossMoveControl();
	~BossMoveControl() = default;
	int _flag;
	int _count;
	int _setTime;
	float ax, v0x, ay, v0y, vx, vy, prex, prey;
};

