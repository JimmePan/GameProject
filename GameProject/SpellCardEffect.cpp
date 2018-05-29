#include "SpellCardEffect.h"
#include "Image.h"
#include "Define.h"
#include <DxLib.h>

SpellCardEffect::SpellCardEffect(int type)
{
	_flag = 1;
	_x = (float)Define::OUT_W;
	_y = 0.f;
	_r = 1.3f;
	_brightness = 40;
	_count = 0;
	_angle = 0.f;
	_eff = 1;
	switch (type)
	{
	case 0:
		_img = Image::getIns()->getEn1Face0();
		break;
	case 1:
		_img = Image::getIns()->getEn2Face0();
		break;
	default:
		break;
	}
	_kind = 0; //消灭敌人特效
}

bool SpellCardEffect::update()
{
	_count++;

	if (_count < 32) {
		_brightness += 6;
		_x = _x - 14.f;
		_y = _y + 14.f;
		return true;
	}
	if (_count >= 32 && _count < 92) {
		_x = _x - 2.f;
		_y = _y + 2.f;
		return true;
	}
	if (_count >= 92) {
		_x = _x - 18.f;
		_y = _y + 18.f;
		_brightness -= 6;
	}
	if (_count > 120) {
		_flag = 0;	//销毁之
		return false;
	}
	return true;
}

void SpellCardEffect::draw() const
{
	DrawRotaGraphF(_x, _y, _r, _angle, _img, TRUE);

}


