#include "BoomEffect01.h"
#include "Define.h"
#include "Image.h"
#include <DxLib.h>
#include "Player.h"
BoomEffect01::BoomEffect01(int imgCount)
{
	_flag = 1;
	_r = 1.5f;
	_imgCount = imgCount;
	_brightness = (int)(200 / pow(1.3f, _imgCount));
	_img = Image::getIns()->getPl00BoomA();
	_count = 0 - _imgCount;
	_color = 0;
	_angle = -Define::PI / 2;
	_eff = 2;
}

bool BoomEffect01::update()
{
	_x = Player::getX();
	_y = Player::getY() - 6 * _r;

	if (_count / 30 % 2 > 0) {		//半圆时间为30帧
		if (_angle > -Define::PI / 2 + 0.01f) {
			_angle = Define::PI / 2 - Define::PI / 256 * (_count % 30)*(_count % 30);
		}
		_turnFlag = true;
	}
	else
	{
		if (_angle < Define::PI / 2 - 0.01f) {
			_angle = -Define::PI / 2 + Define::PI / 256 * (_count % 30)*(_count % 30);
		}
		_turnFlag = false;
	}

	if (_count > 240 - _imgCount) {
		_flag = 0;	//销毁之
		return false;
	}
	else
	{
		_count++;
	}
	return true;
}

void BoomEffect01::draw() const
{
	SetDrawBright(255, 255 - (20 * _imgCount), 255);
	if (_turnFlag)
		DrawRotaGraph2F(_x, _y, 33, 174, _r, _angle, _img, TRUE, TRUE);
	else
	{
		DrawRotaGraph2F(_x, _y, 122, 174, _r, _angle, _img, TRUE);
	}
	SetDrawBright(255, 255, 255);

}
