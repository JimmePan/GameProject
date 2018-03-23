#include "EffectManager.h"
#include <DxLib.h>
#include "DelEnemyEffect.h"
#include "DelEnemyEffect2.h"
#include "ShotEnemyEffect01.h"
#include "ShotEnemyEffect02.h"
#include "BoomEffect01.h"

using namespace std;

std::list<std::shared_ptr<Effect>> EffectManager::_list;	//��̬������ʼ��������Ҫ����
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
	DrawFormatString(0, 70, GetColor(255, 255, 255), "ʣ��Ч��������%d", +_list.size());
	for (auto effect : _list) {
		if (effect->getEff() == 1) {
			SetDrawBlendMode(DX_BLENDMODE_ADD, effect->getBrt());
			
		}
		else {						//������Ч����
			effect->draw();
		}
		if (effect->getEff() == 1)
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
	_list.emplace_back(make_shared<BoomEffect01>());
}
