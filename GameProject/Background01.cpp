#include "Background01.h"
#include "Define.h"
#include "Image.h"
#include <DxLib.h>
#include <iostream>

using namespace std;

const static int START_N = -1;
const static int END_N = 7;

Background01::Background01()
{
	_handle[0] = Image::getIns()->getFusuma();
	_handle[1] = Image::getIns()->getFloor();
	_handle[2] = _handle[0];
	_handle[3] = 0;
	for (int t = 0; t < Surface::DATANUM; t++) {
		for (int z = START_N; z < END_N; z++) {
			_list.push_back(make_shared<Surface>(z, _handle[t], t));
		}
	}
	{
		SetCameraNearFar(1.0f, 10000.f);		//设置相机
		SetCameraScreenCenter(Define::OUT_W / 2.f, Define::OUT_H / 2.f);
		SetCameraPositionAndTarget_UpVecY(VGet(0.0f, 0.0f, -100.0f), VGet(0.0f, 0.0f, 0.0f));
		SetFogEnable(TRUE);
		SetFogColor(0, 0, 0);
		SetFogStartEnd(0.0f, 300.0f);
	}
	{
		MATERIALPARAM Material;
		Material.Diffuse = GetColorF(0.0f, 0.0f, 0.0f, 1.0f);
		Material.Specular = GetColorF(0.0f, 0.0f, 0.0f, 0.0f);
		Material.Ambient = GetColorF(1.0f, 1.0f, 1.0f, 1.0f);
		Material.Emissive = GetColorF(1.0f, 1.0f, 1.0f, 0.0f);
		Material.Power = 20.0f;
		SetMaterialParam(Material);
		SetMaterialUseVertSpcColor(FALSE);
		SetMaterialUseVertDifColor(FALSE);
	}
}

bool Background01::update()
{
	for (auto srf : _list) {
		srf->update();
		if (srf->getZ() < srf->getZWid()*(START_N - 1)) {
			srf->addZ((END_N - START_N) * srf->getZWid());
		}
	}
	/*if (a > 20) {
		a--;
	}
	else if(a >= -1)
	{
		a++;
	}*/
	return true;
}

void Background01::draw() const
{
	VECTOR offset;//画面抖动？
	offset.x = a;
	offset.y = b;
	offset.z = c;
	//offset.x = a;
	//offset.y = b;
	//offset.z = c;
	//if(offset.x>10){
	//	a --;
	//	b --;
	//	c --;
	//}
	//else if(offset.x<=1)
	//{
	//	a++;
	//	b++;
	//	c++;
	//}
	draw(offset);
}

void Background01::draw(VECTOR offset) const
{
	SetDrawMode(DX_DRAWMODE_BILINEAR);
	for (auto srf : _list) {
		srf->draw(offset);
	}
	SetDrawMode(DX_DRAWMODE_NEAREST);
}