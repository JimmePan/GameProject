#include "Player.h"
#include "Pad.h"
#include <Dxlib.h>
#include "Image.h"
#include "Define.h"
#include "PlayerShotManager.h"

using namespace std;
const static float SPEED = 9;

Player::Player() :_x((float)Define::CENTER_X), _y((float)Define::OUT_H*0.8f), _counter(0), //_change(0),
_direction(0), _changeCount(0), _slow(false), _power(0.00f)
//_playerShotManager(make_shared<PlayerShotManager>())
{
}

bool Player::update()
{
	_counter++;
	move();
	shot();
	/*if (_power < 4.01f)
		_power += 0.01f;*/
	return true;
}

void Player::draw() const
{
	const static int imgID[14] = { 0,1,2,3,4,5,6,7,6,5,4,3,2,1 };
	const static int DimgID[6] = { 0,1,2,3,2,1 };
	/*if (_change == _direction) {*/



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
	if (_slow) {
		DrawRotaGraphF(_x, _y, 1.5, Define::PI * 2 / 120 * _counter + Define::PI / 8, Image::getIns()->getSlowPlayer()[0], TRUE);
		DrawRotaGraphF(_x, _y, 1.5, -Define::PI * 2 / 120 * _counter, Image::getIns()->getSlowPlayer()[0], TRUE);
	}

	/*
	子型号子弹阴阳玉
	*/
	for (int i = 0; i < _power; i++) {
		if (_slow) {
			DrawRotaGraphF(_x + 50.f*cos(2 * Define::PI / 60.0f * (_counter % 120) + Define::PI * 2 / (int)_power*i),
				_y + 50.f*sin(2 * Define::PI / 60.0f * (_counter % 120) + Define::PI * 2 / (int)_power*i),
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



