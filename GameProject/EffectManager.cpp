#include "EffectManager.h"
#include <DxLib.h>
#include "DelEnemyEffect.h"
#include "DelEnemyEffect2.h"

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
	DrawFormatString(0, 70, GetColor(255, 255, 255), "剩余效果个数：%d", +_list.size());
	for (auto effect : _list) {
		effect->draw();
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