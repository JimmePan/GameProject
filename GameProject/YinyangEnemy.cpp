#include "YinyangEnemy.h"
#include <DxLib.h>
#include "Image.h"
#include "CalcUtils.h"


YinyangEnemy::YinyangEnemy(float x, float y, int type, int hp, int movePatternID, int shotPatternID, int itemPatternID)
	:AbstractEnemy(x, y, type, hp, movePatternID, shotPatternID, itemPatternID)
{
	_RANGE = 20;
}

void YinyangEnemy::draw() const
{
	switch (_type)
	{
	case 0:
		DrawRotaGraphF(_x, _y, 1.0f, -Define::PI * 2 / 120 * _counter, Image::getIns()->getEnemyNormal()[96], TRUE);
		for (int i = 0; i < 5; i++) {
			DrawRotaGraphF(_x + 20.f * cos(2 * Define::PI / 60 * (_counter % 120) + Define::PI * 2 / 5 * i),
				_y + 20.f * sin(2 * Define::PI / 60 * (_counter % 120) + Define::PI * 2 / 5 * i),
				0.3, -Define::PI * 2 / 120 * _counter, Image::getIns()->getBulletShotEffect()[3], TRUE);
		}
		for (int i = 0; i < 5; i++) {
			DrawRotaGraphF(_x + 35.f * cos(2 * -Define::PI / 60 * (_counter % 180) + Define::PI * 2 / 5 * i),
				_y + 35.f * sin(2 * -Define::PI / 60 * (_counter % 180) + Define::PI * 2 / 5 * i),
				0.5, -Define::PI * 2 / 120 * _counter, Image::getIns()->getBulletShotEffect()[3], TRUE);
		}
		break;
	case 1:
		DrawRotaGraphF(_x, _y, 1.5f, Define::PI * 2 / 30 * _counter, Image::getIns()->getEnemyNormal()[97], TRUE);
		break;
	case 2:
		DrawRotaGraphF(_x, _y, 1.0f, Define::PI * 2 / 30 * _counter, Image::getIns()->getEnemyNormal()[98], TRUE);
		for (int i = 0; i < 5; i++) {
			DrawRotaGraphF(_x + 20.f * cos(2 * Define::PI / 60 * (_counter % 120) + Define::PI * 2 / 5 * i),
				_y + 20.f * sin(2 * Define::PI / 60 * (_counter % 120) + Define::PI * 2 / 5 * i),
				0.3, -Define::PI * 2 / 120 * _counter, Image::getIns()->getBulletShotEffect()[0], TRUE);
		}
		for (int i = 0; i < 5; i++) {
			DrawRotaGraphF(_x + 32.f * cos(2 * -Define::PI / 60 * (_counter % 180) + Define::PI * 2 / 5 * i),
				_y + 32.f * sin(2 * -Define::PI / 60 * (_counter % 180) + Define::PI * 2 / 5 * i),
				0.5, -Define::PI * 2 / 120 * _counter, Image::getIns()->getBulletShotEffect()[0], TRUE);
		}
		break;
	case 3:
		DrawRotaGraphF(_x, _y, 1.5f, Define::PI * 2 / 30 * _counter, Image::getIns()->getEnemyNormal()[99], TRUE);
		break;
	default:
		break;
	}
}


void YinyangEnemy::setSize()
{
	int handle = Image::getIns()->getEnemyNormal()[0];
	GetGraphSize(handle, &_width, &_height);
}

