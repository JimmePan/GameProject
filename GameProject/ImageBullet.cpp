#include "ImageBullet.h"
#include "Macro.h"
#include <DxLib.h>

const float WEIGHT = 0.71f;//范围判定基准值
const float RANGE[] = {
	5.5f * WEIGHT,//Small
	4.0f * WEIGHT,//Barrier
	4.0f * WEIGHT,//SparkSmall
	5.0f * WEIGHT,//Kome
	4.5f * WEIGHT,//Umaibo
	9.0f * WEIGHT,//SparkBig
	10.0f * WEIGHT,//Kodama	//实测12.0f
	6.5f * WEIGHT,//Yosei
	9.0f * WEIGHT,//Ring
	11.0f * WEIGHT,//Ame
	19.5f * WEIGHT,//Tama	//实测23.0f
	38.0f * WEIGHT,//Odama
	2.8f * WEIGHT,//Laser
	10.0f * WEIGHT,//Ofuda
	5.0f * WEIGHT,//Star
	6.0f * WEIGHT,//Rain
	9.0f * WEIGHT,//Rainbow
};

ImageBullet::ImageBullet()
{
	_sizeList.push_back(new Size(16, 16));//0
	_sizeList.push_back(new Size(28, 30));//1
	_sizeList.push_back(new Size(38, 38));//2
	_sizeList.push_back(new Size(18, 31));//3
	_sizeList.push_back(new Size(64, 64));//4
	_sizeList.push_back(new Size(76, 76));//5
	_sizeList.push_back(new Size(32, 32));//6
	_sizeList.push_back(new Size(54, 54));//7
	_sizeList.push_back(new Size(36, 36));//8
	_sizeList.push_back(new Size(30, 57));//9
	_sizeList.push_back(new Size(62, 62));//10
	_sizeList.push_back(new Size(108, 108));//11
	_sizeList.push_back(new Size(12, 240));//12
	_sizeList.push_back(new Size(28, 32));//13
	_sizeList.push_back(new Size(34, 34));//14
	_sizeList.push_back(new Size(20, 34));//15
	_sizeList.push_back(new Size(20, 20));//16
	myLoadDivGraph("../dat/image/bullet/00.small.png");
	myLoadDivGraph("../dat/image/bullet/01.barrier.png");
	myLoadDivGraph("../dat/image/bullet/02.sparkSmall.png");
	myLoadDivGraph("../dat/image/bullet/03.kome.png");
	myLoadDivGraph("../dat/image/bullet/04.umaibo.png");
	myLoadDivGraph("../dat/image/bullet/05.sparkBig.png");
	myLoadDivGraph("../dat/image/bullet/06.kodama.png");
	myLoadDivGraph("../dat/image/bullet/07.yosei.png");
	myLoadDivGraph("../dat/image/bullet/08.ring.png");
	myLoadDivGraph("../dat/image/bullet/09.ame.png");
	myLoadDivGraph("../dat/image/bullet/10.tama.png");
	myLoadDivGraph("../dat/image/bullet/11.odama.png");
	myLoadDivGraph("../dat/image/bullet/12.laser.png");
	myLoadDivGraph("../dat/image/bullet/13.ofuda.png");
	myLoadDivGraph("../dat/image/bullet/14.star.png");
	myLoadDivGraph("../dat/image/bullet/15.rain.png");
	myLoadDivGraph("../dat/image/bullet/16.rainbow.png");
}

void ImageBullet::myLoadDivGraph(const char * fname)
{
	int id = _list.size();
	Size* size = _sizeList[id];
	int *bullets = new int[eColorNum];
	LoadDivGraph(fname, eColorNum, eColorNum, 1, size->getWidth(), size->getHeight(), bullets);
	_list.push_back(bullets);
}

int ImageBullet::get(unsigned int type, unsigned int color) const
{
	if (eTypeNum <= type) {
		ERR("type不正确");
	}
	if (eColorNum <= color) {
		ERR("color不正确");
	}
	return _list[type][color];
}

const Size* ImageBullet::getSize(unsigned int type) const
{
	if (_sizeList.size() <= type) {
		ERR("type不正确");
	}
	return _sizeList[type];
}

