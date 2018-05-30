#include "Boss.h"
#include "Number.h"
#include "Define.h"
#include "CalcUtils.h"
#include "Sound.h"
#include "EnemyManager.h"

using namespace std;

const static int wtime = 140;
Boss::Boss(float x, float y, int type, int hp, int movePatternID, int shotPatternID, int itemPatternID)
	:AbstractEnemy(x, y, type, hp, movePatternID, shotPatternID, itemPatternID)
{
	PlaySoundMem(Sound::getIns()->getCh02(), DX_PLAYTYPE_BACK);
	_flag = type;
	_movePatternID = 4;		//归位
	_boss = true;
	_RANGE = -1.f;
	_spellEffectFlag = false;
}

bool Boss::update()
{
	if (_flag < 1) {
		PlaySoundMem(Sound::getIns()->getEnBreak01(), DX_PLAYTYPE_BACK);
		return false;
	}
	_mover.move(this);
	if (_state == 1 && _waitTime < wtime) {		//等待状态进行等待
		_waitTime++;
		_RANGE = -1.f;
	}
	else if (_state == 1 && _waitTime >= wtime) {
		_RANGE = 42.f;
		_state = 2;	//弹幕状态
		changeMove();
		_waitTime = 0;
	}
	if (_state == 2 && _hp <= 0) {	//击破
		_item.fall(this);
		_flag--;
		PlaySoundMem(Sound::getIns()->getEnBreak00(), DX_PLAYTYPE_BACK);
		reset();
		_moveFlag = true;
		CalcUtils::ClearBulletEn();
		EnemyManager::clearNormalEn();
		_movePatternID = 4;		//归位
	}
	if (_state == 2 && _endTime <= 0) {	//超时
		_flag--;
		reset();
		_moveFlag = true;
		CalcUtils::ClearBulletEn();
		EnemyManager::clearNormalEn();
		_movePatternID = 4;		//归位
	}
	if (_state == 2) {	//放出弹幕
		_shoter.shot(this);
		_bossCount++;
		_endTime--;

	}
	_dx = _x;
	_dy = _y + sin(2 * Define::PI / 130 * (_counter % 130)) * 15;
	_counter++;
	//_hp -= 5;
	return true;


}


void Boss::drawTime() const
{
	if (_endTime % 60 <= 20 && _endTime / 60 <= 10) {
		SetDrawBright(255, 0, 0);
		if (_endTime % 60 == 0) {
			PlaySoundMem(Sound::getIns()->getTimeout(), DX_PLAYTYPE_BACK);
		}
	}
	
	Number((float)_endTime / 60, 400, 100, 2, 2).draw();
	SetDrawBright(255, 255, 255);
}


