#include "Bullet.h"
#include <cmath>
#include "DxLib.h"
#include "Define.h"
#include "EffectManager.h"

Bullet::Bullet(float x, float y, unsigned int type, unsigned int color, int state, float angle, float base_angle, float speed, float rate)
{
	_flag = 1;
	_x = x;
	_y = y;
	_type = type;
	_color = color;
	_count = 0;
	_graze = TRUE;
	_state = state;
	_angle = angle;
	_speed = speed;
	_rate = rate;
	_base_angle = base_angle;
	_sort = ImageBullet::getIns()->SORT_Z[type];
	_range = ImageBullet::getIns()->RANGE[type] * _rate;

}

bool Bullet::update()
{
	if (_flag < 1 && _count >= _till) {
		EffectManager::addBulletBreakEffect(_x, _y, _color);
		return false;
	}
	bulletChange();
	_count++;
	_x = _x + cos(_angle)*_speed;
	_y = _y + sin(_angle)*_speed;


	return isInside();
}

void Bullet::draw() const
{
	DrawRotaGraphF(_x, _y, _rate, _base_angle - Define::PI / 2, ImageBullet::getIns()->get(_type, _color), TRUE);
}

bool Bullet::isInside() const
{
	if (_count <= 90) {
		return true;
	}
	if (_x < -_range - 10.f || Define::OUT_W + _range + 10.f < _x || _y < -_range - 10.f || Define::OUT_H + _range + 10.f < _y) {
		_flag = 0;
		return false;
	}
	return true;
}

void Bullet::bulletChange()
{
	if (_state == 22) {
		_base_angle = _base_angle + Define::PI / 15;
	}
	if (_state == 22 && _count == 30) {
		_speed = 2.7f;
	}

	if (_state == 5 && _count == 10) {
		_speed = 4.f;
		_state = 1005;
	}

	if (_count < 16 && _state == 20) {
		_rate = _count / 15.f;
	}
	if (_count == 16 && _state == 20) {
		_state = 1020;
	}
	if (_state == 1020 && _count == 60) {
		_speed = _speed - 3.f;
		_state = 0;
	}

	if (_count < 16 && _state == 21) {
		_rate = _count / 15.f;
	}
	if (_count == 16 && _state == 21) {
		_state = 1021;
	}
	if (_state == 1021 && _count == 60) {
		_speed = _speed - 3.f;
		_state = 0;
	}
}
