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
		//ERR("shotId����");
	}
	(this->*_shotPattern[id])(enemy);	//����id���

}

void EnemyShoter::setFunction()
{
	_shotPattern.push_back(&EnemyShoter::shotPattern00);
	_shotPattern.push_back(&EnemyShoter::shotPattern01);
	_shotPattern.push_back(&EnemyShoter::shotPattern02);
	_shotPattern.push_back(&EnemyShoter::shotPattern03);
	_shotPattern.push_back(&EnemyShoter::shotPattern04);
	_shotPattern.push_back(&EnemyShoter::shotPattern05);
}
/*�޵�Ļ*/
void EnemyShoter::shotPattern00(AbstractEnemy * enemy)
{
	if (enemy->getCount() == 10)
		BulletManager::add(enemy->getX(), enemy->getY(), 12, 0, 0, Define::PI / 2,
			Define::PI / 2, 4.0f, 1.5f);
}
/*Bullet(float x, float y,unsigned int type, unsigned int color,int state,float angle,float base_angle,float speed,float rate)*/
/*��¶ŵ��1����������*/
void EnemyShoter::shotPattern01(AbstractEnemy * enemy)
{
	int i, t = enemy->getBossCount() % 650;
	float x = enemy->getX();
	float y = enemy->getY();
	//�ʼ���������
	if (t <= 160 && t % 10 == 0) 
		EffectManager::addBulletShotEffect(x, y, 8);
	
	if (t < 180) {
		for (i = 0; i < 2; i++) {//1�μ�������2��
			BulletManager::add(x, y, 8, rand() % 7, 1, (float)(rand() / double(RAND_MAX)*Define::PI * 2),
				0.0f, 4.2f + (float)(rand() / double(RAND_MAX)*2.1f), 1.0f);
		}
		if (t % 8 == 0)
			PlaySoundMem(Sound::getIns()->getCh03(), DX_PLAYTYPE_BACK);
	}

	if (210 <= t && t <= 250 && t % 10 == 0) 
		EffectManager::addBulletShotEffect(((float)Define::CENTER_X+x)/2, y, 0);
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
/*��¶ŵ��1��*/
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
	if (t >= 270 && t % 100 == 70 && t < 520) {		//16����ɫ��
		PlaySoundMem(Sound::getIns()->getTan01(), DX_PLAYTYPE_BACK);
		for (int i = 0; i < 16; i++) {
			BulletManager::add(enemy->getX(), enemy->getY(), 8, 0, -1, 0.f + i * Define::PI / 8,
				0.0f, 8.0f, 1.0f);
		}
	}

	if (t >= 270 && t % 100 == 90 && t < 520)
		EffectManager::addBulletShotEffect(enemy->getX(), enemy->getY(), 0);
	if (t >= 270 && t % 100 == 10 && t < 520) {		//18����ɫ��
		PlaySoundMem(Sound::getIns()->getTan01(), DX_PLAYTYPE_BACK);
		for (int i = 0; i < 18; i++) {
			BulletManager::add(enemy->getX(), enemy->getY(), 8, 0, -1, 0.f + i * Define::PI / 9,
				0.0f, 8.0f, 1.0f);
		}
	}

	if (t >= 270 && t % 100 == 70 && t < 520)
		EffectManager::addBulletShotEffect(enemy->getX(), enemy->getY(), 8);
	if (t >= 270 && t % 100 == 90 && t < 520) {		//32���ɫ��
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
/*��¶ŵ��2��*/
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
/*��¶ŵ��2��*/
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
void EnemyShoter::shotPattern05(AbstractEnemy * enemy) {
	const int cnt = enemy->getCounter();
	if (60 < cnt && cnt <= 2000 && cnt % 20 == 0) {
		BulletManager::add(enemy->getX(), enemy->getY(), 0, 0, 0, enemy->shotatan2(), 0.0, 3, 0.5);
		//BulletManager::add(enemy->getX(), enemy->getY(), 7, 0, 0, enemy->shotatan2(), 0.0, 5, 1.0);
		//BulletManager::add(enemy->getX(), enemy->getY(), 6, 0, 0, enemy->shotatan2(), 0.0, 7, 1.0);
	}

}
void EnemyShoter::shotPlayerBullet(float x, float y, unsigned int type, unsigned int color, int state, float angle, float speed, float rate, float interval, int num)
{
	if (num <= 0) {
		return;
	}
	float baseAngle;
	if (num % 2 == 0) {		//ż����
		baseAngle = angle - ((float)(num - 1) / 2)*interval;
	}
	else			//������
	{
		baseAngle = angle - (num / 2)*interval;
	}
	for (int i = 0; i < num; i++) {
		BulletManager::add(x, y, type, color, state, baseAngle + i * interval, baseAngle + i * interval, speed, rate);
	}
}
