#include "Player.h"
#include "Pad.h"
#include <Dxlib.h>
#include "Image.h"
#include "Define.h"
#include "PlayerShotManager.h"
#include "EffectManager.h"

using namespace std;
const static float SPEED = 9.f;


float Player::pl_x;
float Player::pl_y;
bool Player::_powerMax = false;

Player::Player() :_x((float)Define::CENTER_X), _y((float)Define::OUT_H*0.8f), _counter(0), //_change(0),
_direction(0), _changeCount(0), _slow(false),_bomFlag(false), _flag(0), _mutekicnt(0),
_range(3.8f)//应该根据不同机体变化判定点大小
//,_power(Define::POWER_MIN)
, _power(3.95f)
{
}

bool Player::update()
{
	bool flag = _powerMax;
	if (_flag == 1) {		//决死处理，时间为1/6秒
		if (_counter > 10) {
			_flag = 2;
			_counter = 0;
		}
	}

	if (_counter == 0 && _flag == 2) {		//如果当前瞬间死掉的话
		_x = (float)Define::CENTER_X;				//重设坐标
		_y = (float)Define::OUT_H + 30;
		_power = Define::POWER_MIN;				//火力归零
		_powerMax = false;
		_mutekicnt++;
	}

	if (_flag == 2) {			//如果已经死掉正在上浮的话
		_y -= 4;
		if (_counter > 55) {
			_counter = 0;
			_flag = 3;
		}
		_counter++;
		return true;
	}

	if (_mutekicnt > 0) {//如果无敌状态不为0的话
		_mutekicnt++;
		if (_mutekicnt > 240) {//如果已经4秒以上的话
			_flag = 0;
			_mutekicnt = 0;//还原
			_bomFlag = false;
		}
	}
	_counter++;
	move();
	shot();
	boom();
	/*if (_power < 4.01f)
		_power += 0.01f;*/
	return true;
}

void Player::draw() const
{
	const static int imgID[14] = { 0,1,2,3,4,5,6,7,6,5,4,3,2,1 };
	const static int DimgID[6] = { 0,1,2,3,2,1 };
	/*if (_change == _direction) {*/

	DrawFormatString(0, 35, GetColor(255, 255, 255), "power：%f", +_power);

	if (_mutekicnt == 0) {
		if (_direction == 0) {
			DrawRotaGraphF(_x, _y, 1.5, 0.0, Image::getIns()->getPlayer()[imgID[(_counter / 8) % 14]], TRUE);
			_changeCount = 0;
		}
		if (_direction == 1) {
			DrawRotaGraphF(_x, _y, 1.5, 0.0, Image::getIns()->getPlayer()[12 + DimgID[(_counter / 8) % 6]], TRUE);
			_changeCount = 0;
		}
		if (_direction == 2) {
			DrawRotaGraphF(_x, _y, 1.5, 0.0, Image::getIns()->getPlayer()[20 + DimgID[(_counter / 8) % 6]], TRUE);
			_changeCount = 0;
		}
	}
	else {
		if (_direction == 0) {
			DrawRotaGraphF(_x, _y, 1.5, 0.0, Image::getIns()->getPlayerMuteki()[imgID[(_counter / 8) % 14]], TRUE);
			_changeCount = 0;
		}
		if (_direction == 1) {
			DrawRotaGraphF(_x, _y, 1.5, 0.0, Image::getIns()->getPlayerMuteki()[12 + DimgID[(_counter / 8) % 6]], TRUE);
			_changeCount = 0;
		}
		if (_direction == 2) {
			DrawRotaGraphF(_x, _y, 1.5, 0.0, Image::getIns()->getPlayerMuteki()[20 + DimgID[(_counter / 8) % 6]], TRUE);
			_changeCount = 0;
		}
	}
	if (_slow) {
		DrawRotaGraphF(_x, _y, 1.5, Define::PI * 2 / 120 * _counter + Define::PI / 8, Image::getIns()->getSlowPlayer()[0], TRUE);
		DrawRotaGraphF(_x, _y, 1.5, -Define::PI * 2 / 120 * _counter, Image::getIns()->getSlowPlayer()[0], TRUE);
	}

	/*
	子型号子弹阴阳玉
	*/
	for (int i = 0; i < _power; i++) {
		if (_slow) {
			DrawRotaGraphF(_x + 30.f*cos(2 * Define::PI / 60.0f * (_counter % 120) + Define::PI * 2 / (int)_power*i),
				_y + 30.f*sin(2 * Define::PI / 60.0f * (_counter % 120) + Define::PI * 2 / (int)_power*i),
				1.5, -Define::PI * 2 / 120 * _counter, Image::getIns()->getOnmyou()[0], TRUE);
		}
		else {
			DrawRotaGraphF(_x + 100.f*cos(2 * Define::PI / 60.0f * (_counter % 60) + Define::PI * 2 / (int)_power*i),
				_y + 100.f*sin(2 * Define::PI / 60.0f * (_counter % 120) + Define::PI * 2 / (int)_power*i),
				1.5, -Define::PI * 2 / 120 * _counter, Image::getIns()->getOnmyou()[0], TRUE);
		}
	}


	/*}*/
	//else {
	//	if (_change == 0 && _changeCount < 32) {			//归中转向,进行
	//		DrawRotaGraphF(_x, _y, 1.5, 0.0, Image::getIns()->getPlayer()[3 + _direction * 8 - DimgID[(_changeCount / 2) % 4]], TRUE);
	//		_changeCount++;
	//	}
	//	else if (_change == 0 && _changeCount >= 32) {									//归中转向，结束
	//		DrawRotaGraphF(_x, _y, 1.5, 0.0, Image::getIns()->getPlayer()[0 + _direction * 8], TRUE);
	//		_changeCount = 0;
	//		_direction = _change;
	//	}

	//	if (_change != 0 && _changeCount < 32) {	//转向进行
	//		DrawRotaGraphF(_x, _y, 1.5, 0.0, Image::getIns()->getPlayer()[_direction * 8 + DimgID[(_changeCount / 2) % 4]], TRUE);
	//		_changeCount++;
	//	}
	//	else if (_change != 0 && _changeCount >= 32) {									//转向，结束
	//		DrawRotaGraphF(_x, _y, 1.5, 0.0, Image::getIns()->getPlayer()[4 + _direction * 8], TRUE);
	//		_changeCount = 0;
	//		_direction = _change;
	//	}
	//	}

}

void Player::move()
{
	float moveX = 0, moveY = 0;
	if (Pad::getIns()->get(ePad::left) > 0) {
		if (_direction != 1)
		{
			_direction = 1;
		}
		moveX -= SPEED;
	}
	if (Pad::getIns()->get(ePad::right) > 0) {
		if (_direction != 2)
		{
			_direction = 2;
		}
		moveX += SPEED;
	}
	if (Pad::getIns()->get(ePad::down) > 0) {
		moveY += SPEED;
	}
	if (Pad::getIns()->get(ePad::up) > 0) {
		moveY -= SPEED;
	}
	if (!moveX) {
		_direction = 0;
	}
	if (moveX && moveY) {
		moveX /= (float)sqrt(2.0);
		moveY /= (float)sqrt(2.0);
	}

	if (Pad::getIns()->get(ePad::slow) > 0) {
		_slow = true;
		moveX /= 3;
		moveY /= 3;
	}
	else
	{
		_slow = false;
	}
	if (moveX + _x < Define::IN_X) {
		_x = (float)Define::IN_X;
	}
	else if (moveX + _x > Define::IN_X + Define::IN_W) {
		_x = (float)(Define::IN_X + Define::IN_W);
	}
	else
	{
		_x += moveX;
	}
	if (moveY + _y < Define::IN_Y) {
		_y = (float)Define::IN_Y;
	}
	else if (moveY + _y > Define::IN_Y + Define::IN_H) {
		_y = (float)(Define::IN_Y + Define::IN_H);
	}
	else
	{
		_y += moveY;
	}

	pl_x = _x;		//权宜之计
	pl_y = _y;
}

void Player::shot()
{
	if (Pad::getIns()->get(ePad::shot) > 0) {
		//if (true) {
		_shotCount++;
		if (_shotCount % 6 == 0) {
			PlayerShotManager::add(_x - 16.0f, _y, 0);
			PlayerShotManager::add(_x + 16.0f, _y, 0);
			if (_power >= 1.00f) {
				if (_slow) {	//低速
					for (int i = 0; i < _power; i++) {
						PlayerShotManager::add(_x + 50.f*cos(2 * Define::PI / 60.0f * (_counter % 120) + Define::PI * 2 / (int)_power*i) - 8,
							_y + 50.f*sin(2 * Define::PI / 60.0f * (_counter % 120) + Define::PI * 2 / (int)_power*i), 1);
						PlayerShotManager::add(_x + 50.f*cos(2 * Define::PI / 60.0f * (_counter % 120) + Define::PI * 2 / (int)_power*i) + 8,
							_y + 50.f*sin(2 * Define::PI / 60.0f * (_counter % 120) + Define::PI * 2 / (int)_power*i), 1);
					}
				}
				else
				{

					for (int i = 0; i < _power; i++) {
						PlayerShotManager::add(_x + 100.f*cos(2 * Define::PI / 60.0f * (_counter % 60) + Define::PI * 2 / (int)_power*i) - 8,
							_y + 100.f*sin(2 * Define::PI / 60.0f * (_counter % 60) + Define::PI * 2 / (int)_power*i), 1);
						PlayerShotManager::add(_x + 100.f*cos(2 * Define::PI / 60.0f * (_counter % 60) + Define::PI * 2 / (int)_power*i) + 8,
							_y + 100.f*sin(2 * Define::PI / 60.0f * (_counter % 60) + Define::PI * 2 / (int)_power*i), 1);
					}
				}
			}
		}
	}
	else {
		_shotCount = 5;
	}
}

void Player::boom()
{
	if (Pad::getIns()->get(ePad::bom) > 0 && !_bomFlag) {
		EffectManager::addBoomEffect01();	//根据自机类型，加入boom特效编号,暂时没有
		_bomFlag = true;
		_bomRange = 240.f;
		_flag = 3;
		_mutekicnt++;
	}
}



