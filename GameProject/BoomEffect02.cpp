#include "BoomEffect02.h"
#include "Define.h"
#include <DxLib.h>
#include "Image.h"

BoomEffect02::BoomEffect02(float x, float y,float angle)
{
	_flag = 1;
	_x = x + (rand() % 100 - 50);
	_y = y + (rand() % 50 - 10);
	_r = 0.75f;
	_brightness = 225;
	_count = 0;
	_color = 0;
	_angle = angle + Define::PI;
	_baseAngle = (float)(rand() / double(RAND_MAX))*Define::PI * 2;
	_eff = 2;
	_speed = (float)(rand() / double(RAND_MAX))*3.f ;
	_i = rand() % (4 - 0);
}

bool BoomEffect02::update()
{
	if (_count / 4 >= 12) {
		_flag = 0;	//Ïú»ÙÖ®
		return false;
	}
	else
	{
		_img = Image::getIns()->getBoomEffect()[_count / 4];
		_x = _x + cos(_angle) * _speed;
		_y = _y + sin(_angle) * _speed;
		if (_count / 4 >= 8)
			_brightness -= 5;
	}
	_count++;
	return true;
}

void BoomEffect02::draw() const
{

	if (_i % 3 == 0) {
		SetDrawBright(0, 0, 255);
	}
	else {
		SetDrawBright(255, 0, 0);
	}
	DrawRotaGraphF(_x, _y, _r, _baseAngle, _img, TRUE);
	SetDrawBright(255, 255, 255);
}
