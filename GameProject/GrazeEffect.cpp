#include "GrazeEffect.h"
#include "Image.h"
#include "Define.h"
#include <DxLib.h>

GrazeEffect::GrazeEffect(float x, float y)
{
	_flag = 1;
	_x = x;
	_y = y;
	_r = 0.35f - (float)(rand() / double(RAND_MAX))*0.1f;
	_brightness = 255;
	_count = 0;
	_color = 0;
	_angle = (float)(rand() / double(RAND_MAX))*Define::PI * 2;
	_img = Image::getIns()->getPlayerGraze();
	_eff = 1;
	_speed = (float)(rand() / double(RAND_MAX) + 2) ;
}

bool GrazeEffect::update()
{
	if (_count / 8 >= 4) {
		_flag = 0;	//Ïú»ÙÖ®
		return false;
	}
	else {
		_brightness -= _count % 8;
		//_brightness -= 5;
		_r -= 0.005f;
		_x = _x + cos(_angle)*_speed;
		_y = _y + sin(_angle)*_speed;
	}
	_count++;
	return true;
}

void GrazeEffect::draw() const
{
	DrawRotaGraphF(_x, _y, _r, 0.0f, _img, TRUE);
}
