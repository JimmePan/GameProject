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
		//ERR("shotId出错");
	}
	(this->*_shotPattern[id])(enemy);	//根据id射击

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
		BulletManager::add(enemy->getX(), enemy->getY(), 0, 0, 0, enemy->shotatan2(), 0.0, 3, 0.5);
		//BulletManager::add(enemy->getX(), enemy->getY(), 7, 0, 0, enemy->shotatan2(), 0.0, 5, 1.0);
		//BulletManager::add(enemy->getX(), enemy->getY(), 6, 0, 0, enemy->shotatan2(), 0.0, 7, 1.0);
	}
}
/*Bullet(float x, float y,unsigned int type, unsigned int color,int state,float angle,float base_angle,float speed,float rate)*/
/*琪露诺，完美冻结*/
void EnemyShoter::shotPattern01(AbstractEnemy * enemy)
{
	int i, t = enemy->getBossCount() % 650;
	//最开始的随机发射
	if (t < 180) {
		for (i = 0; i < 2; i++) {//1次计数发射2次
			BulletManager::add(enemy->getX(), enemy->getY(), 8, rand() % 7, 0, (float)(rand() / double(RAND_MAX)*Define::PI * 2),
				0.0f, 3.2f + rand() / double(RAND_MAX)*2.1f, 1.0f);
		}
		/*if (t % 10 == 0)
			se_flag[0] = 1;*/
	}
	if (210 < t && t < 270 && t % 3 == 0) {
		float angle = enemy->shotatan2();
		for (i = 0; i < 8; i++) {
			BulletManager::add(enemy->getX(), enemy->getY(), 8, 0, 2, 
				angle - Define::PI / 2 * 0.8 + Define::PI * 0.8 / 7 * i + rand() / double(RAND_MAX)*(Define::PI / 180) , 0.0f, 
				3.0f + rand() / double(RAND_MAX)*0.3f, 1.0f);
		}

		/*if (t % 10 == 0)
			se_flag[0] = 1;*/
	}
	for (auto it = BulletManager::getListBig()->begin(); it != BulletManager::getListBig()->end();) {
		if ((*it)->getFlag()>0) {
			if ((*it)->getState() == 0) {
				if (t == 190) {
					(*it)->setSpeed(0.f);
					(*it)->setColor(7);
					(*it)->setCount(0);
					(*it)->setState(1);
				}
			}
			if ((*it)->getState() == 1) {
				if ((*it)->getCount() == 200) {
					(*it)->setAngle(rand() / double(RAND_MAX)*(Define::PI));
				}
				if ((*it)->getCount() > 200) {
					(*it)->setSpeed((*it)->getSpeed()+0.01f);
				}
			}
		}
			it++;		
	}
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
