#pragma once

#include"Singleton.h"
#include <array>

class Keyboard final :public Singleton<Keyboard> {
	Keyboard() = default;
	friend Singleton <Keyboard>;
public:
	bool update();
	int getPressingCount(int keyCode);	//����ʱ��֡��
	int getReleasingCount(int keyCode);	//����ʱ��֡��
private:
	static const int KEY_NUM = 256;
	std::array<int, KEY_NUM> _pressingCount;	//��������
	std::array<int, KEY_NUM> _releasingCount;	//��������

	bool isAvailableCode(int keyCode);	//�Ƿ�Ϊ��Ч��������

};

