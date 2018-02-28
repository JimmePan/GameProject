#include "Fps.h"
#include <Dxlib.h>
#include "CalcUtils.h"

const static int LIST_LEN_MAX = 120;//最大120帧处理
const static int FPS = 60;			//FPS
const static int UPINTVL = 60;		//每60帧更新一次

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
	if (len < LIST_LEN_MAX) {		//超过最大积累制才进行计算否则返回
		return;
	}
	int tookTime = _list.back() - _list.front(); //最大帧数需要的时间
	float average = (float)tookTime / (len - 1);
	if (average == 0) {
		return;
	}
	_fps = CalcUtils::roundPoint(1000 / average, 2);//获得帧数

}

void Fps::regist()
{
	_list.push_back(GetNowCount());		//记录当前时间
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
	int shouldTookTime = (int)(1000 / 60.f*(len));	//理论开销
	int actuallyTookTime = GetNowCount() - _list.front();	//实际开销
	int waitTime = shouldTookTime - actuallyTookTime;	//等待时间
	waitTime = waitTime > 0 ? waitTime : 0;
	return (unsigned)(waitTime);

}



