#include "BoomEffect02.h"
#include "Define.h"
#include "Macro.h"
#include "Image.h"

BoomEffect02::BoomEffect02(float x, float y)
{
	_flag = 1;
	_x = x + (rand() % 40 - 20);
	_y = y + (rand() % 40 - 20);
	_r = 1.0f;
	_brightness = 225;
	_count = 0;
	_color = 0;
	_angle = 0.f;
	_eff = 2;
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
		if (_count / 4 >= 8)
			_brightness -= 5;
	}
	_count++;
}

void BoomEffect02::draw() const
{
	SetDrawBright(255, 64, 0);
	DrawRotaGraphF(_x, _y, _r, _angle, _img, TRUE);
	SetDrawBright(255, 255, 255);
}
