#include "ShotEnemyEffect02.h"
#include "Image.h"
#include "Define.h"
#include <DxLib.h>

ShotEnemyEffect02::ShotEnemyEffect02(float x, float y)
{
	_flag = 1;
	_x = x;
	_y = y;
	_r = 1.5f;
	_brightness = 225;
	_count = 0;
	_color = 0;
	_angle = ((float)(rand() / double(RAND_MAX))-0.5f)*Define::PI/16;
	_eff = 1;
	_img = Image::getIns()->getplayerShot2();
	
}

bool ShotEnemyEffect02::update()
{
	_count++;
	_brightness -= 7;
	if (_count >= 30) {
		_flag = 0;	//����֮
		return false;
	}
	return true;
}

void ShotEnemyEffect02::draw() const
{
	DrawRotaGraphF(_x, _y, _r, _angle, _img, TRUE);
}
