#pragma once

#include"Singleton.h"
#include <array>

class Keyboard final :public Singleton<Keyboard> {
	Keyboard() = default;
	friend Singleton <Keyboard>;
public:
	bool update();
	int getPressingCount(int keyCode);	//按键时间帧数
	int getReleasingCount(int keyCode);	//弹起时间帧数
private:
	static const int KEY_NUM = 256;
	std::array<int, KEY_NUM> _pressingCount;	//按键计数
	std::array<int, KEY_NUM> _releasingCount;	//弹键计数

	bool isAvailableCode(int keyCode);	//是否为有效按键输入

};

