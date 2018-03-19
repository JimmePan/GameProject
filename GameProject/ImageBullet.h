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
		eSmall,		//Բ
		eBarrier,	//��Բ
		eSparkSmall,	//Բ
		eKome,		//��Բ
		eUmaibo,	//��
		eSparkBig,	//Բ
		eKodama,	//Բ
		eYosei,	//Բ
		eRing,	//Բ
		eAme,	//��Բ
		eTama,	//Բ
		eOdama,	//Բ
		eLaser,	//����
		eOfuda,	//����
		eStar,	//δ֪
		eRain,	//δ֪
		eRainbow,	//δ֪
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
	const static float RANGE[];		//�ж���Χ
	const static int SORT_Z[];	//��ʾ�ж���С�͵�Ļ�ж���ǰ��������ʾ

	ImageBullet();

	const Size* getSize(unsigned int type)const;		//ԭΪprivate
	int get(unsigned int type, unsigned int color)const;	//ԭΪprivate

	static int getSORT_Z(int type) { return SORT_Z[type]; }

private:
	std::vector<int*>_list;
	std::vector<Size*>_sizeList;
	void load() {}

	void myLoadDivGraph(const char* fname);
};

