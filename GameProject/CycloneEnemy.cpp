#include "CycloneEnemy.h"
#include <DxLib.h>
#include "Image.h"
#include "CalcUtils.h"


CycloneEnemy::CycloneEnemy(float x, float y, int type, int hp, int movePatternID, int shotPatternID, int itemPatternID)
	:AbstractEnemy(x, y, type, hp, movePatternID, shotPatternID, itemPatternID)
{
	_RANGE = 20;
}

void CycloneEnemy::draw() const
{
	switch (_type)
	{
	case 0:
		DrawRotaGraphF(_x, _y, 1.5f, Define::PI * 2 / 30 * _counter, Image::getIns()->getEnemyNormal()[66], TRUE);
		break;
	case 1:
		DrawRotaGraphF(_x, _y, 1.5f, Define::PI * 2 / 30 * _counter, Image::getIns()->getEnemyNormal()[67], TRUE);
		break;
	case 2:
		DrawRotaGraphF(_x, _y, 1.5f, Define::PI * 2 / 30 * _counter, Image::getIns()->getEnemyNormal()[82], TRUE);
		break;
	case 3:
		DrawRotaGraphF(_x, _y, 1.5f, Define::PI * 2 / 30 * _counter, Image::getIns()->getEnemyNormal()[83], TRUE);
		break;
	default:
		break;
	}
}


void CycloneEnemy::setSize()
{
	int handle = Image::getIns()->getEnemyNormal()[0];
	GetGraphSize(handle, &_width, &_height);
}

