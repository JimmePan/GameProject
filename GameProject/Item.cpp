#include "Item.h"
#include <Dxlib.h>
#include "Image.h"
#include "Define.h"

Item::Item(float x, float y, float angle, int kind) :
	_flag(1),
	_RANGE(16.0f),
	_count(0),
	_x(x),
	_y(y),
	_angle(angle),
	_speed(4),
	_kind(kind)
{
}

bool Item::update()
{
	if (_flag < 1)
		return false;
	if (_flag > 1) {
		_angle = shotatan2();
		_speed = 3.0f * _flag;
	}
	if (_kind == 7 && _count == 30) {
		_flag = 10;
	}
	this->_x += cos(this->_angle)*this->_speed;
	this->_y += sin(this->_angle)*this->_speed;
	if (_count == 30) {
		_angle = Define::PI / 2;
		_speed = 3;
	}
	_count++;
	return isInside();
}

void Item::draw() const
{
	if (_count <= 30) {
		DrawRotaGraphF(_x, _y, 1.5, _count*Define::PI / 5, Image::getIns()->getItem()[_kind], TRUE);
	}
	else
	{
		DrawRotaGraphF(_x, _y, 1.5, 0.0, Image::getIns()->getItem()[_kind], TRUE);
	}
}

bool Item::isInside() const
{
	if (Define::OUT_H + _RANGE * 2 < _y) {
		return false;
	}
	return true;
}

int Item::get(unsigned int type) const
{
	return 0;
}
