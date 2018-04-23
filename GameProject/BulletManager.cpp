#include "BulletManager.h"
#include "DxLib.h"
#include "ImageBullet.h"
using namespace std;

std::list<std::shared_ptr<Bullet>> BulletManager::_list_small;
std::list<std::shared_ptr<Bullet>> BulletManager::_list_normal;
std::list<std::shared_ptr<Bullet>> BulletManager::_list_big;

BulletManager::BulletManager()
{
}

bool compare_SORT_Z(std::shared_ptr<Bullet> first, std::shared_ptr<Bullet> second)
{
	unsigned int i = 0;
	if (first->getSort() > second->getSort()) {
		return true;
	}
	return false;

}

void BulletManager::add(float x, float y, unsigned int type, unsigned int color, int state, float angle, float base_angle, float speed, float rate)
{
	switch (ImageBullet::getSORT_Z(type))
	{
	case 1:
		_list_small.emplace_back(make_shared<Bullet>(x, y, type, color, state, angle, base_angle, speed, rate));
		break;
	case 2:
		_list_normal.emplace_back(make_shared<Bullet>(x, y, type, color, state, angle, base_angle, speed, rate));
		break;
	case 3:
		_list_big.emplace_back(make_shared<Bullet>(x, y, type, color, state, angle, base_angle, speed, rate));
		break;
	default:
		break;
	}
}

bool BulletManager::update()
{
	for (auto it = _list_small.begin(); it != _list_small.end();) {
		if ((*it)->update() == false) {
			it = _list_small.erase(it);
		}
		else {
			it++;
		}
	}
	for (auto it = _list_normal.begin(); it != _list_normal.end();) {
		if ((*it)->update() == false) {
			it = _list_normal.erase(it);
		}
		else {
			it++;
		}
	}
	for (auto it = _list_big.begin(); it != _list_big.end();) {
		if ((*it)->update() == false) {
			it = _list_big.erase(it);
		}
		else {
			it++;
		}
	}
	//_list.sort(compare_SORT_Z);
	return true;
}

void BulletManager::draw() const
{
	DrawFormatString(70, 100, GetColor(255, 255, 255), "Í¬ÆÁµ¯Ä»Êý£º%d", +(_list_small.size() + _list_normal.size() + _list_big.size()));
	for (auto bullet : _list_big) {

		bullet->draw();
	}
	for (auto bullet : _list_normal) {

		bullet->draw();
	}
	for (auto bullet : _list_small) {

		bullet->draw();
	}
}