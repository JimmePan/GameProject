#include "PlayerShot.h"
#include <Dxlib.h>
#include "Image.h"
#include "Define.h"


PlayerShot::PlayerShot(float x, float y, int kind) :
	_flag(1),
	_power(Define::PL_POWER[kind]),
	_RANGE(Define::PL_RANGE[kind]),
	_count(0),
	_x(x),
	_y(y),
	_angle(-Define::PI / 2),
	_speed(30),
	_kind(kind)
{
}


bool PlayerShot::update()
{
	if (_flag < 1)
		return false;
	this->_x += cos(this->_angle)*this->_speed;
	this->_y += sin(this->_angle)*this->_speed;
	_count++;
	return isInside();
}

void PlayerShot::draw() const
{
	if (_kind == 0)
		DrawRotaGraphF(_x, _y, 1.5, 0.0, Image::getIns()->getplayerShot1(), TRUE);
	if (_kind == 1)
		DrawRotaGraphF(_x, _y, 1.5, 0.0, Image::getIns()->getplayerShot2(), TRUE);
}



bool PlayerShot::isInside() const
{
	if (_x < -8.5 || Define::OUT_W + 8.5 < _x || _y < -32.5) {
		this->_flag = 0;
		return false;
	}
	return true;
}

int PlayerShot::get(unsigned int type) const
{
	return 0;
}



