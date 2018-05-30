#include "TataraKogasa.h"
#include <DxLib.h>
#include "Image.h"
#include "Define.h"
#include "BGM.h"
#include "EffectManager.h"

TataraKogasa::TataraKogasa(float x, float y, int type, int hp, int movePatternID, int shotPatternID, int itemPatternID)
	:Boss(x, y, type, hp, movePatternID, shotPatternID, itemPatternID)
{
	MOVER = Define::BOSS_02_MOVER;
	SHOTER = Define::BOSS_02_SHOTER;
	ITEM = Define::BOSS_02_ITEM;
	HP = Define::BOSS_02_HP;
	TIME = Define::BOSS_02_TIME;
	_shotCount = 0;
	_shotFlag = false;
	BGM::getIns()->play(1);
	reset();
}
void TataraKogasa::draw() const
{
	if (_state == 1 && _spellEffectFlag && (_flag == 6 || _flag == 4 || _flag == 2 || _flag == 1)) {
		_spellEffectFlag = false;
		EffectManager::addSpellCardEffect(1);
	}

	DrawRotaGraphF(_x, _y, 2.5f + 0.8f*cos(_counter*Define::PI / 60), _counter % 60 * Define::PI / 30, Image::getIns()->getBossBackEffect(), TRUE);
	const static int imgID[6] = { 0,1,2,3,2,1 };
	const static int DimgID[6] = { 3,2,1,0,1,2 };
	int add;
	if (_shotFlag) {
		shotImage();
		changeDirection();
	}
	else
	{


		if (changeDirection()) {
			add = 4;
			int handle;
			if (abs(_change) > 0) {  //中向左右
				handle = Image::getIns()->getBoss02()[add + imgID[(_changeCount / 8) % 4]];
			}
			else {		//左右向中
				handle = Image::getIns()->getBoss02()[add + DimgID[(_changeCount / 8) % 4]];
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
			add = 0;
			const int handle = Image::getIns()->getBoss02()[add + imgID[(_counter / 8) % 4]];	//每8帧切换一次
			if (abs(_direction) > 0) {
				const int handle = Image::getIns()->getBoss02()[7];
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
	}
	bossHp.DrawBossHp(Define::BOSS_02_HP[_type - _flag], _hp, _flag);

	if (_state == 2)
		drawTime();

}
void TataraKogasa::reset()
{
	_spellEffectFlag = true;
	_endTime = Define::BOSS_02_TIME[_type - _flag] * 60;
	_state = 1;		//状态待机
	_waitTime = 0;
	_bossCount = 0;
	_shotPatternID = Define::BOSS_02_SHOTER[_type - _flag];
	_itemPatternID = Define::BOSS_02_ITEM[_type - _flag];
	_hp = Define::BOSS_02_HP[_type - _flag];
}

void TataraKogasa::changeMove() {
	_movePatternID = MOVER[_type - _flag];
}

void TataraKogasa::setSize()
{

	int handle = Image::getIns()->getEnemyNormal()[0];
	GetGraphSize(handle, &_width, &_height);

}

void TataraKogasa::shotImage() const
{
	if (_shotCount == 36) {
		_shotCount = 0;
		_shotFlag = false;
		return;
	}
	int handle = Image::getIns()->getBoss02Shot()[_shotImg[(_shotCount / 6) % 6]];
	_shotCount++;
	if (_direction < 0) {
		DrawRotaGraphF(_dx, _dy, 1.5, 0.0, handle, TRUE, TRUE);
	}
	else
	{
		DrawRotaGraphF(_dx, _dy, 1.5, 0.0, handle, TRUE);
	}
}
