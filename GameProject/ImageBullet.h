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
		eSmall,
		eBarrier,
		eSparkSmall,
		eKome,
		eUmaibo,
		eSparkBig,
		eKodama,
		eYosei,
		eRing,
		eAme,
		eTama,
		eOdama,
		eLaser,
		eOfuda,
		eStar,
		eRain,
		eRainbow,
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
	const static float SORT_Z[];	//显示判定，小型弹幕判定在前，优先显示

	ImageBullet();
private:
	std::vector<int*>_list;
	std::vector<Size*>_sizeList;

	void load() {}
	void myLoadDivGraph(const char* fname);
	int get(unsigned int type, unsigned int color)const;
	const Size* getSize(unsigned int type)const;
};

