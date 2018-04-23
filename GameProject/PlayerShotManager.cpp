#include "PlayerShotManager.h"
#include "DxLib.h"
#include "PlayerShot.h"

using namespace std;

PlayerShotManager::PlayerShotManager()
{
}

std::list<std::shared_ptr<PlayerShot>> PlayerShotManager::_list;	//静态变量初始化！！重要！！

void PlayerShotManager::add(float x, float y, int kind)
{
	_list.emplace_back(make_shared<PlayerShot>(x, y, kind));
}

bool PlayerShotManager::update()
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

void PlayerShotManager::draw() const
{
	DrawFormatString(70, 70, GetColor(255, 255, 255), "发射子弹数：%d", +_list.size());
	for (auto shot : _list) {
		shot->draw();
	}
}



