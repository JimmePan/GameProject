#include "AbstractEnemy.h"
#include <Dxlib.h>
#include "Image.h"
#include "Define.h"



AbstractEnemy::AbstractEnemy(float x, float y, int type,int hp) :
	_flag(1),
	_x(x),
	_y(y),
	_speed(0),
	_angle(0),
	_counter(0),
	_width(0),
	_height(0),
	_hp(hp),
	_direction(0),
	_RANGE(0),
	_type(type),
	_moveFlag(true),
	_change(0),
	_changeCount(0)
{
}

void AbstractEnemy::initialize()
{
	setSize();
}

bool AbstractEnemy::update()
{
	if (_flag < 1) {
		_item.fall(this);
		return false;
	}
	_mover.move(this);
	_shoter.shot(this);

	_counter++;
	return isInside();
}

bool AbstractEnemy::changeDirection() const
{
	if (_change != _direction && _changeCount < 31) {	//处于转换状态,未超出转换时间
		_changeCount++;
		return true;
	}
	else if (_change != _direction && _changeCount >= 31)	//处于转换状态，转换时间转完，回归正常状态
	{

		_changeCount = 0;
		/*if (_direction < _change) {
			_direction++;
		}
		else {
			_direction--;
		}*/
		_direction = _change;
		return false;
	}
	else if (_change == _direction) {		//未处于转换状态
		return false;
	}

}

bool AbstractEnemy::isInside() const
{
	if (_counter < 60) {
		return true;
	}
	if (_x < -_width / 2 || Define::OUT_W + _width / 2 < _x || _y < -_height / 2 || Define::OUT_H + _height / 2 < _y) {
		return false;
	}
	return true;
}



