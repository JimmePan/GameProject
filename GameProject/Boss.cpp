#include "Boss.h"
#include "Define.h"

using namespace std;

const static int wtime = 140;
Boss::Boss(float x, float y, int type,int hp) :AbstractEnemy(x, y, type, hp)
{
	
	_flag = type;
	_movePatternID = 4;		//��λҡ��
	_boss = true;
	_RANGE = 0.f;
}

bool Boss::update()
{
	if (_flag < 1) {
		return false;
	}
	_mover.move(this);
	if (_state == 1 &&_waitTime < wtime) {		//�ȴ�״̬���еȴ�
		_waitTime++;
		_RANGE = 0.f;
	}
	else if (_state == 1 && _waitTime >= wtime) {
		_RANGE = 60.f;
		_state = 2;	//��Ļ״̬
		changeMove();
		_waitTime = 0;
	}
	if (_state == 2 && _hp <= 0) {	//����
		_item.fall(this);
		_flag--;
		reset();
		_moveFlag = true;
		_movePatternID = 4;		//��λҡ��
	}
	if (_state == 2 && _endTime <= 0) {	//��ʱ
		_flag--;
		reset();
		_moveFlag = true;
		_movePatternID = 4;		//��λҡ��
	}
	if (_state == 2) {	//�ų���Ļ
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


