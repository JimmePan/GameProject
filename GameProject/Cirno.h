#pragma once
#include "Boss.h"
#include "BossHp.h"
class Cirno :
	public Boss
{
public:
	Cirno(float x, float y, int type, int hp);
	~Cirno() = default;
	void draw() const override;

protected:
	void reset() override;
	void changeMove() override;
	void setSize() override;
private:
	BossHp bossHp;
};
