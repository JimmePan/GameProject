#include "BulletBreakEffect.h"
#include "Define.h"
#include <DxLib.h>
#include "Image.h"

BulletBreakEffect::BulletBreakEffect(float x, float y, int color)
{
	_flag = 1;
	_x = x;
	_y = y;
	_r = 1.0f;
	_brightness = 225;
	_count = 0;
	_color = color;
	_angle = (float)(rand() / double(Define::PI * 2));
	_eff = 2;
}

bool BulletBreakEffect::update()
{
	if (_count / 4 >= 8) {
		_flag = 0;	//Ïú»ÙÖ®
		return false;
	}
	else
	{
		_img = Image::getIns()->getBulletBreak()[_count / 4];
		if (_count / 4 >= 4)
			_brightness -= 5;
	}
	_count++;
	return true;
}

void BulletBreakEffect::draw() const
{
	switch (_color)
	{
	case 0:
		SetDrawBright(0, 0, 255);
		break;
	case 1:
		SetDrawBright(190, 0, 255);
		break;
	case 2:
		SetDrawBright(255, 0, 127);
		break;
	case 3:
		SetDrawBright(255, 64, 0);
		break;
	case 4:
		SetDrawBright(255, 255, 0);
		break;
	case 5:
		SetDrawBright(64, 255, 0);
		break;
	case 6:
		SetDrawBright(0, 255, 127);
		break;
	case 7:
		SetDrawBright(0, 190, 255);
		break;
	case 8:
		SetDrawBright(225, 225, 225);
		break;

	default:
		break;
	}
	DrawRotaGraphF(_x, _y, _r, _angle, _img, TRUE);
	SetDrawBright(255, 255, 255);
}



