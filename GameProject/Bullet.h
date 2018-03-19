#pragma once
#include "Task.h"

class Bullet : public Task
{
public:
	Bullet(float x, float y, unsigned int type, unsigned int color, int eff, float angle, float base_angle, float speed, float rate);
	//弹幕类构造方法可能会根据eff的情况而出现多个
	virtual ~Bullet() = default;
	bool update() override;
	void draw() const override;

	bool isInside() const;

	mutable int _flag;

	int getFlag() const { return _flag; }
	void setFlag(int flag) { _flag = flag; }
	float getX() const { return _x; }
	void  setX(float x) { _x = x; }
	float getY() const { return _y; }
	void  setY(float y) { _y = y; }
	int getSort() { return _sort; }
	void setSort(int sort) { _sort = sort; }
	int getType() { return _type; }
	void setType(int type) { _type = type; }	//子弹效果：更改子弹类型
	float getSpeed() { return _speed; }
	void setSpeed(float speed) { _speed = speed; }
	int getCount() { return _count; }
	void setCount(int count) { _count = count; }
	float getAngle() { return _angle; }
	void setAngle(float angle) { _angle = angle; }
	float getRange() { return _range; }
	void setRange(float range) { _range = range; }


private:
	unsigned int _type;		//子弹类型
	unsigned int _color;	//子弹颜色
	int _count;
	int _eff;	//效果种类	0.匀速直线运动 1.经过一定时间停滞后朝某角度继续移动
	int _w;
	int _h;
	//int _till;	//保证不消失最短时间，如下雨弹幕会先抛射出屏幕上方再落下，因此需要最短不消失时间
	int _sort;		//弹幕显示顺序排序

	float _x;
	float _y;
	float _angle;
	float _speed;
	float _rate;
	float _range;

	float _base_angle[1];	//基本角度
	float _rem_spd[1];		//瞬间记忆速度
};

