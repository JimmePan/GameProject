#pragma once
#include "Task.h"
#include <memory>
#include <list>
class PlayerShot:public Task
{
public:
	PlayerShot(float x, float y, int kind);		//是否以kind为标示待定
	virtual ~PlayerShot() =default;
	bool update() override;		//更新位置信息
	void draw() const override; //画
	int getFlag() const{ return _flag; }
	void setFlag(int flag) { _flag = flag; }
	int getPower() const { return _power; }
	void setPower(int power) { _power = power; }
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
	int getRange() const { return _RANGE; }
	//void  setRange(float range) { _RANGE = range; }
protected:
	mutable int _flag;		//存在
	int _type;		//机型？
	int _count;		//子弹移动计数
	int _power;		//威力
	int _kind;		//弹种
	float _x, _y, _angle, _speed;//参数

	const int _RANGE;

	bool isInside() const;		//判断出界
private:
	int get(unsigned int type)const;
	
};

