#include "BoomEffect01.h"
#include "Define.h"
#include "Image.h"
#include <DxLib.h>
#include "Player.h"
BoomEffect01::BoomEffect01()
{
	_flag = 1;
	_r = 1.5f;
	_brightness = 225;
	_img = Image::getIns()->getPl00BoomA();
	_count = 0;
	_color = 0;
	_angle = -Define::PI/2;
	_eff = 2;
	_imgCount = 0;
}

bool BoomEffect01::update()
{
	_x = Player::getX() ;
	_y = Player::getY() -6*_r;
	
	//_angle += Define::PI / 64;
	if (_count / 30 % 2 > 0) {
		if (_angle>-Define::PI / 2)
		_angle -= Define::PI / 16;
	}
	else
	{
		if(_angle<Define::PI / 2)
		_angle += Define::PI / 16;		
	}
	if (_count > 2400) {
		_flag = 0;	//Ïú»ÙÖ®
		return false;
	}
	else
	{
		_count++;
	}
	return true;
}

void BoomEffect01::draw() const
{
	DrawRotaGraph2F(_x, _y,122,174, _r, _angle, _img, TRUE);
	
}
