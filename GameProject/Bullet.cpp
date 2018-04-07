#include "Bullet.h"
#include <cmath>
#include "DxLib.h"
#include "Define.h"

Bullet::Bullet(float x, float y,unsigned int type, unsigned int color,int state,float angle,float base_angle,float speed,float rate)
{
	_flag = 1;
	_x = x;
	_y = y;
	_type = type;
	_color = color;
	_count = 0;
	_state = state;
	_angle = angle;
	_speed = speed;
	_rate = rate;
	//_till = 90;
	_base_angle[0] = base_angle;
	_sort = ImageBullet::getIns()->SORT_Z[type];
	_range = ImageBullet::getIns()->RANGE[type]*_rate;
	
}

bool Bullet::update()
{
	if (_flag < 1) {
		return false;
	}
	_count++;
	_x = _x + cos(_angle)*_speed;
	_y = _y + sin(_angle)*_speed;

	
	return isInside();
}

void Bullet::draw() const
{
	DrawRotaGraphF(_x,_y, _rate, _base_angle[0], ImageBullet::getIns()->get(_type,_color),TRUE);
}

bool Bullet::isInside() const
{
	if (_count < 60) {
		return true;
	}
	if (_x < -_range-10.f  || Define::OUT_W + _range+10.f  < _x || _y < -_range- 10.f || Define::OUT_H + _range +10.f < _y) {
		_flag = 0;
		return false;
	}
	return true;
}