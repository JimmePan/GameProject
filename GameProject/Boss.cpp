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

	_flag = type;
	_movePatternID = 4;		//¹éÎ»
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
	if (_state == 1 && _waitTime < wtime) {		//µÈ´ý×´Ì¬½øÐÐµÈ´ý
		_waitTime++;
		_RANGE = -1.f;
	}
	else if (_state == 1 && _waitTime >= wtime) {
		_RANGE = 42.f;
		_state = 2;	//µ¯Ä»×´Ì¬
		changeMove();
		_waitTime = 0;
	}
	if (_state == 2 && _hp <= 0) {	//»÷ÆÆ
		_item.fall(this);
		_flag--;
		PlaySoundMem(Sound::getIns()->getEnBreak00(), DX_PLAYTYPE_BACK);
		reset();
		_moveFlag = true;
		CalcUtils::ClearBulletEn();
		EnemyManager::clearNormalEn();
		_movePatternID = 4;		//¹éÎ»
	}
	if (_state == 2 && _endTime <= 0) {	//³¬Ê±
		_flag--;
		reset();
		_moveFlag = true;
		CalcUtils::ClearBulletEn();
		EnemyManager::clearNormalEn();
		_movePatternID = 4;		//¹éÎ»
	}
	if (_state == 2) {	//·Å³öµ¯Ä»
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


