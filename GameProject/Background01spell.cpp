#include "Background01spell.h"
#include "image.h"
#include "Define.h"
#include<Dxlib.h>

using namespace std;

const static int IMG_HEIGHT = 256;
const static float SCROLL_SPEED = 2.f;
/*
小型背景素材，宽度拉伸，对称分布
*/
Background01spell::Background01spell()
{
	_list[0] = make_shared<Quadrangle>(0, IMG_HEIGHT * 0, Image::getIns()->getBackSpell00());
	_list[1] = make_shared<Quadrangle>(0, IMG_HEIGHT * 1, Image::getIns()->getBackSpell01());
	_list[2] = make_shared<Quadrangle>(0, IMG_HEIGHT * 2, Image::getIns()->getBackSpell00());
	_list[3] = make_shared<Quadrangle>(0, IMG_HEIGHT * 3, Image::getIns()->getBackSpell01());
	_list[4] = make_shared<Quadrangle>(0, IMG_HEIGHT * 4, Image::getIns()->getBackSpell01());
}

bool Background01spell::update()
{
	for (int i = 0; i < NUM; i++) { //向上滚动
		_list[i]->y -= SCROLL_SPEED;
		if (_list[i]->y < -IMG_HEIGHT) {
			_list[i]->y += IMG_HEIGHT * 5;
		}
	}
	return true;
}
/*
小型背景素材，宽度拉伸，对称分布
*/
void Background01spell::draw() const
{
	SetDrawArea(0, 0, Define::OUT_W, Define::OUT_H);
	for (int i = 0; i < NUM; i++) {
		DrawExtendGraphF(_list[i]->x, _list[i]->y + IMG_HEIGHT, (float)Define::OUT_W / 2, _list[i]->y, _list[i]->img, FALSE);
		DrawExtendGraphF(Define::OUT_W, _list[i]->y + IMG_HEIGHT, (float)Define::OUT_W / 2, _list[i]->y, _list[i]->img, FALSE);

	}
	SetDrawArea(0, 0, Define::WIN_W, Define::WIN_H);
}



