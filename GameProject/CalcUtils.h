#pragma once
class CalcUtils
{
public:
	CalcUtils() = delete;

	static float roundPoint(float val, int point);
	static float roundSize(float max, float min, int count);

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
			if (x*x + y * y < r*r)//如果在碰撞判定范围内
				return true;//碰撞
		}
		return false;
	}
}
