#include "EffectManager.h"
#include <DxLib.h>
#include "DelEnemyEffect.h"
#include "DelEnemyEffect2.h"
#include "ShotEnemyEffect01.h"
#include "ShotEnemyEffect02.h"
#include "BoomEffect01.h"
#include "BoomEffect02.h"
#include "BulletBreakEffect.h"
#include "GrazeEffect.h"
#include "BulletShotEffect.h"
#include "LogoEffect.h"

using namespace std;

std::list<std::shared_ptr<Effect>> EffectManager::_list;	//静态变量初始化！！重要！！
EffectManager::EffectManager()
{

}
bool EffectManager::update()
{
	for (auto it = _list.begin(); it != _list.end();) {

		if ((*it)->update() == false) {
			it = _list.erase(it);
		}
		else {
			it++;
		}
	}
	return true;
}

void EffectManager::draw() const
{
	DrawFormatString(70, 85, GetColor(255, 255, 255), "剩余效果个数：%d", +_list.size());
	for (auto effect : _list) {
		switch (effect->getEff())
		{
		case 1:
			SetDrawBlendMode(DX_BLENDMODE_ADD, effect->getBrt());
			effect->draw();
			break;
		case 2:
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, effect->getBrt());
			effect->draw();
			break;
		default:
			break;
		}
		if (effect->getEff() == 1 || effect->getEff() == 2)
			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	}
}

void EffectManager::addEnemyDelEffect(float x, float y, int color)
{
	_list.emplace_back(make_shared<DelEnemyEffect>(x, y, color));
}

void EffectManager::addEnemyDelEffect2(float x, float y, int color)
{
	_list.emplace_back(make_shared<DelEnemyEffect2>(x, y, color));
}

void EffectManager::addShotEnemyEffect01(float x, float y)
{
	_list.emplace_back(make_shared<ShotEnemyEffect01>(x, y));
}

void EffectManager::addShotEnemyEffect02(float x, float y)
{
	_list.emplace_back(make_shared<ShotEnemyEffect02>(x, y));
}
void EffectManager::addBoomEffect01()
{
	for (int i = 7; i >= 0; i--) {
		_list.emplace_back(make_shared<BoomEffect01>(i));
	}
}

void EffectManager::addBoomEffect02(float x, float y, float angle)
{
	_list.emplace_back(make_shared<BoomEffect02>(x, y, angle));
}

void EffectManager::addBulletBreakEffect(float x, float y, int color)
{
	_list.emplace_back(make_shared<BulletBreakEffect>(x, y, color));
}

void EffectManager::addGrazeEffect(float x, float y)
{
	int a = rand() % (3) + 2;
	for (int i = 0; i < a; i++) {
		_list.emplace_back(make_shared<GrazeEffect>(x, y));
	}
}

void EffectManager::addBulletShotEffect(float x, float y, int color)
{
	_list.emplace_back(make_shared<BulletShotEffect>(x, y, color));
}

void EffectManager::addLogoEffect(float x, float y, int num)
{
	_list.emplace_back(make_shared<LogoEffect>(x, y, num));
}
