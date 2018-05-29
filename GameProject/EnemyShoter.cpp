#include "EnemyShoter.h"
#include "Macro.h"
#include "Define.h"
#include "AbstractEnemy.h"
#include "Player.h"
#include "BulletManager.h"
#include "Sound.h"
#include "EffectManager.h"
#include "EnemyManager.h"


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
	_shotPattern.push_back(&EnemyShoter::shotPattern05);
	_shotPattern.push_back(&EnemyShoter::shotPattern06);
	_shotPattern.push_back(&EnemyShoter::shotPattern07);
	_shotPattern.push_back(&EnemyShoter::shotPattern08);
	_shotPattern.push_back(&EnemyShoter::shotPattern09);
	_shotPattern.push_back(&EnemyShoter::shotPattern10);
	_shotPattern.push_back(&EnemyShoter::shotPattern11);
	_shotPattern.push_back(&EnemyShoter::shotPattern12);
	_shotPattern.push_back(&EnemyShoter::shotPattern13);
	_shotPattern.push_back(&EnemyShoter::shotPattern14);
	_shotPattern.push_back(&EnemyShoter::shotPattern15);
	_shotPattern.push_back(&EnemyShoter::shotPattern16);
	_shotPattern.push_back(&EnemyShoter::shotPattern17);
	_shotPattern.push_back(&EnemyShoter::shotPattern18);
	_shotPattern.push_back(&EnemyShoter::shotPattern19);
	_shotPattern.push_back(&EnemyShoter::shotPattern20);
	_shotPattern.push_back(&EnemyShoter::shotPattern21);
	_shotPattern.push_back(&EnemyShoter::shotPattern22);
	_shotPattern.push_back(&EnemyShoter::shotPattern23);
	_shotPattern.push_back(&EnemyShoter::shotPattern24);
	_shotPattern.push_back(&EnemyShoter::shotPattern25);
	_shotPattern.push_back(&EnemyShoter::shotPattern26);
	_shotPattern.push_back(&EnemyShoter::shotPattern27);
	_shotPattern.push_back(&EnemyShoter::shotPattern28);
	_shotPattern.push_back(&EnemyShoter::shotPattern29);
	_shotPattern.push_back(&EnemyShoter::shotPattern30);
	_shotPattern.push_back(&EnemyShoter::shotPattern31);
	_shotPattern.push_back(&EnemyShoter::shotPattern32);
	_shotPattern.push_back(&EnemyShoter::shotPattern33);
}
/*无弹幕*/
void EnemyShoter::shotPattern00(AbstractEnemy * enemy)
{
	/*if (enemy->getBossCount() == 10)
		enemy->setShotFlag(true);*/
}
/*Bullet(float x, float y,unsigned int type, unsigned int color,int state,float angle,float base_angle,float speed,float rate)*/
/*琪露诺，1符完美冻结*/
void EnemyShoter::shotPattern01(AbstractEnemy * enemy)
{
	int i, t = enemy->getBossCount() % 650;
	float x = enemy->getX();
	float y = enemy->getY();
	//最开始的随机发射
	if (t <= 160 && t % 10 == 0)
		EffectManager::addBulletShotEffect(x, y, 8);

	if (t < 180) {
		for (i = 0; i < 2; i++) {//1次计数发射2次
			BulletManager::add(x, y, 8, rand() % 7, 1, (float)(rand() / double(RAND_MAX)*Define::PI * 2),
				0.0f, 4.2f + (float)(rand() / double(RAND_MAX)*2.1f), 1.0f);
		}
		if (t % 8 == 0)
			PlaySoundMem(Sound::getIns()->getCh03(), DX_PLAYTYPE_BACK);
	}

	if (210 <= t && t <= 250 && t % 10 == 0)
		EffectManager::addBulletShotEffect(((float)Define::CENTER_X + x) / 2, y, 0);
	if (210 < t && t < 270 && t % 3 == 0) {
		float angle = enemy->shotatan2();
		for (i = 0; i < 8; i++) {
			BulletManager::add(x, y, 8, 0, -1,
				angle - Define::PI / 2 * 0.8f + Define::PI * 0.8f / 8 * i + (float)(rand() / double(RAND_MAX)*(Define::PI / 180)), 0.0f,
				(float)(7.0f + rand() / double(RAND_MAX)*0.7f), 1.0f);
		}

		if (t % 6 == 0)
			PlaySoundMem(Sound::getIns()->getCh03(), DX_PLAYTYPE_BACK);
	}
	for (auto it = BulletManager::getListBig()->begin(); it != BulletManager::getListBig()->end();) {
		if ((*it)->getFlag() > 0) {
			if ((*it)->getState() == 1) {
				if (t == 190) {
					(*it)->setSpeed(0.f);
					(*it)->setColor(7);
					(*it)->setCount(0);
					(*it)->setState(1001);
				}
			}
			if ((*it)->getState() == 1001) {
				if ((*it)->getCount() == 200) {
					(*it)->setAngle((float)(rand() / double(RAND_MAX)*(Define::PI)));
				}
				if ((*it)->getCount() > 200) {
					(*it)->setSpeed((*it)->getSpeed() + 0.01f);
				}
			}
		}
		it++;
	}
}
/*琪露诺，1非*/
void EnemyShoter::shotPattern02(AbstractEnemy * enemy)
{
	int t = enemy->getBossCount() % 600;

	if (t == 50 || t == 110 || t == 170)
		EffectManager::addBulletShotEffect(enemy->getX(), enemy->getY(), 0);

	if (t % 60 == 0 && t < 240 && t > 0) {
		PlaySoundMem(Sound::getIns()->getTan00(), DX_PLAYTYPE_BACK);
		_groupAngle00 = enemy->shotatan2();
	}
	if (t >= 60 && t < 240 && t % 4 == 0 && t % 60 <= 24) {
		shotPlayerBullet(enemy->getX(), enemy->getY(), 16, 0, -1, _groupAngle00, 12.0f, 0.8f, Define::PI / 40, (t % 60) / 4 + 3);
	}

	if (t >= 250 && t % 100 == 50 && t < 520)
		EffectManager::addBulletShotEffect(enemy->getX(), enemy->getY(), 0);
	if (t >= 270 && t % 100 == 70 && t < 520) {		//16向蓝色弹
		PlaySoundMem(Sound::getIns()->getTan01(), DX_PLAYTYPE_BACK);
		for (int i = 0; i < 16; i++) {
			BulletManager::add(enemy->getX(), enemy->getY(), 8, 0, -1, 0.f + i * Define::PI / 8,
				0.0f, 8.0f, 1.0f);
		}
	}

	if (t >= 270 && t % 100 == 90 && t < 520)
		EffectManager::addBulletShotEffect(enemy->getX(), enemy->getY(), 0);
	if (t >= 270 && t % 100 == 10 && t < 520) {		//18向蓝色弹
		PlaySoundMem(Sound::getIns()->getTan01(), DX_PLAYTYPE_BACK);
		for (int i = 0; i < 18; i++) {
			BulletManager::add(enemy->getX(), enemy->getY(), 8, 0, -1, 0.f + i * Define::PI / 9,
				0.0f, 8.0f, 1.0f);
		}
	}

	if (t >= 270 && t % 100 == 70 && t < 520)
		EffectManager::addBulletShotEffect(enemy->getX(), enemy->getY(), 8);
	if (t >= 270 && t % 100 == 90 && t < 520) {		//32向白色弹
		PlaySoundMem(Sound::getIns()->getTan02(), DX_PLAYTYPE_BACK);
		for (int i = 0; i < 32; i++) {
			BulletManager::add(enemy->getX(), enemy->getY(), 16, 8, 2, 0.f + i * Define::PI / 16,
				0.f + i * Define::PI / 16, 3.0f, 0.8f);
		}
	}
	for (auto it = BulletManager::getListSmall()->begin(); it != BulletManager::getListSmall()->end();) {
		if ((*it)->getFlag() > 0) {
			if ((*it)->getState() == 2 && (*it)->getCount() == 70) {
				(*it)->setAngle((*it)->shotatan2());
				(*it)->setBaseAngle((*it)->shotatan2());
				(*it)->setSpeed(8.f);
				(*it)->setState(1002);
			}
		}
		it++;
	}

}
/*琪露诺，2非*/
void EnemyShoter::shotPattern03(AbstractEnemy * enemy)
{
	int cnt = enemy->getBossCount();

	if (cnt % 200 >= 90 && cnt % 200 <= 140 && cnt % 10 == 0)
		EffectManager::addBulletShotEffect(enemy->getX(), enemy->getY(), 0);
	if (cnt % 200 > 100 && cnt % 200 <= 150 && cnt % 6 == 0) {
		PlaySoundMem(Sound::getIns()->getCh03(), DX_PLAYTYPE_BACK);
		int c = cnt % 200 / 6 - 17;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 10; j++) {
				BulletManager::add(enemy->getX(), enemy->getY(), 16, 0, 3, c*Define::PI / 24 - j * Define::PI / 5 - i * Define::PI / 50,
					c*Define::PI / 24 - j * Define::PI / 5 - i * Define::PI / 50, 15.0f - i * 1.5f, 1.0f);
			}
		}
	}

	if ((cnt % 200 == 130) && cnt > 200)
		EffectManager::addBulletShotEffect(enemy->getX(), enemy->getY(), 7);
	if ((cnt % 200 == 150) && cnt > 200) {
		PlaySoundMem(Sound::getIns()->getFocusFix(), DX_PLAYTYPE_BACK);
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 6; j++) {
				if (enemy->getX() > Define::CENTER_X) {
					BulletManager::add(enemy->getX(), enemy->getY(), 9, 7, 3, Define::PI - i * Define::PI / 20 - 0.05f*j,
						Define::PI - i * Define::PI / 20 - 0.05f*j, 8.0f - j * 1.f, 1.0f);
				}
				else
				{
					BulletManager::add(enemy->getX(), enemy->getY(), 9, 7, 3, i*Define::PI / 20 + 0.05f*j,
						i*Define::PI / 20 + 0.05f*j, 8.0f - j * 1.f, 1.0f);
				}
			}
		}
	}
	for (auto it = BulletManager::getListSmall()->begin(); it != BulletManager::getListSmall()->end();) {
		if ((*it)->getFlag() > 0) {
			if ((*it)->getState() == 3 && (*it)->getCount() == 4) {
				(*it)->setSpeed((*it)->getSpeed() / 5);
				(*it)->setState(1003);
			}
		}
		it++;
	}
	for (auto it = BulletManager::getListBig()->begin(); it != BulletManager::getListBig()->end();) {
		if ((*it)->getFlag() > 0) {
			if ((*it)->getState() == 3 && (*it)->getCount() == 70) {
				(*it)->setSpeed(4);
				(*it)->setBaseAngle((*it)->getBaseAngle() > Define::PI / 2 ? (*it)->getAngle() - Define::PI / 2 : (*it)->getAngle() + Define::PI / 2);
				(*it)->setAngle((*it)->getAngle() > Define::PI / 2 ? (*it)->getAngle() - Define::PI / 2 : (*it)->getAngle() + Define::PI / 2);
				(*it)->setState(1003);
				if (!CheckSoundMem(Sound::getIns()->getKira00())) {
					PlaySoundMem(Sound::getIns()->getKira00(), DX_PLAYTYPE_BACK);
				}
			}
		}
		it++;
	}
}
/*琪露诺，2符*/
void EnemyShoter::shotPattern04(AbstractEnemy * enemy)
{
	int cnt = enemy->getBossCount();
	if (cnt % 100 >= 50 && cnt % 100 <= 100 && cnt % 10 == 0)
		EffectManager::addBulletShotEffect(enemy->getX(), enemy->getY(), 0);
	if (cnt % 100 >= 60 && cnt % 100 <= 100 && cnt % 5 == 0) {
		PlaySoundMem(Sound::getIns()->getCh03(), DX_PLAYTYPE_BACK);
		int c = cnt % 100 / 6 - 10;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 10; j++) {
				BulletManager::add(enemy->getX(), enemy->getY(), 16, 0, 3, c*Define::PI / 24 - j * Define::PI / 5 - i * Define::PI / 50,
					c*Define::PI / 24 - j * Define::PI / 5 - i * Define::PI / 50, 15.0f - i * 1.5f, 1.0f);
			}
		}
	}
	if ((cnt % 400 == 280 || cnt % 400 == 380) && cnt > 0)
		EffectManager::addBulletShotEffect(enemy->getX(), enemy->getY(), 7);
	if ((cnt % 400 == 300 || cnt % 400 == 0) && cnt > 0) {
		PlaySoundMem(Sound::getIns()->getFocusFix(), DX_PLAYTYPE_BACK);
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 6; j++) {
				if (enemy->getX() > Define::CENTER_X) {
					BulletManager::add(enemy->getX(), enemy->getY(), 9, 7, 3, Define::PI - i * Define::PI / 20 - 0.05f*j,
						Define::PI - i * Define::PI / 20 - 0.05f*j, 8.0f - j * 1.f, 1.0f);
				}
				else
				{
					BulletManager::add(enemy->getX(), enemy->getY(), 9, 7, 3, i*Define::PI / 20 + 0.05f*j,
						i*Define::PI / 20 + 0.05f*j, 8.0f - j * 1.f, 1.0f);
				}
			}
		}
	}

	for (auto it = BulletManager::getListSmall()->begin(); it != BulletManager::getListSmall()->end();) {
		if ((*it)->getFlag() > 0) {
			if ((*it)->getState() == 3 && (*it)->getCount() == 4) {
				(*it)->setSpeed((*it)->getSpeed() / 5);
				(*it)->setState(1003);
			}
		}
		it++;
	}
	for (auto it = BulletManager::getListBig()->begin(); it != BulletManager::getListBig()->end();) {
		if ((*it)->getFlag() > 0) {
			if ((*it)->getState() == 3 && (*it)->getCount() == 70) {
				(*it)->setSpeed(4);
				(*it)->setBaseAngle((*it)->getBaseAngle() > Define::PI / 2 ? (*it)->getAngle() - Define::PI / 2 : (*it)->getAngle() + Define::PI / 2);
				(*it)->setAngle((*it)->getAngle() > Define::PI / 2 ? (*it)->getAngle() - Define::PI / 2 : (*it)->getAngle() + Define::PI / 2);
				(*it)->setState(1003);
				if (!CheckSoundMem(Sound::getIns()->getKira00())) {
					PlaySoundMem(Sound::getIns()->getKira00(), DX_PLAYTYPE_BACK);
				}
			}
		}
		it++;
	}
}
/*道中0阶段妖精单自机狙*/
void EnemyShoter::shotPattern05(AbstractEnemy * enemy) {
	const int cnt = enemy->getCounter();
	if (cnt == 50) {
		EffectManager::addBulletShotEffect(enemy->getX(), enemy->getY(), 0);
	}
	if (cnt == 60) {
		PlaySoundMem(Sound::getIns()->getTan00(), DX_PLAYTYPE_BACK);
		BulletManager::add(enemy->getX(), enemy->getY(), 6, 0, 5, enemy->shotatan2(), 0.0f, 8.0f, 1.0f);
	}
	/*for (auto it = BulletManager::getListBig()->begin(); it != BulletManager::getListBig()->end();) {
		if ((*it)->getFlag() > 0) {
			if ((*it)->getState() == 5 && (*it)->getCount() == 10) {
				(*it)->setSpeed(4.f);
				(*it)->setState(1005);
			}
		}
		it++;
	}*/

}
/*道中0阶段大妖精子弹*/
void EnemyShoter::shotPattern06(AbstractEnemy * enemy) {
	const int cnt = enemy->getCounter();
	const int a = 30;
	const int b = -20;
	if (cnt >= 45 && cnt <= 115 && cnt % 5 == 0) {
		EffectManager::addBulletShotEffect(enemy->getX(), enemy->getY(), 0);
	}
	if (cnt >= 50 && cnt <= 110 && cnt % 10 == 0) {
		float a = enemy->shotatan2() + (float)((rand() / double(RAND_MAX))*(Define::PI / 4) - Define::PI / 8);
		BulletManager::add(enemy->getX(), enemy->getY(), 3, 0, 6, a, a, 4.0f, 1.0f);
	}
	if (cnt >= 70 && cnt < 90) {
		if (cnt % 3 == 0) {
			PlaySoundMem(Sound::getIns()->getTan01(), DX_PLAYTYPE_BACK);
		}
		if (enemy->getX() < Define::CENTER_X) {
			BulletManager::add(enemy->getX() + a, enemy->getY() - a, 3, 0, 6, (3 * Define::PI / 4) + (8 * Define::PI / 5)*((cnt - 70) / 20.f),
				(3 * Define::PI / 4) + (8 * Define::PI / 5)*((cnt - 70) / 20.f), 3.0f, 1.f);
			BulletManager::add(enemy->getX() + b, enemy->getY() - b, 3, 0, 6, (3 * Define::PI / 4) - (8 * Define::PI / 5)*((cnt - 70) / 20.f),
				(3 * Define::PI / 4) - (8 * Define::PI / 5)*((cnt - 70) / 20.f), 3.0f, 1.f);
		}
		else
		{
			BulletManager::add(enemy->getX() - a, enemy->getY() + a, 3, 0, 6, (3 * Define::PI / 4) + (8 * Define::PI / 5)*((cnt - 70) / 20.f),
				(3 * Define::PI / 4) + (8 * Define::PI / 5)*((cnt - 70) / 20.f), 3.0f, 1.f);
			BulletManager::add(enemy->getX() - b, enemy->getY() + b, 3, 0, 6, (3 * Define::PI / 4) - (8 * Define::PI / 5)*((cnt - 70) / 20.f),
				(3 * Define::PI / 4) - (8 * Define::PI / 5)*((cnt - 70) / 20.f), 3.0f, 1.f);
		}
	}
	if (cnt >= 90 && cnt < 110) {
		if (cnt % 3 == 0) {
			PlaySoundMem(Sound::getIns()->getTan01(), DX_PLAYTYPE_BACK);
		}
		if (enemy->getX() < Define::CENTER_X) {
			BulletManager::add(enemy->getX() + a, enemy->getY() - a, 3, 0, 6, (7 * Define::PI / 4) + (8 * Define::PI / 5)*((cnt - 90) / 20.f),
				(7 * Define::PI / 4) + (8 * Define::PI / 5)*((cnt - 90) / 20.f), 3.0f, 1.f);
			BulletManager::add(enemy->getX() + b, enemy->getY() - b, 3, 0, 6, (7 * Define::PI / 4) - (8 * Define::PI / 5)*((cnt - 90) / 20.f),
				(7 * Define::PI / 4) - (8 * Define::PI / 5)*((cnt - 90) / 20.f), 3.0f, 1.f);
		}
		else
		{
			BulletManager::add(enemy->getX() - a, enemy->getY() - a, 3, 0, 6, (7 * Define::PI / 4) + (8 * Define::PI / 5)*((cnt - 90) / 20.f),
				(7 * Define::PI / 4) + (8 * Define::PI / 5)*((cnt - 90) / 20.f), 3.0f, 1.f);
			BulletManager::add(enemy->getX() - b, enemy->getY() - b, 3, 0, 6, (7 * Define::PI / 4) - (8 * Define::PI / 5)*((cnt - 90) / 20.f),
				(7 * Define::PI / 4) - (8 * Define::PI / 5)*((cnt - 90) / 20.f), 3.0f, 1.f);
		}
	}
	if (cnt >= 110 && cnt < 130) {
		if (cnt % 3 == 0) {
			PlaySoundMem(Sound::getIns()->getTan01(), DX_PLAYTYPE_BACK);
		}
		if (enemy->getX() < Define::CENTER_X) {
			BulletManager::add(enemy->getX() - a, enemy->getY() + a, 3, 0, 6, (5 * Define::PI / 4) + (8 * Define::PI / 5)*((cnt - 110) / 20.f),
				(5 * Define::PI / 4) + (8 * Define::PI / 5)*((cnt - 110) / 20.f), 3.0f, 1.f);
			BulletManager::add(enemy->getX() - b, enemy->getY() - b, 3, 0, 6, (5 * Define::PI / 4) - (8 * Define::PI / 5)*((cnt - 110) / 20.f),
				(5 * Define::PI / 4) - (8 * Define::PI / 5)*((cnt - 110) / 20.f), 3.0f, 1.f);
		}
		else
		{
			BulletManager::add(enemy->getX() + a, enemy->getY() + a, 3, 0, 6, (5 * Define::PI / 4) + (8 * Define::PI / 5)*((cnt - 110) / 20.f),
				(5 * Define::PI / 4) + (8 * Define::PI / 5)*((cnt - 110) / 20.f), 3.0f, 1.f);
			BulletManager::add(enemy->getX() + b, enemy->getY() - b, 3, 0, 6, (5 * Define::PI / 4) - (8 * Define::PI / 5)*((cnt - 110) / 20.f),
				(5 * Define::PI / 4) - (8 * Define::PI / 5)*((cnt - 110) / 20.f), 3.0f, 1.f);
		}
	}

}
/*道中1阶段小妖精子弹*/
void EnemyShoter::shotPattern07(AbstractEnemy * enemy) {
	const int cnt = enemy->getCounter();
	const int type = enemy->getType();
	if (cnt == 25) {
		EffectManager::addBulletShotEffect(enemy->getX(), enemy->getY(), 0);
	}
	if (cnt == 30) {
		PlaySoundMem(Sound::getIns()->getTan01(), DX_PLAYTYPE_BACK);
		shotPlayerBullet(enemy->getX(), enemy->getY(), 3, 0, 7, Define::PI / 2 + (float)((rand() / double(RAND_MAX))*(Define::PI / 8) - Define::PI / 16), 3, 0.9f, Define::PI / 16, 3);
	}
	if (type == 8 && cnt == 45) {
		EffectManager::addBulletShotEffect(enemy->getX(), enemy->getY(), 0);
	}
	if (type == 8 && cnt == 50) {
		PlaySoundMem(Sound::getIns()->getTan01(), DX_PLAYTYPE_BACK);
		shotPlayerBullet(enemy->getX(), enemy->getY(), 3, 0, 7, enemy->shotatan2(), 3, 0.9f, Define::PI / 16, 3);
	}
	if (type == 9 && cnt == 65) {
		EffectManager::addBulletShotEffect(enemy->getX(), enemy->getY(), 0);
	}
	if (type == 9 && cnt == 70) {
		PlaySoundMem(Sound::getIns()->getTan01(), DX_PLAYTYPE_BACK);
		shotPlayerBullet(enemy->getX(), enemy->getY(), 3, 0, 7, Define::PI / 2 + (float)((rand() / double(RAND_MAX))*(Define::PI / 8) - Define::PI / 16), 3, 0.9f, Define::PI / 16, 3);
	}
}
/*道中1阶段大妖精子弹*/
void EnemyShoter::shotPattern08(AbstractEnemy * enemy) {
	const int cnt = enemy->getCounter();

	if (cnt >= 120 && cnt <= 160 && cnt % 10 == 0) {
		EffectManager::addBulletShotEffect(enemy->getX(), enemy->getY(), 3);
	}

	if (cnt == 140) {
		_groupAngle00 = enemy->shotatan2();
	}
	if (cnt >= 140 && cnt <= 176 && (cnt - 140) % 4 == 0) {
		shotPlayerBullet(enemy->getX(), enemy->getY(), 3, 3, 8, _groupAngle00, 8.0f, 0.8f, Define::PI / 72, (cnt - 140) / 4 + 1);
	}
	if (cnt % 5 == 0 && cnt >= 140 && cnt <= 176) {
		PlaySoundMem(Sound::getIns()->getTan00(), DX_PLAYTYPE_BACK);
	}

	if (cnt >= 220 && cnt <= 260 && cnt % 10 == 0) {
		EffectManager::addBulletShotEffect(enemy->getX(), enemy->getY(), 3);
	}
	if (cnt == 240) {
		_groupAngle00 = enemy->shotatan2();
	}
	if (cnt >= 240 && cnt <= 276 && (cnt - 240) % 4 == 0) {
		shotPlayerBullet(enemy->getX(), enemy->getY(), 3, 3, 8, _groupAngle00, 8.0f, 0.8f, Define::PI / 72, (cnt - 240) / 4 + 1);
	}
	if (cnt % 5 == 0 && cnt >= 240 && cnt <= 276) {
		PlaySoundMem(Sound::getIns()->getTan00(), DX_PLAYTYPE_BACK);
	}
}
/*道中2阶段妖精子弹01*/
void EnemyShoter::shotPattern09(AbstractEnemy * enemy) {
	const int cnt = enemy->getCounter();
	if (cnt > 90 && cnt < 200 && (cnt % 25 == 0 || cnt % 95 == 0)) {
		EffectManager::addBulletShotEffect(enemy->getX(), enemy->getY(), 0);
	}
	if (cnt >= 100 && cnt <= 200 && (cnt % 30 == 0 || cnt % 100 == 0)) {
		PlaySoundMem(Sound::getIns()->getTan00(), DX_PLAYTYPE_BACK);
		BulletManager::add(enemy->getX(), enemy->getY(), 6, 0, 9, enemy->shotatan2(), 0.0f, 6.0f, 1.0f);
	}
}
/*道中2阶段妖精子弹02*/
void EnemyShoter::shotPattern10(AbstractEnemy * enemy) {
	const int cnt = enemy->getCounter();
	const int type = enemy->getType();
	if (cnt == 25) {
		EffectManager::addBulletShotEffect(enemy->getX(), enemy->getY(), 0);
	}
	if (cnt == 30) {
		PlaySoundMem(Sound::getIns()->getTan01(), DX_PLAYTYPE_BACK);
		shotPlayerBullet(enemy->getX(), enemy->getY(), 3, 0, 7, Define::PI / 2 + (float)((rand() / double(RAND_MAX))*(Define::PI / 8) - Define::PI / 16), 3, 1.0f, Define::PI / 16, 3);
	}
	if (cnt == 45) {
		EffectManager::addBulletShotEffect(enemy->getX(), enemy->getY(), 0);
	}
	if (cnt == 50) {
		PlaySoundMem(Sound::getIns()->getTan01(), DX_PLAYTYPE_BACK);
		shotPlayerBullet(enemy->getX(), enemy->getY(), 3, 0, 7, enemy->shotatan2(), 3, 1.0f, Define::PI / 16, 3);
	}
}
/*道中3阶段妖精子弹01*/
void EnemyShoter::shotPattern11(AbstractEnemy * enemy)
{
	const int cnt = enemy->getCounter();
	if (cnt == 20 || cnt == 45 || cnt == 70) {
		EffectManager::addBulletShotEffect(enemy->getX() + cos(enemy->getAngle()) * 35, enemy->getY() + sin(enemy->getAngle()) * 40, 1);
	}
	if (cnt == 30 || cnt == 55 || cnt == 80) {
		PlaySoundMem(Sound::getIns()->getTan01(), DX_PLAYTYPE_BACK);
		shotPlayerBullet(enemy->getX(), enemy->getY(), 3, 1, 11, enemy->getAngle(), 8.0f, 0.8f, Define::PI / 40, 3);
	}
}
/*道中3阶段妖精子弹02*/
void EnemyShoter::shotPattern12(AbstractEnemy * enemy)
{
	const int cnt = enemy->getCounter();
	if (cnt >= 70 && cnt < 150 && (cnt % 10 == 5)) {
		EffectManager::addBulletShotEffect(enemy->getX(), enemy->getY(), 1);
	}
	if (cnt >= 80 && cnt < 160 && (cnt % 10 == 0)) {
		PlaySoundMem(Sound::getIns()->getTan00(), DX_PLAYTYPE_BACK);
		BulletManager::add(enemy->getX(), enemy->getY(), 2, 1, 12, enemy->shotatan2(), 0.0f, 6.0f, 1.0f);
	}
}
/*道中3阶段大妖精子弹01*/
void EnemyShoter::shotPattern13(AbstractEnemy * enemy)
{
	float baseAngle;
	bool a;
	const int cnt = enemy->getCounter();
	if (enemy->getX() < Define::CENTER_X) {
		baseAngle = 11 * Define::PI / 8;
		a = true;
	}
	else
	{
		baseAngle = 13 * Define::PI / 8;
		a = false;
	}
	if (cnt >= 60 && cnt <= 380 && cnt % 10 == 0) {
		EffectManager::addBulletShotEffect(enemy->getX(), enemy->getY() - 10, 3);
		EffectManager::addBulletShotEffect(enemy->getX(), enemy->getY() + 10, 3);
		EffectManager::addBulletShotEffect(enemy->getX() - 10, enemy->getY(), 3);
		EffectManager::addBulletShotEffect(enemy->getX() + 10, enemy->getY(), 3);
	}

	if (cnt >= 70 && cnt <= 390) {
		if (cnt % 10 == 0) {
			PlaySoundMem(Sound::getIns()->getCh03(), DX_PLAYTYPE_BACK);
		}
		if ((cnt - 70) % 8 == 0) {
			if (a) {
				shotPlayerBullet(enemy->getX(), enemy->getY(), 16, 3, 13, baseAngle + ((cnt - 70) / 8)*Define::PI / 160, 5.f, 1.f, 5 * Define::PI / 64, 16);
			}
			else
			{
				shotPlayerBullet(enemy->getX(), enemy->getY(), 16, 3, 13, baseAngle - ((cnt - 70) / 8)*Define::PI / 160, 5.f, 1.f, 5 * Define::PI / 64, 16);
			}
		}
		if (cnt % 80 == 0) {
			PlaySoundMem(Sound::getIns()->getTan01(), DX_PLAYTYPE_BACK);
		}
		if (cnt % 80 <= 20 && cnt % 80 % 2 == 0) {
			if (a) {
				BulletManager::add(enemy->getX(), enemy->getY(), 16, 0, 13, baseAngle - Define::PI + (cnt / 80 - 1)*Define::PI / 16 + ((cnt % 80) / 2) *Define::PI / 160,
					baseAngle - Define::PI + (cnt / 80 - 1)*Define::PI / 16 + ((cnt % 80) / 2) *Define::PI / 160, 4.0f, 1.0f);
			}
			else
			{
				BulletManager::add(enemy->getX(), enemy->getY(), 16, 0, 13, baseAngle - Define::PI - (cnt / 80 - 1)*Define::PI / 16 - ((cnt % 80) / 2) *Define::PI / 160,
					baseAngle - Define::PI - (cnt / 80 - 1)*Define::PI / 16 - ((cnt % 80) / 2) *Define::PI / 160, 4.0f, 1.0f);
			}
		}
	}
}
/*道中3阶段妖精子弹03形态1*/
void EnemyShoter::shotPattern14(AbstractEnemy * enemy)
{
	const int cnt = enemy->getCounter();
	if (cnt == 50 || cnt == 110 || cnt == 170) {
		EffectManager::addBulletShotEffect(enemy->getX() + cos(enemy->getAngle()) * 30, enemy->getY() + sin(enemy->getAngle()) * 30, 4);
	}
	if (cnt == 60 || cnt == 120 || cnt == 180) {
		PlaySoundMem(Sound::getIns()->getTan01(), DX_PLAYTYPE_BACK);
		BulletManager::add(enemy->getX(), enemy->getY(), 10, 4, 14, enemy->shotatan2(), enemy->shotatan2(), 5.0f, 1.f);
	}
}
/*道中3阶段妖精子弹03形态2*/
void EnemyShoter::shotPattern15(AbstractEnemy * enemy)
{
	const int cnt = enemy->getCounter();
	if (cnt == 20 || cnt == 80 || cnt == 140) {
		EffectManager::addBulletShotEffect(enemy->getX() + cos(enemy->getAngle()) * 30, enemy->getY() + sin(enemy->getAngle()) * 30, 4);
	}
	if (cnt == 30 || cnt == 90 || cnt == 150) {
		PlaySoundMem(Sound::getIns()->getTan01(), DX_PLAYTYPE_BACK);
		BulletManager::add(enemy->getX(), enemy->getY(), 10, 4, 14, enemy->shotatan2(), enemy->shotatan2(), 5.0f, 1.f);
	}
}
/*道中4阶段毛玉子弹*/
void EnemyShoter::shotPattern16(AbstractEnemy * enemy)
{
	const int cnt = enemy->getCount();
	if (cnt == 85) {
		EffectManager::addBulletShotEffect(enemy->getX(), enemy->getY(), 0);
	}
	if (cnt == 100) {
		PlaySoundMem(Sound::getIns()->getTan00(), DX_PLAYTYPE_BACK);
		BulletManager::add(enemy->getX(), enemy->getY(), 3, 0, 15, enemy->shotatan2(), enemy->shotatan2(), 2.5f, 0.8f);
	}
}
/*道中5阶段妖精子弹01  切记17不能与10,11,12,13,14同屏*/
void EnemyShoter::shotPattern17(AbstractEnemy * enemy) {
	const int cnt = enemy->getCount();
	if (cnt >= 8 && cnt <= 48 && cnt % 4 == 0) {
		EffectManager::addBulletShotEffect(enemy->getX(), enemy->getY(), 0);
	}
	if (cnt >= 16 && cnt <= 56 && cnt % 4 == 0) {
		PlaySoundMem(Sound::getIns()->getTan00(), DX_PLAYTYPE_BACK);
		BulletManager::add(enemy->getX(), enemy->getY(), 8, 0, -1, enemy->shotatan2() + (cnt - 36) / 4 * Define::PI / 90, 0.f
			, 4.f - 0.08f*(36 - cnt) / 4, 1.0f);
	}
	if (enemy->getX() <= Define::IN_W) {
		if (cnt >= 70 && (cnt - 70) % 90 == 0) {
			PlaySoundMem(Sound::getIns()->getTan02(), DX_PLAYTYPE_BACK);
			EffectManager::addBulletShotEffect(enemy->getX(), enemy->getY(), 3);
		}
		if (cnt >= 80 && (cnt - 80) % 90 == 0) {
			_groupAngle00 = enemy->shotatan2();
			for (int i = 0; i < 5; i++) {
				BulletManager::add(enemy->getX(), enemy->getY(), 3, 3, -10 - i, _groupAngle00 + (i - 2)  * Define::PI / 12, enemy->shotatan2()
					, 3.0f, 0.8f);
			}
		}
		if (cnt >= 80 && (cnt - 80) % 90 <= 14 && (cnt - 80) % 90 > 0 && (cnt - 80) % 90 % 2 == 0) {
			for (int i = 0; i < 5; i++) {
				BulletManager::add(enemy->getX(), enemy->getY(), 3, 3, 10 + i, _groupAngle00 + (i - 2)  * Define::PI / 12, enemy->shotatan2()
					, 3.0f, 0.8f);
			}
		}
	}
	for (auto it = BulletManager::getListSmall()->begin(); it != BulletManager::getListSmall()->end();) {
		if ((*it)->getFlag() > 0) {
			if ((*it)->getCount() == 29 && (*it)->getState() == -10) {
				_groupY = (Player::getY() + (*it)->getY()) / 2;
				_groupX = (Player::getX() + (*it)->getX()) / 2;
			}
			if ((*it)->getCount() == 30) {
				if ((*it)->getState() == -10) {
					_groupAngle01 = atan2(_groupY - (*it)->getY(), _groupX - (*it)->getX());
					(*it)->setState(10017);
					(*it)->setBaseAngle(atan2(Player::getY() - (*it)->getY(), Player::getX() - (*it)->getX()));
					(*it)->setAngle(_groupAngle01);
				}
				if ((*it)->getState() == -11) {
					_groupAngle02 = atan2(_groupY - (*it)->getY(), _groupX - (*it)->getX());
					(*it)->setState(10017);
					(*it)->setBaseAngle(atan2(Player::getY() - (*it)->getY(), Player::getX() - (*it)->getX()));
					(*it)->setAngle(_groupAngle02);
				}
				if ((*it)->getState() == -12) {
					_groupAngle03 = atan2(_groupY - (*it)->getY(), _groupX - (*it)->getX());
					(*it)->setState(10017);
					(*it)->setAngle(_groupAngle03);
					(*it)->setBaseAngle(atan2(Player::getY() - (*it)->getY(), Player::getX() - (*it)->getX()));
				}
				if ((*it)->getState() == -13) {
					_groupAngle04 = atan2(_groupY - (*it)->getY(), _groupX - (*it)->getX());
					(*it)->setState(10017);
					(*it)->setBaseAngle(atan2(Player::getY() - (*it)->getY(), Player::getX() - (*it)->getX()));
					(*it)->setAngle(_groupAngle04);
				}
				if ((*it)->getState() == -14) {
					_groupAngle05 = atan2(_groupY - (*it)->getY(), _groupX - (*it)->getX());
					(*it)->setState(10017);
					(*it)->setAngle(_groupAngle05);
					(*it)->setBaseAngle(atan2(Player::getY() - (*it)->getY(), Player::getX() - (*it)->getX()));
				}
			}
			if ((*it)->getCount() == 31) {
				if ((*it)->getState() == 10) {
					(*it)->setState(10017);
					(*it)->setAngle(_groupAngle01);
					(*it)->setBaseAngle(_groupAngle01);
				}
				if ((*it)->getState() == 11) {
					(*it)->setState(10017);
					(*it)->setAngle(_groupAngle02);
					(*it)->setBaseAngle(_groupAngle02);
				}
				if ((*it)->getState() == 12) {
					(*it)->setState(10017);
					(*it)->setAngle(_groupAngle03);
					(*it)->setBaseAngle(_groupAngle03);
				}
				if ((*it)->getState() == 13) {
					(*it)->setState(10017);
					(*it)->setAngle(_groupAngle04);
					(*it)->setBaseAngle(_groupAngle04);
				}
				if ((*it)->getState() == 14) {
					(*it)->setState(10017);
					(*it)->setAngle(_groupAngle05);
					(*it)->setBaseAngle(_groupAngle05);
				}
			}
		}
		it++;
	}

}
/*道中5阶段妖精子弹02*/
void EnemyShoter::shotPattern18(AbstractEnemy * enemy) {
	const int cnt = enemy->getCount();
	if (cnt == 30) {
		EffectManager::addBulletShotEffect(enemy->getX(), enemy->getY() + 50, 3);
	}
	if (cnt == 40) {
		PlaySoundMem(Sound::getIns()->getTan01(), DX_PLAYTYPE_BACK);
		shotPlayerBullet(enemy->getX(), enemy->getY(), 3, 3, 18, 0.f, 3.5f, 1.0f, Define::PI / 18, 36);
	}
}
/*道中5阶段妖精子弹03*/
void EnemyShoter::shotPattern19(AbstractEnemy * enemy) {
	const int cnt = enemy->getCount();
	if (cnt == 100) {
		EffectManager::addBulletShotEffect(enemy->getX(), enemy->getY(), 0);
	}
	if (cnt == 110) {
		PlaySoundMem(Sound::getIns()->getItem00(), DX_PLAYTYPE_BACK);
		for (int i = 0; i < 3; i++) {
			BulletManager::add(enemy->getX(), enemy->getY(), 6, 1, 19, enemy->shotatan2(), enemy->shotatan2(), 2.f + 1.f*i, 1.f);
		}
	}
}
/*道中6阶段阴阳玉子弹01*/
void EnemyShoter::shotPattern20(AbstractEnemy * enemy)
{
	const int cnt = enemy->getCount();
	if (cnt % 16 == 10 && cnt <= 192) {
		EffectManager::addBulletShotEffect(enemy->getX(), enemy->getY(), 3);
	}
	if (cnt % 16 == 0 && cnt <= 192) {
		PlaySoundMem(Sound::getIns()->getLazer01(), DX_PLAYTYPE_BACK);
		for (int i = 0; i < 6; i++) {
			if (i == 0) {
				BulletManager::add(enemy->getX(), enemy->getY(), 12, 3, 20, Define::PI / 2 + i * Define::PI / 3, Define::PI / 2 + i * Define::PI / 3, 6.f, 0.f);
			}
			else {
				BulletManager::add(enemy->getX(), enemy->getY(), 12, 3, 20, Define::PI / 2 + i * Define::PI / 3, Define::PI / 2 + i * Define::PI / 3, 7.5f, 0.f);
			}
		}
	}
	/*for (auto it = BulletManager::getListSmall()->begin(); it != BulletManager::getListSmall()->end();) {
		if ((*it)->getFlag() > 0) {
			float count = (float)(*it)->getCount();
			if (count < 16 && (*it)->getState() == 20) {
				(*it)->setRate(count / 15);
			}
			if (count == 16 && (*it)->getState() == 20) {
				(*it)->setState(1020);
			}
			if ((*it)->getState() == 1020 && (*it)->getCount() == 60) {
				(*it)->setSpeed((*it)->getSpeed() - 3.f);
				(*it)->setState(0);
			}
		}
		it++;
	}*/
}
/*道中6阶段阴阳玉子弹02*/
void EnemyShoter::shotPattern21(AbstractEnemy * enemy) {
	const int cnt = enemy->getCount();
	if (cnt % 16 == 10 && cnt <= 192) {
		EffectManager::addBulletShotEffect(enemy->getX(), enemy->getY(), 0);
	}
	if (cnt % 16 == 0 && cnt <= 192) {
		PlaySoundMem(Sound::getIns()->getLazer01(), DX_PLAYTYPE_BACK);
		for (int i = 0; i < 6; i++) {
			if (i == 1 || 5) {
				BulletManager::add(enemy->getX(), enemy->getY(), 12, 0, 21, Define::PI / 2 + i * Define::PI / 3, Define::PI / 2 + i * Define::PI / 3, 5.5f, 0.f);
			}
			else {
				BulletManager::add(enemy->getX(), enemy->getY(), 12, 0, 21, Define::PI / 2 + i * Define::PI / 3, Define::PI / 2 + i * Define::PI / 3, 7.5f, 0.f);
			}
		}
	}
	/*for (auto it = BulletManager::getListSmall()->begin(); it != BulletManager::getListSmall()->end();) {
		if ((*it)->getFlag() > 0) {
			float count = (float)(*it)->getCount();
			if (count < 16 && (*it)->getState() == 21) {
				(*it)->setRate(count / 15);
			}
			if (count == 16 && (*it)->getState() == 21) {
				(*it)->setState(1021);
			}
			if ((*it)->getState() == 1021 && (*it)->getCount() == 60) {
				(*it)->setSpeed((*it)->getSpeed() - 3.f);
				(*it)->setState(0);
			}
		}
		it++;
	}*/
}
/*道中6阶段大妖精子弹01*/
void EnemyShoter::shotPattern22(AbstractEnemy * enemy) {
	const int cnt = enemy->getCount() - 30;
	if (cnt % 10 == 0) {
		if (cnt / 70 % 2 == 0) {
			for (int i = 0; i < 30; i++) {
				BulletManager::add(enemy->getX() + ((float)(rand() / double(RAND_MAX)*100.f - 50.f)), enemy->getY() + ((float)(rand() / double(RAND_MAX)*100.f) - 50.f),
					14, 3, 22, Define::PI / 2 + cnt * Define::PI / 25 + ((float)(rand() / double(RAND_MAX)*Define::PI / 2) - Define::PI / 4),
					Define::PI / 2 + cnt * Define::PI / 25, 6.0f, 0.6f);
			}
		}
		else
		{
			for (int i = 0; i < 30; i++) {
				BulletManager::add(enemy->getX() + ((float)(rand() / double(RAND_MAX)*100.f - 50.f)), enemy->getY() + ((float)(rand() / double(RAND_MAX)*100.f) - 50.f),
					14, 7, 22, Define::PI / 2 - cnt * Define::PI / 25 + ((float)(rand() / double(RAND_MAX)*Define::PI / 2) - Define::PI / 4),
					Define::PI / 2 - cnt * Define::PI / 25, 6.0f, 0.6f);
			}
		}
	}
	//结构批漏，需要加入bullet类的update中
	//for (auto it = BulletManager::getListSmall()->begin(); it != BulletManager::getListSmall()->end();) {
	//	if ((*it)->getFlag() > 0) {
	//		if ((*it)->getState() == 22 || (*it)->getState() == 1022) {
	//			(*it)->setBaseAngle((*it)->getBaseAngle() + Define::PI / 15);
	//		}
	//		if ((*it)->getState() == 22 && (*it)->getCount() == 30) {
	//			(*it)->setSpeed(2.7f);
	//		}
	//	}
	//	it++;
	//}
}
/*小伞1非*/
void EnemyShoter::shotPattern23(AbstractEnemy * enemy) {
	int t = enemy->getBossCount() % 120;
	if (t == 0) {
		enemy->setShotFlag(true);
	}
	if (t < 40) {
		bool i = TRUE;
		if (cos(enemy->getAngle()) < -0.1) {
			i = FALSE;
		}
		if (i) {
			BulletManager::add(enemy->getX() + cos(2 * Define::PI / 4 - t * Define::PI / 20)*38.f,
				enemy->getY() + sin(2 * Define::PI / 4 - t * Define::PI / 20)*38.f,
				8, 2, 23, 2 * Define::PI / 4 - t * Define::PI / 20,
				0.0f, 7.5f, 1.0f);
			BulletManager::add(enemy->getX() + cos(3 * Define::PI / 4 - t * Define::PI / 20)*46.f,
				enemy->getY() + sin(3 * Define::PI / 4 - t * Define::PI / 20)*46.f,
				8, 2, 23, 3 * Define::PI / 4 - t * Define::PI / 20,
				0.0f, 7.f, 1.0f);
			BulletManager::add(enemy->getX() + cos(4 * Define::PI / 4 - t * Define::PI / 20)*54.f,
				enemy->getY() + sin(4 * Define::PI / 4 - t * Define::PI / 20)*54.f
				, 8, 2, 23, 4 * Define::PI / 4 - t * Define::PI / 20,
				0.0f, 6.5f, 1.0f);
			BulletManager::add(
				enemy->getX() + cos(5 * Define::PI / 4 - t * Define::PI / 20)*62.f,
				enemy->getY() + sin(5 * Define::PI / 4 - t * Define::PI / 20)*62.f,
				8, 2, 23, 5 * Define::PI / 4 - t * Define::PI / 20,
				0.0f, 6.f, 1.0f);
			BulletManager::add(enemy->getX() + cos(6 * Define::PI / 4 - t * Define::PI / 20)*70.f,
				enemy->getY() + sin(6 * Define::PI / 4 - t * Define::PI / 20)*70.f
				, 8, 2, 23, 6 * Define::PI / 4 - t * Define::PI / 20,
				0.0f, 5.5f, 1.0f);
			BulletManager::add(enemy->getX() + cos(7 * Define::PI / 4 - t * Define::PI / 20)*78.f,
				enemy->getY() + sin(7 * Define::PI / 4 - t * Define::PI / 20)*78.f
				, 8, 2, 23, 7 * Define::PI / 4 - t * Define::PI / 20,
				0.0f, 5.f, 1.0f);
		}
		else
		{
			BulletManager::add(enemy->getX() + cos(8 * Define::PI / 4 + t * Define::PI / 20)*78.f,
				enemy->getY() + sin(8 * Define::PI / 4 + t * Define::PI / 20)*70.f,
				8, 2, 23, 8 * Define::PI / 4 + t * Define::PI / 20,
				0.0f, 7.5f, 1.0f);
			BulletManager::add(enemy->getX() + cos(7 * Define::PI / 4 + t * Define::PI / 20)*70.f,
				enemy->getY() + sin(7 * Define::PI / 4 + t * Define::PI / 20)*70.f,
				8, 2, 23, 7 * Define::PI / 4 + t * Define::PI / 20,
				0.0f, 7.f, 1.0f);
			BulletManager::add(enemy->getX() + cos(6 * Define::PI / 4 + t * Define::PI / 20)*62.f,
				enemy->getY() + sin(6 * Define::PI / 4 + t * Define::PI / 20)*62.f
				, 8, 2, 23, 6 * Define::PI / 4 + t * Define::PI / 20,
				0.0f, 6.5f, 1.0f);
			BulletManager::add(
				enemy->getX() + cos(5 * Define::PI / 4 + t * Define::PI / 20)*54.f,
				enemy->getY() + sin(5 * Define::PI / 4 + t * Define::PI / 20)*54.f,
				8, 2, 23, 5 * Define::PI / 4 + t * Define::PI / 20,
				0.0f, 6.f, 1.0f);
			BulletManager::add(enemy->getX() + cos(4 * Define::PI / 4 + t * Define::PI / 20)*46.f,
				enemy->getY() + sin(4 * Define::PI / 4 + t * Define::PI / 20)*46.f
				, 8, 2, 23, 4 * Define::PI / 4 + t * Define::PI / 20,
				0.0f, 5.5f, 1.0f);
			BulletManager::add(enemy->getX() + cos(3 * Define::PI / 4 + t * Define::PI / 20)*38.f,
				enemy->getY() + sin(3 * Define::PI / 4 + t * Define::PI / 20)*38.f
				, 8, 2, 23, 3 * Define::PI / 4 + t * Define::PI / 20,
				0.0f, 5.f, 1.0f);
		}
		if (t % 8 == 0) {
			PlaySoundMem(Sound::getIns()->getCh03(), DX_PLAYTYPE_BACK);
		}
	}

	for (auto it = BulletManager::getListBig()->begin(); it != BulletManager::getListBig()->end();) {
		if ((*it)->getFlag() > 0) {
			if ((*it)->getState() == 23 && (*it)->getCount() <= 30) {
				(*it)->setSpeed((*it)->getSpeed() - 0.1f);
			}
			if ((*it)->getState() == 23 && (*it)->getCount() > 60 && (*it)->getCount() <= 90) {
				(*it)->setSpeed((*it)->getSpeed() + 0.1f);
			}
		}
		it++;
	}

}
/*小伞1符卡*/
void EnemyShoter::shotPattern24(AbstractEnemy * enemy) {
	int t = enemy->getBossCount() % 120;
	if (t == 0) {
		enemy->setShotFlag(true);
	}
	if (t < 50) {
		bool i = TRUE;
		if (cos(enemy->getAngle()) < -0.1) {
			i = FALSE;
		}
		if (i) {
			BulletManager::add(enemy->getX() + cos(3 * Define::PI / 4 + t * Define::PI / 25)*70.f,
				enemy->getY() + sin(3 * Define::PI / 4 + t * Define::PI / 25)*70.f,
				8, 1, 23, 3 * Define::PI / 4 + t * Define::PI / 25,
				0.0f, 6.5f, 1.0f);
			BulletManager::add(enemy->getX() + cos(4 * Define::PI / 4 + t * Define::PI / 25)*62.f,
				enemy->getY() + sin(4 * Define::PI / 4 + t * Define::PI / 25 + Define::PI)*62.f
				, 8, 2, 23, 4 * Define::PI / 4 + t * Define::PI / 25,
				0.0f, 6.0f, 1.0f);
			BulletManager::add(enemy->getX() + cos(5 * Define::PI / 4 + t * Define::PI / 25)*54.f,
				enemy->getY() + sin(5 * Define::PI / 4 + t * Define::PI / 25 + Define::PI)*54.f,
				8, 3, 23, 5 * Define::PI / 4 + t * Define::PI / 25,
				0.0f, 6.5f, 1.0f);
			BulletManager::add(enemy->getX() + cos(6 * Define::PI / 4 + t * Define::PI / 25)*46.f,
				enemy->getY() + sin(6 * Define::PI / 4 + t * Define::PI / 25)*46.f
				, 8, 4, 23, 6 * Define::PI / 4 + t * Define::PI / 25,
				0.0f, 6.5f, 1.0f);
			BulletManager::add(enemy->getX() + cos(9 * Define::PI / 4 + t * Define::PI / 25)*38.f,
				enemy->getY() + sin(4 * Define::PI / 4 + t * Define::PI / 25)*38.f
				, 8, 5, 23, 4 * Define::PI / 4 + t * Define::PI / 25,
				0.0f, 6.f, 1.0f);
		}
		else {
			BulletManager::add(enemy->getX() + cos(7 * Define::PI / 4 + t * Define::PI / 25)*70.f,
				enemy->getY() + sin(3 * Define::PI / 4 + t * Define::PI / 25)*70.f,
				8, 1, 23, 3 * Define::PI / 4 + t * Define::PI / 25,
				0.0f, 5.5f, 1.0f);
			BulletManager::add(enemy->getX() + cos(6 * Define::PI / 4 + t * Define::PI / 25)*62.f,
				enemy->getY() + sin(4 * Define::PI / 4 + t * Define::PI / 25)*62.f
				, 8, 2, 23, 4 * Define::PI / 4 + t * Define::PI / 25,
				0.0f, 6.0f, 1.0f);
			BulletManager::add(enemy->getX() + cos(5 * Define::PI / 4 + t * Define::PI / 25)*54.f,
				enemy->getY() + sin(5 * Define::PI / 4 + t * Define::PI / 25)*54.f,
				8, 3, 23, 5 * Define::PI / 4 + t * Define::PI / 25,
				0.0f, 6.5f, 1.0f);
			BulletManager::add(enemy->getX() + cos(4 * Define::PI / 4 + t * Define::PI / 25)*46.f,
				enemy->getY() + sin(6 * Define::PI / 4 + t * Define::PI / 25)*46.f
				, 8, 4, 23, 6 * Define::PI / 4 + t * Define::PI / 25,
				0.0f, 7.0f, 1.0f);
			BulletManager::add(enemy->getX() + cos(8 * Define::PI / 4 + t * Define::PI / 25)*38.f,
				enemy->getY() + sin(4 * Define::PI / 4 + t * Define::PI / 25)*38.f
				, 8, 5, 23, 4 * Define::PI / 4 + t * Define::PI / 25,
				0.0f, 6.5f, 1.0f);
		}
		if (t % 10 == 0) {
			PlaySoundMem(Sound::getIns()->getCh03(), DX_PLAYTYPE_BACK);
		}
	}

	for (auto it = BulletManager::getListBig()->begin(); it != BulletManager::getListBig()->end();) {
		if ((*it)->getFlag() > 0) {
			if ((*it)->getState() == 23 && (*it)->getCount() <= 30) {
				(*it)->setSpeed((*it)->getSpeed() - 0.1f);
			}
			if ((*it)->getState() == 23 && (*it)->getCount() > 30 && (*it)->getCount() <= 60) {
				(*it)->setSpeed((*it)->getSpeed() + 0.1f);
			}

		}
		it++;
	}
}
/*小伞2非*/
void EnemyShoter::shotPattern25(AbstractEnemy * enemy) {
	int t = enemy->getBossCount();
	if (t == 0) {
		PlaySoundMem(Sound::getIns()->getRain00(), DX_PLAYTYPE_LOOP);
	}
	if (t > 0) {
		BulletManager::add(Define::IN_X + (float)(rand() / double(RAND_MAX)*Define::IN_W), 0, 15, 7, 25, Define::PI / 2, -Define::PI / 2,
			4.5f + (float)(rand() / double(RAND_MAX)*3.0), 0.8f + (float)(rand() / double(RAND_MAX)*0.3f));
	}
	for (auto it = BulletManager::getListNormal()->begin(); it != BulletManager::getListNormal()->end();) {
		if ((*it)->getFlag() > 0) {
			if ((*it)->getState() == 25) {
				if ((*it)->getX() < (enemy->getX() + 80.f) && (*it)->getX() > (enemy->getX() - 80.f)
					&& (*it)->getY() > (enemy->getY() - 80.f) && (*it)->getY() < (enemy->getY())) {
					(*it)->setFlag(0);
				}
			}
		}
		it++;
	}
}
/*小伞2符*/
void EnemyShoter::shotPattern26(AbstractEnemy * enemy) {
	int t = enemy->getBossCount();
	if (t == 0) {
		StopSoundMem(Sound::getIns()->getRain00());
		PlaySoundMem(Sound::getIns()->getRain01(), DX_PLAYTYPE_BACK);
	}
	if (enemy->getHp() < 150) {
		StopSoundMem(Sound::getIns()->getRain01());
	}
	if (t > 0) {
		BulletManager::add(Define::IN_X + (float)(rand() / double(RAND_MAX)*Define::IN_W), 0, 15, 7, 25, Define::PI / 2, -Define::PI / 2,
			4.5f + (float)(rand() / double(RAND_MAX)*3.0), 0.8f + (float)(rand() / double(RAND_MAX)*0.3f));
	}
	if (t % 3 == 0) {
		BulletManager::add(0, (float)(rand() / double(RAND_MAX)*Define::IN_H), 15, 7, 25, Define::PI / 2, -Define::PI / 2,
			4.5f + (float)(rand() / double(RAND_MAX)*3.0), 0.8f + (float)(rand() / double(RAND_MAX)*0.3f));
		BulletManager::add(Define::IN_X + Define::IN_H, (float)(rand() / double(RAND_MAX)*Define::IN_H), 15, 7, 25, Define::PI / 2, -Define::PI / 2,
			4.5f + (float)(rand() / double(RAND_MAX)*3.0), 0.8f + (float)(rand() / double(RAND_MAX)*0.3f));
	}
	if (t % 150 == 120) {
		PlaySoundMem(Sound::getIns()->getTan01(), DX_PLAYTYPE_BACK);
		enemy->setShotFlag(true);
		_groupAngle00 = Define::PI / 2 + ((int)enemy->getX() - Define::CENTER_X) * Define::PI / 1500;
		shotPlayerBullet(enemy->getX() + cos(_groupAngle00)*60.f,
			enemy->getY() + sin(_groupAngle00)*60.f, 11, 3, -1, _groupAngle00, 10.0f, 1.0f, Define::PI / 12, 3);
	}
	if (t % 150 == 125) {
		shotPlayerBullet(enemy->getX() + cos(_groupAngle00)*60.f,
			enemy->getY() + sin(_groupAngle00)*60.f, 11, 3, -1, _groupAngle00, 9.0f, 1.0f, Define::PI / 12, 3);
	}
	if (t % 150 == 130) {
		shotPlayerBullet(enemy->getX() + cos(_groupAngle00)*60.f,
			enemy->getY() + sin(_groupAngle00)*60.f, 11, 3, -1, _groupAngle00, 8.0f, 1.0f, Define::PI / 12, 3);
	}
	for (auto it = BulletManager::getListNormal()->begin(); it != BulletManager::getListNormal()->end();) {
		if ((*it)->getFlag() > 0) {
			if ((*it)->getState() == 25 && (t % 150 > 40 || t % 150 < 120) && t % 2 == 0) {
				int a = (int)enemy->getX() - Define::CENTER_X;
				(*it)->setBaseAngle(-Define::PI / 2 + a * Define::PI / 1500);
				(*it)->setAngle(Define::PI / 2 + a * Define::PI / 1500);
				if ((*it)->getX() < (enemy->getX() + 80.f) && (*it)->getX() > (enemy->getX() - 80.f)
					&& (*it)->getY() > (enemy->getY() - 80.f) && (*it)->getY() < (enemy->getY())) {
					(*it)->setFlag(0);
				}
			}
		}
		it++;
	}
}
/*小伞3符*/
void EnemyShoter::shotPattern27(AbstractEnemy * enemy)
{
	int t = enemy->getBossCount();
	if (t % 240 == 5) {
		enemy->setShotFlag(true);
	}

	if (EnemyManager::getSize() > 1) {
		if (!CheckSoundMem(Sound::getIns()->getUFO()))
			PlaySoundMem(Sound::getIns()->getUFO(), DX_PLAYTYPE_BACK);
	}
	if (t % 1200 == 0)
		PlaySoundMem(Sound::getIns()->getCh02(), DX_PLAYTYPE_BACK);
	if (t % 1200 == 15) {
		EnemyManager::addSpell27(enemy->getX() + 75.f, enemy->getY(), 0, 28);
		EnemyManager::addSpell27(enemy->getX(), enemy->getY() + 75.f, 1, 29);
		EnemyManager::addSpell27(enemy->getX(), enemy->getY() - 75.f, 2, 30);
		EnemyManager::addSpell27(enemy->getX() - 75.f, enemy->getY(), 3, 31);
	}

	if (t % 240 >= 14 && t % 240 <= 54 && t > 240 && t % 2 == 0) {
		if (t % 240 == 14)
			PlaySoundMem(Sound::getIns()->getTan00(), DX_PLAYTYPE_BACK);
		BulletManager::add(enemy->getX() + cos(3 * Define::PI / 4 - t * Define::PI / 20)*46.f,
			enemy->getY() + sin(3 * Define::PI / 4 - t * Define::PI / 20)*46.f,
			6, 1, 27, 3 * Define::PI / 4 - t * Define::PI / 20,
			0.0f, 7.f, 1.0f);
	}

	for (auto it = BulletManager::getListSmall()->begin(); it != BulletManager::getListSmall()->end();) {
		if ((*it)->getFlag() > 0) {
			if ((*it)->getState() == 29 && (*it)->getCount() < 30) {
				if ((*it)->getAngle() <= 3 * Define::PI / 2) {
					(*it)->setAngle((*it)->getAngle() - Define::PI / 60);
				}
				else
				{
					(*it)->setAngle((*it)->getAngle() + Define::PI / 60);
				}
				(*it)->setSpeed((*it)->getSpeed() + 0.05f);
			}
			if ((*it)->getState() == 29 && (*it)->getCount() > 30 && (*it)->getCount() < 60) {
				if ((*it)->getAngle() <= 3 * Define::PI / 2) {
					(*it)->setAngle((*it)->getAngle() - Define::PI / 120);
				}
				else
				{
					(*it)->setAngle((*it)->getAngle() + Define::PI / 120);
				}
				(*it)->setSpeed((*it)->getSpeed() + 0.1f);
			}

		}
		it++;
	}

}
/*小伞3符UFO 1*/
void EnemyShoter::shotPattern28(AbstractEnemy * enemy) {
	const int cnt = enemy->getCount();
	if (cnt < 930 && cnt>200) {
		if (cnt % 100 == 35) {
			EffectManager::addBulletShotEffect(enemy->getX(), enemy->getY(), 3);
		}
		if (cnt % 100 == 45) {
			_groupAngle00 = enemy->shotatan2();
			_groupX = enemy->getX();
			_groupY = enemy->getY();
			shotPlayerBullet(_groupX, _groupY, 11, 3, 28, _groupAngle00, 8.f, 1.f, Define::PI / 12, 5);
		}
		if (cnt % 100 == 55) {
			shotPlayerBullet(_groupX, _groupY, 11, 3, 28, _groupAngle00, 8.f, 1.f, Define::PI / 12, 5);
		}
		if (cnt % 100 == 65) {
			shotPlayerBullet(_groupX, _groupY, 11, 3, 28, _groupAngle00, 8.f, 1.f, Define::PI / 12, 5);
		}
	}
	else
	{
		if (cnt >= 930 && cnt <= 955 && cnt % 5 == 0) {
			EffectManager::addBulletShotEffect(enemy->getX(), enemy->getY(), 3);
		}
		if (cnt == 970) {
			shotPlayerBullet(enemy->getX(), enemy->getY(), 10, 3, 0, enemy->shotatan2(), 10.f, 1.f, Define::PI / 8, 16);
			enemy->setFlag(-1);
		}
	}

}
/*小伞3符UFO 2*/
void EnemyShoter::shotPattern29(AbstractEnemy * enemy) {
	const int cnt = enemy->getCount();

	if (cnt < 900) {
		if (cnt % 30 == 20) {
			EffectManager::addBulletShotEffect(enemy->getX(), enemy->getY(), 0);
		}
		if (cnt > 35 && cnt % 3 > 0) {
			BulletManager::add(enemy->getX(), enemy->getY(),
				14, rand() % (8), 29, 3 * Define::PI / 2 + ((float)(rand() / double(RAND_MAX)*Define::PI / 2) - Define::PI / 4),
				((float)(rand() / double(RAND_MAX) * 2 * Define::PI) - Define::PI / 4), 3.f, 0.7f);
		}
	}
	else
	{
		if (cnt >= 940 && cnt <= 965 && cnt % 5 == 0) {
			EffectManager::addBulletShotEffect(enemy->getX(), enemy->getY(), 3);
		}
		if (cnt == 980) {
			shotPlayerBullet(enemy->getX(), enemy->getY(), 10, 1, 0, enemy->shotatan2(), 10.f, 1.f, Define::PI / 8, 17);
			enemy->setFlag(-1);
		}
	}
}
/*小伞3符UFO 3*/
void EnemyShoter::shotPattern30(AbstractEnemy * enemy) {
	const int cnt = enemy->getCount();
	if (cnt < 930 && cnt > 200) {
		if (cnt % 200 == 70 || cnt % 200 == 90) {
			EffectManager::addBulletShotEffect(enemy->getX(), enemy->getY(), 3);
		}
		if (cnt % 200 == 80) {
			_groupAngle01 = enemy->shotatan2();
			shotPlayerBullet(enemy->getX(), enemy->getY(), 0, 6, 28, _groupAngle01, 8.f, 1.f, Define::PI / 8, 16);
		}
		if (cnt % 200 == 90) {
			shotPlayerBullet(enemy->getX(), enemy->getY(), 0, 5, 28, _groupAngle01, 8.f, 1.f, Define::PI / 16, 31);
		}
		if (cnt % 200 == 100) {
			shotPlayerBullet(enemy->getX(), enemy->getY(), 0, 4, 28, _groupAngle01, 8.f, 1.f, Define::PI / 8, 16);
		}
		if (cnt % 200 == 110) {
			shotPlayerBullet(enemy->getX(), enemy->getY(), 0, 5, 28, _groupAngle01, 8.f, 1.f, Define::PI / 16, 31);
		}
		if (cnt % 200 == 120) {
			shotPlayerBullet(enemy->getX(), enemy->getY(), 0, 6, 28, _groupAngle01, 8.f, 1.f, Define::PI / 8, 16);
		}
	}
	else
	{
		if (cnt >= 950 && cnt <= 975 && cnt % 5 == 0) {
			EffectManager::addBulletShotEffect(enemy->getX(), enemy->getY(), 3);
		}
		if (cnt == 990) {
			shotPlayerBullet(enemy->getX(), enemy->getY(), 10, 6, 0, enemy->shotatan2(), 10.f, 1.f, Define::PI / 8, 16);
			enemy->setFlag(-1);
		}
	}
}
/*小伞3符UFO 4*/
void EnemyShoter::shotPattern31(AbstractEnemy * enemy) {
	const int cnt = enemy->getCount();

	if (cnt < 1000 && cnt >= 102 && cnt % 6 == 0) {
		if (cnt % 5 == 0) {
			EffectManager::addBulletShotEffect(enemy->getX(), enemy->getY(), 4);
		}
		BulletManager::add(enemy->getX(), enemy->getY(), 16, 4, 31, Define::PI / 2 + (cnt - 102) * Define::PI / 256,
			Define::PI / 2 + (cnt - 102) * Define::PI / 256, 5.5f, 1.f);
		BulletManager::add(enemy->getX(), enemy->getY(), 16, 4, 31, 3 * Define::PI / 2 + (cnt - 102) * Define::PI / 256,
			3 * Define::PI / 2 + (cnt - 102) * Define::PI / 256, 5.5f, 1.f);
	}
	else
	{
		if (cnt >= 960 && cnt <= 985 && cnt % 5 == 0) {
			EffectManager::addBulletShotEffect(enemy->getX(), enemy->getY(), 4);
		}
		if (cnt == 1000) {
			shotPlayerBullet(enemy->getX(), enemy->getY(), 10, 4, 0, enemy->shotatan2(), 10.f, 1.f, Define::PI / 8, 17);
			enemy->setFlag(-1);
		}
	}
}
/*小伞3非*/
void EnemyShoter::shotPattern32(AbstractEnemy * enemy) {
	int t = enemy->getBossCount() - 60;
	if (t < 0) {
		return;
	}
	if (t % 600 == 0 && t == 0) {
		_groupAngle00 = enemy->shotatan2();
	}
	if (t % 600 <= 540 && t % 30 == 0 && t / 600 % 2 == 0) {
		PlaySoundMem(Sound::getIns()->getTan02(), DX_PLAYTYPE_BACK);
		_groupAngle00 = _groupAngle00 - Define::PI / 9;
		shotPlayerBullet(enemy->getX(), enemy->getY(), 3, 7, 32, -_groupAngle00, 3, 0.8f, 11 * Define::PI / 576, 96);
	}
	if (t % 600 <= 540 && t % 600 > 40 && t % 30 >= 15 && t % 5 == 0 && t / 600 % 2 == 0) {
		if (t % 30 == 20)
			PlaySoundMem(Sound::getIns()->getTan01(), DX_PLAYTYPE_BACK);
		shotPlayerBullet(enemy->getX(), enemy->getY(), 5, 0, 32, -_groupAngle00, 4.5, 0.8f, 7 * Define::PI / 192, 48);
	}
	if (t % 600 <= 540 && t % 30 == 0 && t / 600 % 2 != 0) {
		PlaySoundMem(Sound::getIns()->getTan02(), DX_PLAYTYPE_BACK);
		_groupAngle00 = _groupAngle00 + Define::PI / 9;
		shotPlayerBullet(enemy->getX(), enemy->getY(), 3, 3, 32, -_groupAngle00, 3, 0.8f, 11 * Define::PI / 576, 96);
	}
	if (t % 600 <= 540 && t % 600 > 40 && t % 30 >= 15 && t % 5 == 0 && t / 600 % 2 != 0) {
		if (t % 30 == 20)
			PlaySoundMem(Sound::getIns()->getTan01(), DX_PLAYTYPE_BACK);
		shotPlayerBullet(enemy->getX(), enemy->getY(), 5, 2, 32, -_groupAngle00, 4.5, 0.8f, 7 * Define::PI / 192, 48);
	}
}
/*小伞4符卡*/
void EnemyShoter::shotPattern33(AbstractEnemy * enemy) {
	int t = enemy->getBossCount();
	int k = 90;
	int i = enemy->getHp();
	if (enemy->getHp() <= 30000) {
		k = 60;
	}
	if (enemy->getHp() <= 15000) {
		k = 40;
	}
	if (t >= 0 && t % k == 0) {
		PlaySoundMem(Sound::getIns()->getTan02(), DX_PLAYTYPE_BACK);
		for (int j = 0; j < 2; j++) {
			shotPlayerBullet(enemy->getX(), enemy->getY(), 9, 5, j, (float)(rand() / double(RAND_MAX)*Define::PI / 2), 3.2f, 0.5f, Define::PI / 30, 60);

		}
	}
	//声音
	for (auto it = BulletManager::getListBig()->begin(); it != BulletManager::getListBig()->end();) {//
		if ((*it)->getFlag() > 0) {
			int state = (*it)->getState();
			if (state < 10) {
				int cnt = (*it)->getCount();
				if (30 < cnt && cnt < 120) {
					(*it)->setSpeed((*it)->getSpeed() - 1.2f / 90.0f);
					(*it)->setBaseAngle((*it)->getBaseAngle() + Define::PI / 90.f*(state ? -1 : 1));
					(*it)->setAngle((*it)->getAngle() + Define::PI / 90.f*(state ? -1 : 1));
				}
				if (cnt > 120) {
					(*it)->setState(10033);
				}
			}
		}
		it++;
	}
}

void EnemyShoter::shotPlayerBullet(float x, float y, unsigned int type, unsigned int color, int state, float angle, float speed, float rate, float interval, int num)
{
	if (num <= 0) {
		return;
	}
	float baseAngle;
	if (num % 2 == 0) {		//偶数弹
		baseAngle = angle - ((float)(num - 1) / 2)*interval;
	}
	else			//奇数弹
	{
		baseAngle = angle - (num / 2)*interval;
	}
	for (int i = 0; i < num; i++) {
		BulletManager::add(x, y, type, color, state, baseAngle + i * interval, baseAngle + i * interval, speed, rate);
	}
}
