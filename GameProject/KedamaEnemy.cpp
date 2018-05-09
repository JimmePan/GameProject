#include "KedamaEnemy.h"
#include <DxLib.h>
#include "Image.h"
#include "CalcUtils.h"


KedamaEnemy::KedamaEnemy(float x, float y, int type, int hp, int movePatternID, int shotPatternID, int itemPatternID)
	:AbstractEnemy(x, y, type, hp, movePatternID, shotPatternID, itemPatternID)
{
	_RANGE = 16;
}

void KedamaEnemy::draw() const
{
	switch (_type)
	{
	case 0:
		DrawRotaGraphF(_x, _y, 1.5f, 0.f, Image::getIns()->getEnemyNormal()[72 + (_counter / 8) % 8], TRUE);
		break;
	case 1:
		DrawRotaGraphF(_x, _y, 1.5f, 0.f, Image::getIns()->getEnemyNormal()[88 + (_counter / 8) % 8], TRUE);
		break;
	case 2:
		DrawRotaGraphF(_x, _y, 1.5f, 0.f, Image::getIns()->getEnemyNormal()[104 + (_counter / 8) % 8], TRUE);
		break;
	case 3:
		DrawRotaGraphF(_x, _y, 1.5f, 0.f, Image::getIns()->getEnemyNormal()[120 + (_counter / 8) % 8], TRUE);
		break;
	default:
		break;
	}
}


void KedamaEnemy::setSize()
{
	int handle = Image::getIns()->getEnemyNormal()[0];
	GetGraphSize(handle, &_width, &_height);
}

