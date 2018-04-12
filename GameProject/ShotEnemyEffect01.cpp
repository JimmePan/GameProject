#include "ShotEnemyEffect01.h"
#include "Image.h"
#include "Define.h"
#include <DxLib.h>

ShotEnemyEffect01::ShotEnemyEffect01(float x, float y)
{
	_flag = 1;
	_x = x;
	_y = y;
	_r = 1.5f;
	_brightness = 225;
	_count = 0;
	_color = 0;
	_angle = 0;
	_eff = 1;

}

bool ShotEnemyEffect01::update()
{
	if (_count / 8 >= 4) {
		_flag = 0;	//Ïú»ÙÖ®
		return false;
	}
	else {
		_img = Image::getIns()->getShotEnemyEffect1()[_count / 8];
		_angle += Define::PI / 16;
		_brightness -= _count % 8;
		_y -= 2.0f;
	}
	_count++;
	return true;
}

void ShotEnemyEffect01::draw() const
{
	DrawRotaGraphF(_x, _y, _r, _angle, _img, TRUE);
}
