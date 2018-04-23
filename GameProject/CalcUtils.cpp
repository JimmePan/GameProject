#include "CalcUtils.h"
#include <cmath>


using namespace std;
/*
@brief 小数点后point位四舍五入，原为（+point-1）保留疑问
*/
float CalcUtils::roundPoint(float val, int point)
{
	float temp;
	temp = val * pow(10.f, +point);
	temp = (int)(temp + 0.5f);
	temp = temp * pow(10.f, -point);
	return temp;

}

float CalcUtils::roundSize(float max, float min, int count)
{
	if (count / 60 % 2 > 0) {
		return max - count % 60 * ((max - min) / 60);
	}
	else {
		return min + count % 60 * ((max - min) / 60);
	}

}

void CalcUtils::ClearBullet()
{
	for (auto i = BulletManager::getListSmall()->begin(); i != BulletManager::getListSmall()->end();) {
		if ((*i)->getFlag() > 0) {
			(*i)->setFlag(0);
		}
		i++;
	}
	for (auto i = BulletManager::getListNormal()->begin(); i != BulletManager::getListNormal()->end();) {
		if ((*i)->getFlag() > 0) {
			(*i)->setFlag(0);
		}
		i++;
	}
	for (auto i = BulletManager::getListBig()->begin(); i != BulletManager::getListBig()->end();) {
		if ((*i)->getFlag() > 0) {
			(*i)->setFlag(0);
		}
		i++;
	}
}

void CalcUtils::ClearBulletEn()
{
	for (auto i = BulletManager::getListSmall()->begin(); i != BulletManager::getListSmall()->end();) {
		if ((*i)->getFlag() > 0) {
			(*i)->setFlag(0);
			ItemManger::add((*i)->getX(), (*i)->getY(), -Define::PI / 2, 7);
		}
		i++;
	}
	for (auto i = BulletManager::getListNormal()->begin(); i != BulletManager::getListNormal()->end();) {
		if ((*i)->getFlag() > 0) {
			(*i)->setFlag(0);
			ItemManger::add((*i)->getX(), (*i)->getY(), -Define::PI / 2, 7);
		}
		i++;
	}
	for (auto i = BulletManager::getListBig()->begin(); i != BulletManager::getListBig()->end();) {
		if ((*i)->getFlag() > 0) {
			(*i)->setFlag(0);
			ItemManger::add((*i)->getX(), (*i)->getY(), -Define::PI / 2, 7);
		}
		i++;
	}
}

void CalcUtils::PlayFall()
{
	for (int i = 0; i < 5; i++) {
		int j = 3;
		float angle = 5 * Define::PI / 4 + i * Define::PI / 8;
		if (i == 0 || i == 4) {
			j = 0;
		}
		ItemManger::add((float)Define::CENTER_X + cos(angle) * 70, (float)Define::OUT_H*0.8f + sin(angle) * 60, angle, j);
	}
}

Point CalcUtils::getApex(std::list<std::shared_ptr<Bullet>>::iterator & b, int i)
{
	float height, width;
	if (i <= 3 && i >= 0) {
		switch ((*b)->getType())
		{
		case 4:
			height = 22.f;
			width = 6.f;
			break;
		case 12:
			height = 140.f;
			width = 7.f;
			break;
		case 13:
			height = 15.f;
			width = 15.f;
			break;
		default:
			//报告错误信息
			return Point(0.f, 0.f);
			break;
		}
	}
	else
	{
		//报告错误信息
		return Point(0.f, 0.f);
	}
	float rate = (*b)->getRate();

	float h = height * rate / 2;
	if (i > 1) {
		h = -h;
	}

	float w = width * rate / 2;
	if (i % 2 != 0) {
		w = -w;
	}
	float a = (*b)->getBaseAngle();
	float x = (*b)->getX();
	float y = (*b)->getY();
	return Point(h * cos(a) - w * sin(a) + x, h * sin(a) + w * cos(a) + y);
}

float CalcUtils::distanceLine(Point a, Point b, Point p)
{
	double ap_ab = (b.x - a.x)*(p.x - a.x) + (b.y - a.y)*(p.y - a.y);//cross( a , p , b );  
	if (ap_ab <= 0)
		return sqrt((p.x - a.x)*(p.x - a.x) + (p.y - a.y)*(p.y - a.y));

	double d2 = (b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y);
	if (ap_ab >= d2) return sqrt((p.x - b.x)*(p.x - b.x) + (p.y - b.y)*(p.y - b.y));

	double r = ap_ab / d2;
	double px = a.x + (b.x - a.x) *r;
	double py = a.y + (b.y - a.y) *r;
	return (float)sqrt((p.x - px)*(p.x - px) + (p.y - py)*(p.y - py));
}

float CalcUtils::getMinDis(float a, float b, float c, float d)
{
	float u = a;
	if (u >= b) {
		u = b;
	}
	if (u >= c) {
		u = c;
	}
	if (u >= d) {
		u = d;
	}
	return u;
}

bool CalcUtils::out_judge_shot_re(std::list<std::shared_ptr<Bullet>>::iterator & i, std::shared_ptr<Player>& p)
{
	Point a = getApex(i, 0);	//(+,-)
	Point b = getApex(i, 1);	//(+,+)
	Point c = getApex(i, 2);	//(-,-)
	Point d = getApex(i, 3);	//(-,+)
	Point r = Point((*i)->getX(), (*i)->getY());	//矩形中心
	Point pl = Point(p->getX(), p->getY());	//圆形中心
	Vector v = r.getVec(pl);		//向量cp
	float u = getMinDis(distanceLine(a, b, pl), distanceLine(b, d, pl),
		distanceLine(d, c, pl), distanceLine(c, a, pl));	//圆点到矩形的距离
	Point h = a;
	if (pl.distance(b) < pl.distance(a))
		h = b;
	if (pl.distance(c) < pl.distance(b))
		h = c;
	if (pl.distance(d) < pl.distance(c))
		h = d;
	Vector vh = v - r.getVec(h);
	v.absV();
	vh.absV();
	if (vh.getX() < 0 && vh.getY() < 0)		//圆心在矩形内
		return true;
	if (u <= p->getRange())		//距离小于判定
		return true;
	if (u < 24 && (*i)->getCount()%5 == 0) {		//擦弹
		Global::GRAZE++;
		EffectManager::addGrazeEffect(p->getX(), p->getY());//擦弹特效
		if (!CheckSoundMem(Sound::getIns()->getGraze()))
			PlaySoundMem(Sound::getIns()->getGraze(), DX_PLAYTYPE_BACK);//擦弹音效
	}
	return false;
}
