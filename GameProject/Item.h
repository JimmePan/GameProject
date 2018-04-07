#pragma once
#include "Task.h"
#include "Player.h"
#include <memory>
#include <list>
class Item :public Task
{
public:
	Item(float x, float y, float angle, int kind);		//angle 初始移动方向
	virtual ~Item() = default;
	bool update() override;		//更新位置信息
	void draw() const override; //画
	int getFlag() const { return _flag; }
	void setFlag(int flag) { _flag = flag; }
	int getCount() const { return _count; }
	//void setCount(int count) { _count = count; }
	int getKind() const { return _kind; }
	//void setKind(int kind) { _kind = kind; }

	float getX() const { return _x; }
	//void  setX(float x) { _x = x; }
	float getY() const { return _y; }
	//void  setY(float y) { _y = y; }
	float getSpeed() const { return _speed; }
	//void  setSpeed(float speed) { _speed = speed; }
	float getAngle() const { return _angle; }
	//void  setAngle(float angle) { _angle = angle; }
	float getRange() const { return _RANGE; }
	//void  setRange(float range) { _RANGE = range; }

protected:
	mutable int _flag;		//存在
	int _count;		//子弹移动计数
	int _kind;		//弹种
	float _x, _y, _angle, _speed;//参数

	const float _RANGE;

	bool isInside() const;		//判断出界
private:
	int get(unsigned int type)const;
	float shotatan2() { return atan2(Player::getY() - _y, Player::getX() - _x); }		//向自机方向移动（权宜之计）

};

