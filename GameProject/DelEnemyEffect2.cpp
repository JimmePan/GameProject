#include "DelEnemyEffect2.h"
#include "Image.h"
#include "Define.h"
#include <DxLib.h>

DelEnemyEffect2::DelEnemyEffect2(float x, float y, int color)
{
	_flag = 1;
	_x = x;
	_y = y;
	_r = 0.f;
	_color = color;
	_brightness = 180;
	_count = 0;
	_angle = 0;
	_eff = 1;
	switch (_color)
	{
	case 0:case 8:
		_img = Image::getIns()->getEnemyDelEffect2()[1];
		break;
	case 1:case 9:
		_img = Image::getIns()->getEnemyDelEffect2()[0];
		break;
	case 2:case 10:
		_img = Image::getIns()->getEnemyDelEffect2()[3];
		break;
	case 3:case 11:
		_img = Image::getIns()->getEnemyDelEffect2()[2];
		break;
	default:
		break;
	}
	_kind = 0; //消灭敌人特效

}

bool DelEnemyEffect2::update()
{
	_count++;
	_r += 0.2f;//逐渐把效果的大小变大
	if (_count > 10)//如果计数为10以上
		_brightness -= 10;//将亮度降低
	if (_count > 20) {//效果为20以上
		_flag = 0;	//销毁之
		return false;
	}
	return true;
}

void DelEnemyEffect2::draw() const
{
	DrawRotaGraphF(_x, _y, _r, _angle, _img, TRUE);
}


