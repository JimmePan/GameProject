#pragma once
#include "Task.h"

class Player : public Task
{
public:
	Player();
	virtual ~Player() = default;
	bool update() override;
	void draw() const override;

	static float getX() { return pl_x; }
	//void  setX(float x) { _x = x; }
	static float getY() { return pl_y; }
	//void  setY(float y) { _y = y; }
	static bool getPowerMax() { return _powerMax; }
	void  setPowerMax(bool max) { _powerMax = max; }

	float getRange() { return _range; }
	float getBomRange() { return _bomRange; }
	int getFlag() { return _flag; }
	void setFlag(int flag) { _flag = flag; }
	bool getBomFlag() { return _bomFlag; }
	void setBomFlag(bool bomFlag) { _bomFlag = bomFlag; }
	int getCount() { return _counter; }
	void setCount_0() { _counter = 0; }
	int getMutekicnt() { return _mutekicnt; }
	void setMutekicnt(int mutekicnt) { _mutekicnt = mutekicnt; }
	bool getSlow() { return _slow; }
	//void setSlow(bool slow) { _slow = slow; }

private:

	void move();
	void shot();
	void boom();

	float _x, _y;
	float _range;
	static float pl_x, pl_y;		//为获取自机位置的权宜之计
	float _bomRange;
	static bool _powerMax;		//满火力标示

	int _counter;//帧计数器
	int _slowRange = 100;	//低速时，子弹绕行半径

	//mutable int _change;//方向判定
	mutable int _mutekicnt;		//无敌状态
	mutable int _flag;		//0：普通状态 1：正在进行决死处理 2：已经被击毁且新的自机正在从下浮起来	3:无敌状态
	mutable bool _bomFlag;	//0.未boom 1.boom中
	mutable bool _slow; //慢速判定
	mutable int _direction; //方向
	mutable int _changeCount; //方向改变计数器
	mutable int _shotCount = 5;	//射击计数器
};

