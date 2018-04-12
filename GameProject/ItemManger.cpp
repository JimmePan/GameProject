#include "ItemManger.h"
#include "DxLib.h"

using namespace std;
std::list<std::shared_ptr<Item>> ItemManger::_list;
ItemManger::ItemManger()
{
}

void ItemManger::add(float x, float y, float angle, int kind)
{
	_list.emplace_back(make_shared<Item>(x, y, angle, kind));
}

bool ItemManger::update()
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

void ItemManger::draw() const
{
	DrawFormatString(0, 110, GetColor(255, 255, 255), "µÀ¾ßÊý£º%d", +_list.size());
	for (auto shot : _list) {
		shot->draw();
	}
}
