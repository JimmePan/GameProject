#include "Boss.h"
#include "Define.h"

using namespace std;

const static int wtime = 140;
Boss::Boss(float x, float y, int type,int hp) :AbstractEnemy(x, y, type, hp)
{
	
	_flag = type;
	_movePatternID = 4;		//¹éÎ»Ò¡°Ú
	_boss = true;
	_RANGE = 0.f;
}

bool Boss::update()
{
	if (_flag < 1) {
		return false;
	}
	_mover.move(this);
	if (_state == 1 &&_waitTime < wtime) {		//µÈ´ý×´Ì¬½øÐÐµÈ´ý
		_waitTime++;
		_RANGE = 0.f;
	}
	else if (_state == 1 && _waitTime >= wtime) {
		_RANGE = 60.f;
		_state = 2;	//µ¯Ä»×´Ì¬
		changeMove();
		_waitTime = 0;
	}
	if (_state == 2 && _hp <= 0) {	//»÷ÆÆ
		_item.fall(this);
		_flag--;
		reset();
		_moveFlag = true;
		_movePatternID = 4;		//¹éÎ»Ò¡°Ú
	}
	if (_state == 2 && _endTime <= 0) {	//³¬Ê±
		_flag--;
		reset();
		_moveFlag = true;
		_movePatternID = 4;		//¹éÎ»Ò¡°Ú
	}
	if (_state == 2) {	//·Å³öµ¯Ä»
		_shoter.shot(this);
		_bossCount++;
		_endTime--;
	}
	_dx = _x;
	_dy = _y + sin(2*Define::PI / 130 * (_counter % 130)) * 15;
	_counter++;
	//_hp -= 20;
	return true;


}


