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
	DrawFormatString(70, 40, GetColor(255, 255, 255), "剩余敌人个数：%d", +_list.size());
	for (auto enemy : _list) {
		enemy->draw();
	}
}
/*AbstractEnemy(float x, float y, int type, int hp, int movePatternID, int shotPatternID, int itemPatternID) */
void EnemyManager::state01Play()
{
	///*第一阶段*/
	//const int step00 = 0;
	//if (_count == 10) {
	//	_list.emplace_back(make_shared<NormalEnemy>(Define::CENTER_X + 50, 0.f, 9, 50, 7, 0, 1));
	//	return;
	//}
	//if (_count == 20) {
	//	_list.emplace_back(make_shared<NormalEnemy>(Define::CENTER_X - 50, 0.f, 8, 50, 8, 5, 2));
	//	return;
	//}
	//if (_count == 30) {
	//	_list.emplace_back(make_shared<NormalEnemy>(Define::CENTER_X + 100, 0.f, 9, 50, 8, 0, 1));
	//	return;
	//}
	//if (_count == 40) {
	//	_list.emplace_back(make_shared<NormalEnemy>(Define::CENTER_X - 100, 0.f, 8, 50, 8, 5, 2));
	//	return;
	//}
	//if (_count == 50) {
	//	_list.emplace_back(make_shared<NormalEnemy>(Define::CENTER_X + 150, 0.f, 9, 50, 7, 0, 1));
	//	return;
	//}
	//if (_count == 60) {
	//	_list.emplace_back(make_shared<NormalEnemy>(Define::CENTER_X - 70, 0.f, 8, 50, 7, 5, 2));
	//	return;
	//}
	//if (_count == 70) {
	//	_list.emplace_back(make_shared<NormalEnemy>(Define::CENTER_X + 70, 0.f, 9, 50, 7, 0, 1));
	//	return;
	//}
	//if (_count == 80) {
	//	_list.emplace_back(make_shared<NormalEnemy>(Define::CENTER_X - 90, 0.f, 8, 50, 8, 5, 2));
	//	return;
	//}
	//if (_count == 90) {
	//	_list.emplace_back(make_shared<NormalEnemy>(Define::CENTER_X + 150, 0.f, 8, 50, 7, 5, 2));
	//	return;
	//}
	//if (_count == 100) {
	//	_list.emplace_back(make_shared<NormalEnemy>(Define::CENTER_X - 150, 0.f, 9, 50, 7, 0, 1));
	//	return;
	//}
	//if (_count == 110) {
	//	_list.emplace_back(make_shared<NormalEnemy>(Define::CENTER_X + 200, 0.f, 8, 50, 8, 5, 2));
	//	return;
	//}
	//if (_count == 120) {
	//	_list.emplace_back(make_shared<NormalEnemy>(Define::CENTER_X - 200, 0.f, 9, 50, 8, 0, 1));
	//	return;
	//}
	//if (_count == 130) {
	//	_list.emplace_back(make_shared<NormalEnemy>(Define::CENTER_X + 120, 0.f, 8, 50, 7, 5, 2));
	//	return;
	//}
	//if (_count == 140) {
	//	_list.emplace_back(make_shared<NormalEnemy>(Define::CENTER_X - 120, 0.f, 9, 50, 8, 0, 1));
	//	return;
	//}
	//if (_count == 150) {
	//	_list.emplace_back(make_shared<NormalEnemy>(Define::CENTER_X + 180, 0.f, 8, 50, 7, 5, 2));
	//	return;
	//}
	//if (_count == 160) {
	//	_list.emplace_back(make_shared<NormalEnemy>(Define::CENTER_X - 180, 0.f, 9, 50, 7, 0, 1));
	//	return;
	//}
	//if (_count == 170) {
	//	_list.emplace_back(make_shared<NormalEnemy>(Define::CENTER_X + 120, 0.f, 9, 50, 7, 0, 1));
	//	return;
	//}
	//if (_count == 180) {
	//	_list.emplace_back(make_shared<NormalEnemy>(Define::CENTER_X - 120, 0.f, 9, 50, 8, 0, 1));
	//	return;
	//}
	//if (_count == 190) {
	//	_list.emplace_back(make_shared<NormalEnemy>(Define::CENTER_X + 230, 0.f, 9, 50, 8, 0, 1));
	//	return;
	//}
	//if (_count == 200) {
	//	_list.emplace_back(make_shared<NormalEnemy>(Define::CENTER_X - 230, 0.f, 9, 50, 7, 0, 1));
	//	return;
	//}
	//if (_count == 210) {
	//	_list.emplace_back(make_shared<NormalEnemy>(Define::CENTER_X + 110, 0.f, 9, 50, 7, 0, 1));
	//	return;
	//}
	//if (_count == 220) {
	//	_list.emplace_back(make_shared<NormalEnemy>(Define::CENTER_X - 110, 0.f, 9, 50, 7, 0, 1));
	//	return;
	//}
	//if (_count == 230) {
	//	_list.emplace_back(make_shared<NormalEnemy>(Define::CENTER_X + 160, 0.f, 9, 50, 8, 0, 1));
	//	return;
	//}
	//if (_count == 240) {
	//	_list.emplace_back(make_shared<NormalEnemy>(Define::CENTER_X - 160, 0.f, 9, 50, 7, 0, 1));
	//	_list.emplace_back(make_shared<BigEnemy>(Define::CENTER_X + 220, 0.f, 0, 800, 9, 6, 5));
	//	_list.emplace_back(make_shared<BigEnemy>(Define::CENTER_X - 220, 0.f, 0, 800, 9, 6, 5));
	//	return;
	//}
	//if (_count == 250) {
	//	_list.emplace_back(make_shared<NormalEnemy>(Define::CENTER_X + 190, 0.f, 9, 50, 8, 0, 1));
	//	return;
	//}
	//if (_count == 260) {
	//	_list.emplace_back(make_shared<NormalEnemy>(Define::CENTER_X - 190, 0.f, 9, 50, 8, 0, 1));
	//	return;
	//}
	//if (_count == 270) {
	//	_list.emplace_back(make_shared<NormalEnemy>(Define::CENTER_X + 220, 0.f, 9, 50, 7, 0, 1));
	//	return;
	//}
	//if (_count == 280) {
	//	_list.emplace_back(make_shared<NormalEnemy>(Define::CENTER_X - 220, 0.f, 9, 50, 8, 0, 1));
	//	return;
	//}
	//if (_count == 290) {
	//	_list.emplace_back(make_shared<NormalEnemy>(Define::CENTER_X + 60, 0.f, 9, 50, 8, 0, 1));
	//	return;
	//}
	//if (_count == 300) {
	//	_list.emplace_back(make_shared<NormalEnemy>(Define::CENTER_X - 60, 0.f, 1, 50, 7, 0, 3));
	//	return;
	//}
	//if (_count == 310) {
	//	_list.emplace_back(make_shared<NormalEnemy>(Define::CENTER_X + 150, 0.f, 9, 50, 7, 0, 1));
	//	return;
	//}
	//if (_count == 320) {
	//	_list.emplace_back(make_shared<NormalEnemy>(Define::CENTER_X - 150, 0.f, 9, 50, 8, 0, 1));
	//	return;
	//}
		/*第一阶段共640帧，后跟标题显示，下一阶段从900帧起*/
	/*const int step01 = 900;
	if (_count - step01 == 0) {
		_list.emplace_back(make_shared<NormalEnemy>(Define::CENTER_X + 240, 0.f, 9, 50, 10, 7, 1));
		_list.emplace_back(make_shared<BigEnemy>(Define::CENTER_X - 240, 0.f, 0, 800, 9, 8, 5));
		return;
	}
	if (_count - step01 == 20) {
		_list.emplace_back(make_shared<NormalEnemy>(Define::CENTER_X + 220, 0.f, 8, 50, 10, 7, 2));
		return;
	}
	if (_count - step01 == 40) {
		_list.emplace_back(make_shared<NormalEnemy>(Define::CENTER_X + 200, 0.f, 9, 50, 10, 7, 1));
		return;
	}
	if (_count - step01 == 60) {
		_list.emplace_back(make_shared<NormalEnemy>(Define::CENTER_X + 240, 0.f, 9, 50, 10, 7, 1));
		return;
	}
	if (_count - step01 == 80) {
		_list.emplace_back(make_shared<NormalEnemy>(Define::CENTER_X + 220, 0.f, 8, 50, 10, 7, 2));
		return;
	}
	if (_count - step01 == 100) {
		_list.emplace_back(make_shared<NormalEnemy>(Define::CENTER_X + 200, 0.f, 9, 50, 10, 7, 1));
		return;
	}
	if (_count - step01 == 120) {
		_list.emplace_back(make_shared<NormalEnemy>(Define::CENTER_X + 240, 0.f, 9, 50, 10, 7, 1));
		return;
	}
	if (_count - step01 == 140) {
		_list.emplace_back(make_shared<NormalEnemy>(Define::CENTER_X + 220, 0.f, 8, 50, 10, 7, 2));
		return;
	}
	if (_count - step01 == 160) {
		_list.emplace_back(make_shared<NormalEnemy>(Define::CENTER_X + 200, 0.f, 9, 50, 10, 7, 1));
		return;
	}*/
	/*第二阶段共380帧，后跟标题显示，下一阶段从1180帧起*/
	/*const int step02 = 1180;
	if (_count - step02 == 0) {
		_list.emplace_back(make_shared<NormalEnemy>(Define::IN_W, Define::OUT_H, 9, 100, 11, 0, 1));
		return;
	}
	if (_count - step02 == 10) {
		_list.emplace_back(make_shared<NormalEnemy>(Define::IN_W, Define::OUT_H, 8, 100, 11, 9, 2));
		return;
	}
	if (_count - step02 == 20) {
		_list.emplace_back(make_shared<NormalEnemy>(Define::IN_W, Define::OUT_H, 9, 100, 11, 0, 1));
		return;
	}
	if (_count - step02 == 30) {
		_list.emplace_back(make_shared<NormalEnemy>(Define::IN_W, Define::OUT_H, 8, 100, 11, 9, 2));
		return;
	}
	if (_count - step02 == 40) {
		_list.emplace_back(make_shared<NormalEnemy>(Define::IN_W, Define::OUT_H, 9, 100, 11, 0, 1));
		return;
	}
	if (_count - step02 == 50) {
		_list.emplace_back(make_shared<NormalEnemy>(Define::IN_W, Define::OUT_H, 8, 100, 11, 9, 2));
		return;
	}
	if (_count - step02 == 60) {
		_list.emplace_back(make_shared<NormalEnemy>(Define::IN_W, Define::OUT_H, 9, 100, 11, 0, 1));
		return;
	}
	if (_count - step02 == 70) {
		_list.emplace_back(make_shared<NormalEnemy>(Define::IN_W, Define::OUT_H, 8, 100, 11, 9, 2));
		return;
	}
	if (_count - step02 == 80) {
		_list.emplace_back(make_shared<NormalEnemy>(Define::IN_W, Define::OUT_H, 9, 100, 11, 0, 1));
		return;
	}
	if (_count - step02 == 90) {
		_list.emplace_back(make_shared<NormalEnemy>(Define::IN_W, Define::OUT_H, 8, 100, 11, 9, 2));
		return;
	}

	if (_count - step02 == 250) {
		_list.emplace_back(make_shared<NormalEnemy>(0.f, Define::OUT_H*0.7f, 8, 100, 12, 9, 2));
		_list.emplace_back(make_shared<NormalEnemy>(Define::IN_X+200, 0, 9, 100, 13, 10, 1));
		return;
	}
	if (_count - step02 == 260) {
		_list.emplace_back(make_shared<NormalEnemy>(0.f, Define::OUT_H*0.7f, 9, 100, 12, 0, 1));
		return;
	}
	if (_count - step02 == 270) {
		_list.emplace_back(make_shared<NormalEnemy>(0.f, Define::OUT_H*0.7f, 8, 100, 12, 9, 2));
		_list.emplace_back(make_shared<NormalEnemy>(Define::IN_X + 180, 0, 9, 100, 13, 10, 1));
		return;
	}
	if (_count - step02 == 280) {
		_list.emplace_back(make_shared<NormalEnemy>(0.f, Define::OUT_H*0.7f, 9, 100, 12, 0, 1));
		return;
	}
	if (_count - step02 == 290) {
		_list.emplace_back(make_shared<NormalEnemy>(0.f, Define::OUT_H*0.7f, 8, 100, 12, 9, 2));
		_list.emplace_back(make_shared<NormalEnemy>(Define::IN_X + 160, 0, 9, 100, 13, 10, 1));
		return;
	}
	if (_count - step02 == 300) {
		_list.emplace_back(make_shared<NormalEnemy>(0.f, Define::OUT_H*0.7f, 9, 100, 12, 0, 1));
		return;
	}
	if (_count - step02 == 310) {
		_list.emplace_back(make_shared<NormalEnemy>(0.f, Define::OUT_H*0.7f, 8, 100, 12, 9, 2));
		_list.emplace_back(make_shared<NormalEnemy>(Define::IN_X + 140, 0, 9, 100, 13, 10, 1));
		return;
	}
	if (_count - step02 == 320) {
		_list.emplace_back(make_shared<NormalEnemy>(0.f, Define::OUT_H*0.7f, 9, 100, 12, 0, 1));
		return;
	}
	if (_count - step02 == 330) {
		_list.emplace_back(make_shared<NormalEnemy>(0.f, Define::OUT_H*0.7f, 8, 100, 12, 9, 2));
		_list.emplace_back(make_shared<NormalEnemy>(Define::IN_X + 200, 0, 9, 100, 13, 10, 1));
		return;
	}
	if (_count - step02 == 340) {
		_list.emplace_back(make_shared<NormalEnemy>(0.f, Define::OUT_H*0.7f, 9, 100, 12, 0, 1));
		return;
	}
	if (_count - step02 == 350) {
		_list.emplace_back(make_shared<NormalEnemy>(0.f, Define::OUT_H*0.7f, 8, 100, 12, 9, 2));
		_list.emplace_back(make_shared<NormalEnemy>(Define::IN_X + 180, 0, 9, 100, 13, 10, 1));
		return;
	}
	if (_count - step02 == 360) {
		_list.emplace_back(make_shared<NormalEnemy>(0.f, Define::OUT_H*0.7f, 9, 100, 12, 0, 1));
		return;
	}
	if (_count - step02 == 370) {
		_list.emplace_back(make_shared<NormalEnemy>(0.f, Define::OUT_H*0.7f, 8, 100, 12, 9, 2));
		_list.emplace_back(make_shared<NormalEnemy>(Define::IN_X + 160, 0, 9, 100, 13, 10, 1));
		return;
	}
	if (_count - step02 == 380) {
		_list.emplace_back(make_shared<NormalEnemy>(0.f, Define::OUT_H*0.7f, 9, 100, 12, 0, 1));
		_list.emplace_back(make_shared<NormalEnemy>(Define::IN_X + 140, 0, 9, 100, 13, 10, 1));
		return;
	}
	if (_count - step02 == 540) {
		_list.emplace_back(make_shared<BigEnemy>(Define::CENTER_X - 180, 0.f, 0, 1200, 14, 6, 5));
		return;
	}
	if (_count - step02 == 600) {
		_list.emplace_back(make_shared<BigEnemy>(Define::CENTER_X + 180, 0.f, 0, 1200, 14, 8, 5));
		return;
	}*/
	/*第三阶段共840帧，后跟标题显示，下一阶段从2020帧起*/
	const int step03 = 0;
	if (_count - step03 == 0) {
		for (int i = 0; i < 7; i++) {
			_list.emplace_back(make_shared<NormalEnemy>(Define::IN_X + 100 + i * 100, 0.f, 8 + i % 2, 100, 15, 11, 2 - i % 2));
		}
		for (int i = 0; i < 8; i++) {
			_list.emplace_back(make_shared<NormalEnemy>(Define::IN_X + 50 + i * 100, Define::OUT_H, 8 + i % 2, 100, 15, 11, 2 - i % 2));
		}
		return;
	}
	if (_count - step03 == 140) {
		for (int i = 0; i < 8; i++) {
			_list.emplace_back(make_shared<NormalEnemy>(0.f, Define::IN_Y + 100 + i * 100, 10 + i % 2, 100, 16, 11, 2 - i % 2));
		}
		for (int i = 0; i < 9; i++) {
			_list.emplace_back(make_shared<NormalEnemy>(Define::OUT_W, Define::IN_Y + 50 + i * 100, 10 + i % 2, 100, 16, 11, 2 - i % 2));
		}
		return;
	}
	if (_count - step03 == 290) {
		_list.emplace_back(make_shared<NormalEnemy>(0.f, Define::CENTER_Y + 100 , 8, 100, 17, 12, 2));
		_list.emplace_back(make_shared<NormalEnemy>(Define::OUT_W, Define::CENTER_Y + 100, 8, 100, 17, 12, 2));
	}
	if (_count - step03 == 310) {
		_list.emplace_back(make_shared<NormalEnemy>(0.f, Define::CENTER_Y + 100, 8, 100, 17, 12, 2));
		_list.emplace_back(make_shared<NormalEnemy>(Define::OUT_W, Define::CENTER_Y + 100, 8, 100, 17, 12, 2));
	}
	if (_count - step03 == 330) {
		_list.emplace_back(make_shared<NormalEnemy>(0.f, Define::CENTER_Y + 100, 8, 100, 17, 12, 2));
		_list.emplace_back(make_shared<NormalEnemy>(Define::OUT_W, Define::CENTER_Y + 100, 8, 100, 17, 12, 2));
	}
	if (_count - step03 == 350) {
		_list.emplace_back(make_shared<NormalEnemy>(0.f, Define::CENTER_Y + 100, 8, 100, 17, 12, 2));
		_list.emplace_back(make_shared<NormalEnemy>(Define::OUT_W, Define::CENTER_Y + 100, 8, 100, 17, 12, 2));
	}
	if (_count - step03 == 370) {
		_list.emplace_back(make_shared<NormalEnemy>(0.f, Define::CENTER_Y + 100, 8, 100, 17, 12, 2));
		_list.emplace_back(make_shared<NormalEnemy>(Define::OUT_W, Define::CENTER_Y + 100, 8, 100, 17, 12, 2));
	}
	if (_count - step03 == 390) {
		_list.emplace_back(make_shared<NormalEnemy>(0.f, Define::CENTER_Y + 100, 8, 100, 17, 12, 2));
		_list.emplace_back(make_shared<NormalEnemy>(Define::OUT_W, Define::CENTER_Y + 100, 8, 100, 17, 12, 2));
	}
	if (_count - step03 == 410) {
		_list.emplace_back(make_shared<NormalEnemy>(0.f, Define::CENTER_Y + 100, 8, 100, 17, 12, 2));
		_list.emplace_back(make_shared<NormalEnemy>(Define::OUT_W, Define::CENTER_Y + 100, 8, 100, 17, 12, 2));

	}
	if (_count - step03 == 430) {
		_list.emplace_back(make_shared<NormalEnemy>(0.f, Define::CENTER_Y + 100, 8, 100, 17, 12, 2));
		_list.emplace_back(make_shared<NormalEnemy>(Define::OUT_W, Define::CENTER_Y + 100, 8, 100, 17, 12, 2));
	}
	if (_count - step03 == 450) {
		_list.emplace_back(make_shared<NormalEnemy>(0.f, Define::CENTER_Y + 100, 3, 800, 17, 0, 3));
		_list.emplace_back(make_shared<NormalEnemy>(Define::OUT_W, Define::CENTER_Y + 100, 3, 800, 17, 0, 3));
	}
	if (_count - step03 == 470) {
		_list.emplace_back(make_shared<BigEnemy>(Define::CENTER_X - 180, 0.f, 0, 2400, 14, 6, 5));
	}
	
}



