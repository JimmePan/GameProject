#include "EnemyShoter.h"
#include "Macro.h"
#include "Define.h"
#include "AbstractEnemy.h"
#include "Player.h"
#include "BulletManager.h"
#include "Sound.h"
#include "EffectManager.h"

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
}
/*无弹幕*/
void EnemyShoter::shotPattern00(AbstractEnemy * enemy)
{
	/*if (enemy->getCount() == 10)
		BulletManager::add(enemy->getX(), enemy->getY(), 12, 0, 0, Define::PI / 2,
			Define::PI / 2, 4.0f, 1.5f);*/
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
	for (auto it = BulletManager::getListBig()->begin(); it != BulletManager::getListBig()->end();) {
		if ((*it)->getFlag() > 0) {
			if ((*it)->getState() == 5 && (*it)->getCount() == 10) {
				(*it)->setSpeed(4.f);
				(*it)->setState(1005);
			}
		}
		it++;
	}

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
	if (cnt >= 150 && cnt <= 190 && cnt % 10 == 0) {
		EffectManager::addBulletShotEffect(enemy->getX(), enemy->getY(), 3);
	}

	if (cnt == 170) {
		_groupAngle00 = enemy->shotatan2();
	}
	if (cnt >= 170 && cnt <= 206 && (cnt - 170) % 4 == 0) {
		shotPlayerBullet(enemy->getX(), enemy->getY(), 3, 3, 8, _groupAngle00, 8.0f, 0.8f, Define::PI / 72, (cnt - 170) / 4 + 1);
	}
	if (cnt % 5 == 0 && cnt >= 170 && cnt <= 206) {
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
		EffectManager::addBulletShotEffect(enemy->getX()+cos(enemy->getAngle())*35, enemy->getY() + sin(enemy->getAngle())*40, 1);
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

void EnemyShoter::shotPattern13(AbstractEnemy * enemy)
{
}

void EnemyShoter::shotPattern14(AbstractEnemy * enemy)
{
}

void EnemyShoter::shotPattern15(AbstractEnemy * enemy)
{
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
