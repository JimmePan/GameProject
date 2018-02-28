#pragma once

#include "Task.h"
#include "EnemyMover.h"
class AbstractEnemy : public Task
{
public:
	AbstractEnemy(float x, float y, int type, int hp);
	virtual ~AbstractEnemy() = default;
	void initialize();
	bool update() override;

	bool changeDirection() const; // 更改方向

	int getFlag() const { return _flag; }
	void setFlag(int flag) { _flag = flag; }
	float getX() const { return _x; }
	void  setX(float x) { _x = x; }
	float getY() const { return _y; }
	void  setY(float y) { _y = y; }
	int   getCounter() const { return _counter; }
	void  setSpeed(float speed) { _speed = speed; }
	float getSpeed() const { return _speed; }
	void  setAngle(float angle) { _angle = angle; _change = cos(angle) > 0.1 ? 1 : (cos(angle) < -0.1 ? -1 : 0);}
	float getAngle() const { return _angle; }
	float getRange() const { return _RANGE; }
	//void  setRange(float range) { _RANGE = range; }
	int getHp() { return _hp; }
	void setHp(int hp) { _hp -= hp; }	//直接更新血量
	int getType() { return _type; }
	void setType(int type) { _type = type; }

	int getMovePatternID() const { return _movePatternID; }


protected:
	virtual void setSize() = 0;
	bool isInside() const;

	EnemyMover _mover;

	mutable int _flag;
	float _x, _y;//坐标
	float _speed;//速度
	float _angle;//角度

	float _RANGE;	//判定范围
	int _hp;	//生命值

	int _counter;//帧计数器
	int _width;	//宽
	int _height;//高

	int _movePatternID;	//移动方式

	int _type;

	mutable int _direction; //方向
	mutable int _change;//方向判定
	mutable int _changeCount; //方向改变计数器
};

