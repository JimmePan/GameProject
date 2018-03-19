#include "EnemyShoter.h"
#include "Macro.h"
#include "Define.h"
#include "AbstractEnemy.h"
#include "Player.h"
#include "BulletManager.h"

EnemyShoter::EnemyShoter()
{
	setFunction();
}

void EnemyShoter::shot(AbstractEnemy * enemy)
{
	const unsigned int id = enemy->getShotPatternID();
	if (_shotPattern.size() <= id) {
		//ERR("shotId³ö´í");
	}
	(this->*_shotPattern[id])(enemy);	//¸ù¾ÝidÉä»÷

}

void EnemyShoter::setFunction()
{
	_shotPattern.push_back(&EnemyShoter::shotPattern00);
	_shotPattern.push_back(&EnemyShoter::shotPattern01);
	_shotPattern.push_back(&EnemyShoter::shotPattern02);
	_shotPattern.push_back(&EnemyShoter::shotPattern03);
	_shotPattern.push_back(&EnemyShoter::shotPattern04);
}

void EnemyShoter::shotPattern00(AbstractEnemy * enemy)
{
	const int cnt = enemy->getCounter();
	if (60 < cnt && cnt <= 2000 && cnt % 20 == 0) {
		BulletManager::add(enemy->getX(),enemy->getY(),0,0,0,enemy->shotatan2(),0.0,3,0.5);
		BulletManager::add(enemy->getX(), enemy->getY(), 7, 0, 0, enemy->shotatan2(), 0.0, 5, 1.0);
		BulletManager::add(enemy->getX(), enemy->getY(), 6, 0, 0, enemy->shotatan2(), 0.0, 7, 1.0);
	}
}

void EnemyShoter::shotPattern01(AbstractEnemy * enemy)
{
}

void EnemyShoter::shotPattern02(AbstractEnemy * enemy)
{
}

void EnemyShoter::shotPattern03(AbstractEnemy * enemy)
{
}

void EnemyShoter::shotPattern04(AbstractEnemy * enemy)
{
}
