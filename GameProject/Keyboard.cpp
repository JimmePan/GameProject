#include "Keyboard.h"
#include <DxLib.h>

bool Keyboard::update() {
	char nowKeyStatus[KEY_NUM];
	GetHitKeyStateAll(nowKeyStatus);		//获得所有按键状态代码存至nowkeystatus数组
	for (int i = 0; i < KEY_NUM; i++)
	{
		if (nowKeyStatus[i] != 0) {			//如果i键被按下
			if (_releasingCount[i] > 0) {	//如果弹起计数器大于零
				_releasingCount[i] = 0;		//归零
			}
			_pressingCount[i]++;			//增加计数
		}
		else {								//如果i键被释放
			if (_pressingCount[i] > 0) {	//如果按键计数器大于零
				_pressingCount[i] = 0;		//归零
			}
			_releasingCount[i]++;			//增加计数
		}
	}
	return true;
}

int Keyboard::getPressingCount(int keyCode)
{
	if (!isAvailableCode(keyCode)) {
		return -1;
	}
	return _pressingCount[keyCode];
}

int Keyboard::getReleasingCount(int keyCode)
{
	if (!isAvailableCode(keyCode)) {
		return -1;
	}
	return _releasingCount[keyCode];
}

bool Keyboard::isAvailableCode(int keyCode)
{
	if (!(0 <= keyCode && keyCode < KEY_NUM)) {
		return false;
	}
	return true;
}
