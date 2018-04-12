#include "Keyboard.h"
#include <DxLib.h>

bool Keyboard::update() {
	char nowKeyStatus[KEY_NUM];
	GetHitKeyStateAll(nowKeyStatus);		//������а���״̬�������nowkeystatus����
	for (int i = 0; i < KEY_NUM; i++)
	{
		if (nowKeyStatus[i] != 0) {			//���i��������
			if (_releasingCount[i] > 0) {	//������������������
				_releasingCount[i] = 0;		//����
			}
			_pressingCount[i]++;			//���Ӽ���
		}
		else {								//���i�����ͷ�
			if (_pressingCount[i] > 0) {	//�������������������
				_pressingCount[i] = 0;		//����
			}
			_releasingCount[i]++;			//���Ӽ���
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
