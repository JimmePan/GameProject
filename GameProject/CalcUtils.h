#pragma once
#include "BulletManager.h"
#include <DxLib.h>
#include "ItemManger.h"
#include "Define.h"
#include "Global.h"
#include "ItemManger.h"
#include "Bullet.h"
#include "Vector.h"
#include "Point.h"
#include "EffectManager.h"
#include "Sound.h"

using namespace std;
class CalcUtils
{
public:
	CalcUtils() = delete;

	static float roundPoint(float val, int point);
	static float roundSize(float max, float min, int count);
	/*自机死亡消弹*/
	static void ClearBullet();
	/*boss死亡消弹*/
	static void ClearBulletEn();
	/*自机死亡掉落*/
	static void PlayFall();
	/*根据矩形中心点以及于x轴形成的夹角获得矩形顶点位置*/
	static Point getApex(std::list<std::shared_ptr<Bullet>>::iterator & b, int i);
	/*点到线段的距离*/
	static float distanceLine(Point a, Point b, Point p);
	/*点到矩形顶点的最短距*/
	static float getMinDis(float a, float b, float c, float d);
	/*圆与矩形的相交判定*/
	static bool out_judge_shot_re(std::list<std::shared_ptr<Bullet>>::iterator & b, std::shared_ptr<Player> & p);
	/*圆与圆的相交判定*/
	template<typename T1, typename T2>
	static bool out_judge_shot(T1 i, T2 s);
};

template<typename T1, typename T2>
inline bool CalcUtils::out_judge_shot(T1 i, T2 s)
{
	{

		int j;

		if ((*i)->getCount() > 0) { //子弹已经射出，即已经产生轨迹
			float x = (*i)->getX() - (*s)->getX();		//敌人和自机子弹距离
			float y = (*i)->getY() - (*s)->getY();

			float r = (*i)->getRange() + (*s)->getRange();	//敌人的碰撞判定和自机射击的子弹的碰撞判定的合计范围

			if ((*i)->getSpeed() > r) {		//半径小于速度，计算轨迹
											//1帧前的位置
				float pre_x = (*i)->getX() + cos((*i)->getAngle() + Define::PI)*(*i)->getSpeed();
				float pre_y = (*i)->getY() + sin((*i)->getAngle() + Define::PI)*(*i)->getSpeed();
				float px, py;
				for (j = 0; j < (*i)->getSpeed() / r; j++) {			//前进的分量/碰撞判定分量次循环
					px = pre_x - (*s)->getX();
					py = pre_y - (*s)->getY();
					if (px*px + py * py < r*r)
						return true;
					pre_x += cos((*i)->getAngle())*r;
					pre_y += sin((*i)->getAngle())*r;
				}
			}
			if (x * x + y * y < r * r)//如果在碰撞判定范围内
				return true;//碰撞

			if (x*x + y * y - r * r < 1296 && (*i)->getGraze()) {		//擦弹
				Global::GRAZE++;
				(*i)->setGraze();
				EffectManager::addGrazeEffect((*s)->getX(), (*s)->getY());//擦弹特效
				if (!CheckSoundMem(Sound::getIns()->getGraze()))
					PlaySoundMem(Sound::getIns()->getGraze(), DX_PLAYTYPE_BACK);//擦弹音效
			}
		}
		return false;
	}
}
