#pragma once

#include <vector>
#include <memory>
#include "BossMoveControl.h"

class AbstractEnemy;

class EnemyMover
{
public:
	EnemyMover();
	virtual ~EnemyMover() = default;
	void move(AbstractEnemy* enemy);
	void moveWithConstantAcceleration(AbstractEnemy* enemy, float x, float y, int t);
private:
	BossMoveControl phy;

	typedef void(EnemyMover::*FUNC)(AbstractEnemy* enemy);
	std::vector<FUNC> _movePattern;
	void setFunction();

	void movePattern00(AbstractEnemy *enemy);
	void movePattern01(AbstractEnemy *enemy);
	void movePattern02(AbstractEnemy *enemy);
	void movePattern03(AbstractEnemy *enemy);
	void movePattern04(AbstractEnemy *enemy);
	void movePattern05(AbstractEnemy *enemy);
	void movePattern06(AbstractEnemy *enemy);
	void movePattern07(AbstractEnemy *enemy);
	void movePattern08(AbstractEnemy *enemy);
	void movePattern09(AbstractEnemy *enemy);
	void movePattern10(AbstractEnemy *enemy);
	void movePattern11(AbstractEnemy *enemy);
	void movePattern12(AbstractEnemy *enemy);
	void movePattern13(AbstractEnemy *enemy);
	void movePattern14(AbstractEnemy *enemy);
	void movePattern15(AbstractEnemy *enemy);
	void movePattern16(AbstractEnemy *enemy);
	void movePattern17(AbstractEnemy *enemy);
	void movePattern18(AbstractEnemy *enemy);
	void movePattern19(AbstractEnemy *enemy);
	void movePattern20(AbstractEnemy *enemy);
	void movePattern21(AbstractEnemy *enemy);
	void movePattern22(AbstractEnemy *enemy);
	void movePattern23(AbstractEnemy *enemy);
	void movePattern24(AbstractEnemy *enemy);
	void movePattern25(AbstractEnemy *enemy);
	void movePattern26(AbstractEnemy *enemy);
	void movePattern27(AbstractEnemy *enemy);
	void movePattern28(AbstractEnemy *enemy);
	void movePattern29(AbstractEnemy *enemy);
	void movePattern30(AbstractEnemy *enemy);
	void movePattern31(AbstractEnemy *enemy);
	void movePattern32(AbstractEnemy *enemy);
	void movePattern33(AbstractEnemy *enemy);
};

