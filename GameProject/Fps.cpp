#include "Fps.h"
#include <Dxlib.h>
#include "CalcUtils.h"

const static int LIST_LEN_MAX = 120;//���120֡����
const static int FPS = 60;			//FPS
const static int UPINTVL = 60;		//ÿ60֡����һ��

Fps::Fps():_counter(0),_fps(0)
{
}

void Fps::wait()
{
	_counter++;
	Sleep(getWaitTime());
	regist();
	if (_counter == UPINTVL) {
		updateAverage();
		_counter = 0;
	}
}

void Fps::draw() const
{
	if (_fps == 0) {
		return;
	}
	DrawFormatString(0, 0, GetColor(255, 255, 255), "%04.1ffps", _fps);
}

void Fps::updateAverage()
{
	int len = (int)_list.size();
	if (len < LIST_LEN_MAX) {		//�����������ƲŽ��м�����򷵻�
		return;
	}
	int tookTime = _list.back() - _list.front(); //���֡����Ҫ��ʱ��
	float average = (float)tookTime / (len - 1);
	if (average == 0) {
		return;
	}
	_fps = CalcUtils::roundPoint(1000 / average, 2);//���֡��

}

void Fps::regist()
{
	_list.push_back(GetNowCount());		//��¼��ǰʱ��
	if (_list.size() > LIST_LEN_MAX) {
		_list.pop_front();
	}
}

unsigned Fps::getWaitTime() const
{
	int len = (int)_list.size();
	if (len == 0) {
		return 0;

	}
	int shouldTookTime = (int)(1000 / 60.f*(len));	//���ۿ���
	int actuallyTookTime = GetNowCount() - _list.front();	//ʵ�ʿ���
	int waitTime = shouldTookTime - actuallyTookTime;	//�ȴ�ʱ��
	waitTime = waitTime > 0 ? waitTime : 0;
	return (unsigned)(waitTime);

}



