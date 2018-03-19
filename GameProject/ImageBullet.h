#pragma once
#include "Singleton.h"
#include <vector>

class Size {
public:
	Size() :w(0), h(0) {}
	Size(int w, int h) :w(w), h(h) {}
	int getWidth() const { return w; }
	int getHeight() const { return h; }
private:
	int w, h;
};
class ImageBullet final:public Singleton<ImageBullet>
{
public:
	enum eBulletType {
		eSmall,		//圆
		eBarrier,	//椭圆
		eSparkSmall,	//圆
		eKome,		//椭圆
		eUmaibo,	//矩
		eSparkBig,	//圆
		eKodama,	//圆
		eYosei,	//圆
		eRing,	//圆
		eAme,	//椭圆
		eTama,	//圆
		eOdama,	//圆
		eLaser,	//矩形
		eOfuda,	//矩形
		eStar,	//未知
		eRain,	//未知
		eRainbow,	//未知
		eTypeNum,
	};
	enum eBulletColor {
		eBlue,
		ePurple,
		ePink,
		eOrange,
		eYellow,
		eGreen,
		eLime,
		eAqua,
		eColorNum,
	};
	const static float RANGE[];		//判定范围
	const static int SORT_Z[];	//显示判定，小型弹幕判定在前，优先显示

	ImageBullet();

	const Size* getSize(unsigned int type)const;		//原为private
	int get(unsigned int type, unsigned int color)const;	//原为private

	static int getSORT_Z(int type) { return SORT_Z[type]; }

private:
	std::vector<int*>_list;
	std::vector<Size*>_sizeList;
	void load() {}

	void myLoadDivGraph(const char* fname);
};

