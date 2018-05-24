#include "UFOEnemy.h"
#include <DxLib.h>
#include "Image.h"
#include "CalcUtils.h"


UFOEnemy::UFOEnemy(float x, float y, int type, int hp, int movePatternID, int shotPatternID, int itemPatternID)
	:AbstractEnemy(x, y, type, hp, movePatternID, shotPatternID, itemPatternID)
{
	_RANGE = 28;
	_baseAngle = Define::PI / 8;
}

void UFOEnemy::draw() const
{
	switch (_type)
	{
	case 0:
		DrawRotaGraphF(_x, _y, 0.9f, _baseAngle, Image::getIns()->getUFOEnemy()[0 + (_counter / 8) % 4], TRUE);
		break;
	case 1:
		DrawRotaGraphF(_x, _y, 0.9f, _baseAngle, Image::getIns()->getUFOEnemy()[4 + (_counter / 8) % 4], TRUE);
		break;
	case 2:
		DrawRotaGraphF(_x, _y, 0.9f, _baseAngle, Image::getIns()->getUFOEnemy()[8 + (_counter / 8) % 4], TRUE);
		break;
	case 3:
		DrawRotaGraphF(_x, _y, 0.9f, _baseAngle, Image::getIns()->getUFOEnemy()[12 + (_counter / 8) % 4], TRUE);
		break;
	default:
		break;
	}
	if ((_counter - 8) % 96 < 48) {
		_baseAngle = _baseAngle - Define::PI / 384;
	}
	else
	{
		_baseAngle = _baseAngle + Define::PI / 384;
	}
}

void UFOEnemy::setSize()
{
	int handle = Image::getIns()->getEnemyNormal()[0];
	GetGraphSize(handle, &_width, &_height);
}
