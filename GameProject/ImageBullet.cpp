#include "ImageBullet.h"
#include "Macro.h"
#include <DxLib.h>


const float WEIGHT = 0.71f;//范围判定基准值
const float ImageBullet::RANGE[] = {
	5.5f * WEIGHT,//Small
	4.0f * WEIGHT,//Barrier
	4.5f * WEIGHT,//SparkSmall	//改
	5.0f * WEIGHT,//Kome
	44.f * WEIGHT,// 4.5f * WEIGHT,//Umaibo
	9.0f * WEIGHT,	//SparkBig
	12.0f * WEIGHT,	//Kodama	//原10.0f	//改
	6.5f * WEIGHT,	//Yosei
	9.0f * WEIGHT,	//Ring
	11.0f * WEIGHT,//Ame
	23.0f * WEIGHT,	//Tama	//原19.5 //改
	38.0f * WEIGHT,	//Odama
	220.f * WEIGHT,//2.8f * WEIGHT,//Laser
	22.f * WEIGHT,//10.0f * WEIGHT,//Ofuda
	5.0f * WEIGHT,//Star
	6.0f * WEIGHT,//Rain
	6.5f * WEIGHT,//Ice
	9.0f * WEIGHT,//Rainbow
};

//const int ImageBullet::SORT_Z[] =
//{
//	1,//Small
//	5,//Barrier
//	4,//SparkSmall
//	2,//Kome
//	7,//Umaibo
//	8,//SparkBig
//	12,//Kodama
//	10,//Yosei
//	12,//Ring
//	14,//Ame
//	15,//Tama
//	16,//Odama
//	3,//Laser
//	11,//Ofuda
//	5,//Star
//	6,//Rain
//	9,//Rainbow
//};

//未想出好的数据结构或者排序方法前不细分
const int ImageBullet::SORT_Z[] =
{
	1,//Small
	1,//Barrier
	1,//SparkSmall
	1,//Kome
	2,//Umaibo
	2,//SparkBig
	3,//Kodama
	2,//Yosei
	3,//Ring
	3,//Ame
	3,//Tama
	3,//Odama
	1,//Laser
	2,//Ofuda
	1,//Star
	2,//Rain
	1,//Ice
	2,//Rainbow
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
	_sizeList.push_back(new Size(32, 32));//16
	_sizeList.push_back(new Size(20, 20));//17
	myLoadDivGraph("E://dat/image/bullet/00.small.png");
	myLoadDivGraph("E://dat/image/bullet/01.barrier.png");
	myLoadDivGraph("E://dat/image/bullet/02.sparkSmall.png");
	myLoadDivGraph("E://dat/image/bullet/03.kome.png");
	myLoadDivGraph("E://dat/image/bullet/04.umaibo.png");
	myLoadDivGraph("E://dat/image/bullet/05.sparkBig.png");
	myLoadDivGraph("E://dat/image/bullet/06.kodama.png");
	myLoadDivGraph("E://dat/image/bullet/07.yosei.png");
	myLoadDivGraph("E://dat/image/bullet/08.ring.png");
	myLoadDivGraph("E://dat/image/bullet/09.ame.png");
	myLoadDivGraph("E://dat/image/bullet/10.tama.png");
	myLoadDivGraph("E://dat/image/bullet/11.odama.png");
	myLoadDivGraph("E://dat/image/bullet/12.laser.png");
	myLoadDivGraph("E://dat/image/bullet/13.ofuda.png");
	myLoadDivGraph("E://dat/image/bullet/14.star.png");
	myLoadDivGraph("E://dat/image/bullet/15.rain.png");
	myLoadDivGraph("E://dat/image/bullet/16.ice.png");
	myLoadDivGraph("E://dat/image/bullet/17.rainbow.png");
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

