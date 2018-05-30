#include "Cirno.h"
#include <DxLib.h>
#include "Image.h"
#include "Define.h"
#include "EffectManager.h"

Cirno::Cirno(float x, float y, int type, int hp, int movePatternID, int shotPatternID, int itemPatternID)
	:Boss(x, y, type, hp, movePatternID, shotPatternID, itemPatternID)
{
	MOVER = Define::BOSS_01_MOVER;
	SHOTER = Define::BOSS_01_SHOTER;
	ITEM = Define::BOSS_01_ITEM;
	HP = Define::BOSS_01_HP;
	TIME = Define::BOSS_01_TIME;
	reset();
}
void Cirno::draw() const
{
	if (_state == 1 && _spellEffectFlag && (_flag == 3 || _flag == 1)) {
		_spellEffectFlag = false;
		EffectManager::addSpellCardEffect(0);
	}
	DrawRotaGraphF(_x, _y, 2.5f + 0.8f*cos(_counter*Define::PI / 60), _counter % 60 * Define::PI / 30, Image::getIns()->getBossBackEffect(), TRUE);
	const static int imgID[6] = { 0,1,2,3,2,1 };
	const static int DimgID[6] = { 3,2,1,0,1,2 };
	int add;

	if (changeDirection()) {
		add = 4;
		int handle;
		if (abs(_change) > 0) {  //中向左右
			handle = Image::getIns()->getBoss01()[add + imgID[(_changeCount / 8) % 4]];
		}
		else {		//左右向中
			handle = Image::getIns()->getBoss01()[add + DimgID[(_changeCount / 8) % 4]];
		}
		if ((_change < 0 || _direction < 0) && (_direction - _change >= -1)) {	//鏡像
			DrawRotaGraphF(_dx, _dy, 1.5, 0.0, handle, TRUE, TRUE);
		}
		else {																//正像
			DrawRotaGraphF(_dx, _dy, 1.5, 0.0, handle, TRUE);
		}

	}
	else
	{
		add = _direction != 0 ? 8 : 0;
		int i = add + imgID[(_counter / 8) % 6];
		const int handle = Image::getIns()->getBoss01()[add + imgID[(_counter / 8) % 4]];	//每8帧切换一次
		if (abs(_direction) > 0) {
			const int handle = Image::getIns()->getBoss01()[7];
			if (_direction < 0) {
				DrawRotaGraphF(_dx, _dy, 1.5, 0.0, handle, TRUE, TRUE);
			}
			else
			{
				DrawRotaGraphF(_dx, _dy, 1.5, 0.0, handle, TRUE);
			}
		}
		else
		{
			DrawRotaGraphF(_dx, _dy, 1.5, 0.0, handle, TRUE);
		}
	}
	bossHp.DrawBossHp(Define::BOSS_01_HP[_type - _flag], _hp, _flag);

	if (_state == 2)
		drawTime();

}
void Cirno::reset()
{
	_spellEffectFlag = true;
	_endTime = Define::BOSS_01_TIME[_type - _flag] * 60;
	_state = 1;		//状态待机
	_waitTime = 0;
	_bossCount = 0;
	_shotPatternID = Define::BOSS_01_SHOTER[_type - _flag];
	_itemPatternID = Define::BOSS_01_ITEM[_type - _flag];
	_hp = Define::BOSS_01_HP[_type - _flag];
}

void Cirno::changeMove() {
	_movePatternID = MOVER[_type - _flag];
}

void Cirno::setSize()
{

	int handle = Image::getIns()->getEnemyNormal()[0];
	GetGraphSize(handle, &_width, &_height);

}
