#include "LogoEffect.h"
#include "Image.h"
#include "Define.h"
#include <DxLib.h>

LogoEffect::LogoEffect(float x, float y, int num)
{
	_flag = 1;
	_x = x;
	_y = y;
	_r = 1.f;
	_color = 0;
	_brightness = 0;
	_count = 0;
	_angle = 0;
	_eff = 1;
	switch (num)
	{
	case 1:
		_img = Image::getIns()->getSt01Logo();
		break;
	default:
		break;
	}
}

bool LogoEffect::update()
{
	if (_count < 128)
		_brightness += 2;
	if (_count > 256) {
		_brightness -= 2;
	}
	if (_count > 360) {
		_flag = 0;
		return false;
	}
	_count++;
	return true;
}

void LogoEffect::draw() const
{
	DrawRotaGraphF(_x, _y, _r, _angle, _img, TRUE);
}


