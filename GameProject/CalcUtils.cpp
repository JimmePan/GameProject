#include "CalcUtils.h"
#include <cmath>


using namespace std;
/*
@brief 小数点后point位四舍五入，原为（+point-1）保留疑问
*/
float CalcUtils::roundPoint(float val, int point)
{
	float temp;
	temp = val * pow(10.f, +point);
	temp = (int)(temp + 0.5f);
	temp = temp * pow(10.f, -point);
	return temp;

}

float CalcUtils::roundSize(float max, float min, int count)
{
	if (count / 60 % 2 > 0) {
		return max - count % 60 * ((max - min) / 60);
	}
	else {
		return min + count % 60 * ((max - min) / 60);
	}

}

void CalcUtils::ClearBullet()		//自机死亡消弹
{
	for (auto i = BulletManager::getListSmall()->begin(); i != BulletManager::getListSmall()->end();) {
		if ((*i)->getFlag() > 0) {
			(*i)->setFlag(0);
		}
		i++;
	}
	for (auto i = BulletManager::getListNormal()->begin(); i != BulletManager::getListNormal()->end();) {
		if ((*i)->getFlag() > 0) {
			(*i)->setFlag(0);
		}
		i++;
	}
	for (auto i = BulletManager::getListBig()->begin(); i != BulletManager::getListBig()->end();) {
		if ((*i)->getFlag() > 0) {
			(*i)->setFlag(0);
		}
		i++;
	}
}

void CalcUtils::ClearBulletEn()		//boss死亡消弹
{
	for (auto i = BulletManager::getListSmall()->begin(); i != BulletManager::getListSmall()->end();) {
		if ((*i)->getFlag() > 0) {
			(*i)->setFlag(0);
			ItemManger::add((*i)->getX(), (*i)->getY(), -Define::PI / 2, 7);
		}
		i++;
	}
	for (auto i = BulletManager::getListNormal()->begin(); i != BulletManager::getListNormal()->end();) {
		if ((*i)->getFlag() > 0) {
			(*i)->setFlag(0);
			ItemManger::add((*i)->getX(), (*i)->getY(), -Define::PI / 2, 7);
		}
		i++;
	}
	for (auto i = BulletManager::getListBig()->begin(); i != BulletManager::getListBig()->end();) {
		if ((*i)->getFlag() > 0) {
			(*i)->setFlag(0);
			ItemManger::add((*i)->getX(), (*i)->getY(), -Define::PI / 2, 7);
		}
		i++;
	}
}

void CalcUtils::PlayFall()	//自机死亡掉落
{
	for (int i = 0; i < 5; i++) {
		int j = 3;
		float angle = 5 * Define::PI / 4 + i*Define::PI / 8;
		if (i == 0 || i == 4) {
			j = 0;
		}
		ItemManger::add((float)Define::CENTER_X + cos(angle) * 70, (float)Define::OUT_H*0.8f + sin(angle) * 60, angle, j);
	}
}
