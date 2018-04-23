#include "NormalEnemy.h"
#include <DxLib.h>
#include "Image.h"
#include "CalcUtils.h"


NormalEnemy::NormalEnemy(float x, float y, int type, int hp) :AbstractEnemy(x, y, type, hp)
{
	_movePatternID = 1;
	_shotPatternID = 1;
	_itemPatternID = 1;
	_RANGE = 20;
}


void NormalEnemy::draw() const
{
	const static int imgID[6] = { 0,1,2,3,2,1 };
	const static int DimgID[6] = { 3,2,1,0,1,2 };
	int add;
	float size = 2.0;

	SetDrawBlendMode(DX_BLENDMODE_ADD, 100);	//设置亮度
	switch (_type)				//妖精背景
	{
	case 0:case 8:
		DrawRotaGraphF(_x, _y, CalcUtils::roundSize(1.0f, 2.5f, _counter), Define::PI * 2 / 90 * _counter, Image::getIns()->getEnemyNormal()[114], TRUE);
		break;
	case 1:case 9:
		DrawRotaGraphF(_x, _y, CalcUtils::roundSize(1.0f, 2.5f, _counter), Define::PI * 2 / 60 * _counter, Image::getIns()->getEnemyNormal()[112], TRUE);
		break;
	case 2:case 10:
		DrawRotaGraphF(_x, _y, CalcUtils::roundSize(1.0f, 2.5f, _counter), Define::PI * 2 / 60 * _counter, Image::getIns()->getEnemyNormal()[113], TRUE);
		break;
	case 3:case 11:
		DrawRotaGraphF(_x, _y, CalcUtils::roundSize(1.0f, 2.5f, _counter), Define::PI * 2 / 60 * _counter, Image::getIns()->getEnemyNormal()[115], TRUE);
		break;
	default:
		break;
	}
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);		//还原亮度

	if (changeDirection()) {
		add = 4;
		int handle;
		if (abs(_change) > 0) {  //中向左右
			handle = Image::getIns()->getEnemyNormal()[add + imgID[(_changeCount / 8) % 4] + _type * 16];
		}
		else {		//左右向中
			handle = Image::getIns()->getEnemyNormal()[add + DimgID[(_changeCount / 8) % 4] + _type * 16];
		}
		if ((_change < 0 || _direction < 0) && (_direction - _change >= -1)) {	//鏡像
			DrawRotaGraphF(_x, _y, 1.5, 0.0, handle, TRUE, TRUE);
		}
		else {																//正像
			DrawRotaGraphF(_x, _y, 1.5, 0.0, handle, TRUE);
		}

	}
	else
	{
		add = _direction != 0 ? 8 : 0;
		int i = add + imgID[(_counter / 8) % 6] + _type * 16;
		int a = 3;
		const int handle = Image::getIns()->getEnemyNormal()[add + imgID[(_counter / 8) % 6] + _type * 16];	//每8帧切换一次
		if (_direction < 0) {
			DrawRotaGraphF(_x, _y, 1.5, 0.0, handle, TRUE, TRUE);
		}
		else
		{

			DrawRotaGraphF(_x, _y, 1.5, 0.0, handle, TRUE);
		}
	}

}

void NormalEnemy::setSize()
{
	int handle = Image::getIns()->getEnemyNormal()[0];
	GetGraphSize(handle, &_width, &_height);
}

