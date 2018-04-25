#include "BigEnemy.h"
#include <DxLib.h>
#include "Image.h"

BigEnemy::BigEnemy(float x, float y, int type, int hp, int movePatternID, int shotPatternID, int itemPatternID)
	:AbstractEnemy(x, y, type, hp, movePatternID, shotPatternID, itemPatternID)
{
	_movePatternID = 0;
	_shotPatternID = 0;
	_itemPatternID = 3;
	_RANGE = 45.f;
}


void BigEnemy::draw() const
{
	const static int imgID[6] = { 48,49,50,51,50,49 };
	const static int DimgID[6] = { 51,50,49,48,49,50 }; //逆向移动
	const static int CimgID[6] = { 38,39,46,47,46,39 };//非垂直线移动
	int add;
	int handle;

	if (_type) {
		const int THandle = Image::getIns()->getEnemyBig()[16];
		DrawRotaGraphF(_x, _y, 2.0, 0.0, THandle, TRUE);
	}

	if (changeDirection()) {
		add = 4;
		if (abs(_change) > 0) {  //中向左右
			handle = Image::getIns()->getEnemyBig()[add + imgID[(_changeCount / 8) % 4]];
		}
		else {		//左右向中
			handle = Image::getIns()->getEnemyBig()[add + DimgID[(_changeCount / 8) % 4]];
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
		if (_direction == 0) {
			handle = Image::getIns()->getEnemyBig()[add + imgID[(_counter / 8) % 6]];	//每8帧切换一次
		}
		else
		{
			handle = Image::getIns()->getEnemyBig()[CimgID[(_counter / 8) % 6]];	//每8帧切换一次
		}
		if (_direction < 0) {
			DrawRotaGraphF(_x, _y, 1.5, 0.0, handle, TRUE, TRUE);
		}
		else
		{

			DrawRotaGraphF(_x, _y, 1.5, 0.0, handle, TRUE);
		}
	}


}

void BigEnemy::setSize()
{
	int handle = Image::getIns()->getEnemyBig()[0];
	GetGraphSize(handle, &_width, &_height);
}