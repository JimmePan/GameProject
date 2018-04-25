#include "BulletShotEffect.h"
#include <DxLib.h>
#include "Image.h"

BulletShotEffect::BulletShotEffect(float x, float y, int color)
{
	_flag = 1;
	_x = x;
	_y = y;
	_r = 2.5f;
	_color = color;
	_brightness = 100;
	_count = 0;
	_angle = 0.0f;
	_eff = 1;
}
bool BulletShotEffect::update()
{
	_count++;
	_r -= 0.08f;
	if (_count > 24) {
		_flag = 0;	
		return false;
	}
	if (_count < 12)//
		_brightness += 8;//½«ÁÁ¶È½µµÍ
	else
	{
		_brightness += 4;
	}
	return true;
}

void BulletShotEffect::draw() const
{
	DrawRotaGraphF(_x, _y, _r, _angle, Image::getIns()->getBulletShotEffect()[_color], TRUE);

}