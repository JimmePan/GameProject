#include "EnemyMover.h"
#include "Macro.h"
#include "Define.h"
#include "AbstractEnemy.h"


EnemyMover::EnemyMover()
{
	setFunction();
}

void EnemyMover::move(AbstractEnemy * enemy)
{
	const unsigned int id = enemy->getMovePatternID();
	if (_movePattern.size() <= id) {
		//ERR("moveID出错");
	}
	(this->*_movePattern[id])(enemy);	//根据id移动
	enemy->setX(enemy->getX() + cos(enemy->getAngle())*enemy->getSpeed());
	enemy->setY(enemy->getY() + sin(enemy->getAngle())*enemy->getSpeed());
}

/*
将函数指针设置为列表
*/
void EnemyMover::setFunction()
{
	_movePattern.push_back(&EnemyMover::movePattern00);
	_movePattern.push_back(&EnemyMover::movePattern01);
	_movePattern.push_back(&EnemyMover::movePattern02);
	_movePattern.push_back(&EnemyMover::movePattern03);
	_movePattern.push_back(&EnemyMover::movePattern04);
}
/*向下，停顿后，向下*/
void EnemyMover::movePattern00(AbstractEnemy * enemy)
{
	const int cnt = enemy->getCounter();
	const int wait = 180;
	if (0 == cnt) {
		enemy->setAngle(Define::PI / 2);
		enemy->setSpeed(3);
	}
	if (60 < cnt && cnt <= 90) {
		enemy->setSpeed(enemy->getSpeed() - 0.1f);
	}
	/*if (90 + wait < cnt && cnt <= 90 + wait + 30) {
		enemy->setSpeed(enemy->getSpeed() + 0.1f);
	}*/
}
//左下移动
void EnemyMover::movePattern01(AbstractEnemy * enemy)
{
	int cnt = enemy->getCounter();
	if (0 == cnt) {
		enemy->setAngle(Define::PI * 3 / 4);
		enemy->setSpeed(4);
	}
	if (60 == cnt) {
		enemy->setAngle(Define::PI * 1 / 4);
		enemy->setSpeed(4);
	}
	if (120 == cnt) {
		enemy->setAngle(Define::PI * 2 / 4);
		enemy->setSpeed(4);
	}
	if (180 == cnt) {
		enemy->setAngle(Define::PI * 1 / 4);
		enemy->setSpeed(4);
	}
}

void EnemyMover::movePattern02(AbstractEnemy * enemy)
{
	int cnt = enemy->getCounter();
	if (0 == cnt) {
		enemy->setAngle(Define::PI * 1 / 4);
		enemy->setSpeed(4);
	}
}

void EnemyMover::movePattern03(AbstractEnemy * enemy)
{
}

void EnemyMover::movePattern04(AbstractEnemy * enemy)
{
}


