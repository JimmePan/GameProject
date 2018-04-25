#include "EnemyManager.h"
#include "Define.h"
#include "NormalEnemy.h"
#include "Cirno.h"
#include "BigEnemy.h"
#include "DxLib.h"

using namespace std;

EnemyManager::EnemyManager()
{
	//_list.emplace_back(make_shared<NormalEnemy>(Define::CENTER_X, 100.f, 0, 200));
	//_list.emplace_back(make_shared<BigEnemy>(Define::CENTER_X-100, 0.f, 1, 5000));
	//_list.emplace_back(make_shared<BigEnemy>(Define::CENTER_X, 500.f, 1, 500));
	//_list.emplace_back(make_shared<NormalEnemy>(Define::CENTER_X-100, 0.f, 1, 150));
	//_list.emplace_back(make_shared<BigEnemy>(Define::CENTER_X - 100.f, 0.f, 0, 1000));
	//_list.emplace_back(make_shared<Cirno>(Define::CENTER_X + 100, 0.f, 4, 150));
	_count = 0;
}

bool EnemyManager::update()
{
	for (auto it = _list.begin(); it != _list.end();) {

		if ((*it)->update() == false) {
			it = _list.erase(it);
		}
		else {
			it++;
		}
	}
	state01Play();
	_count++;
	return true;
}

void EnemyManager::draw() const
{
	DrawFormatString(70, 40, GetColor(255, 255, 255), "Ê£ÓàµÐÈË¸öÊý£º%d", +_list.size());
	for (auto enemy : _list) {
		enemy->draw();
	}
}

void EnemyManager::state01Play()
{
	if (_count == 300) {
		_list.emplace_back(make_shared<Cirno>(Define::CENTER_X + 100, 0.f, 4, 0, 0, 0, 0));
	}
}



