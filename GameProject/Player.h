#pragma once
#include "Task.h"

class Player: public Task
{
public:
	Player();
	virtual ~Player() = default;
	bool update() override;
	void draw() const override;
	
	float _power;
	float getPower() const{
		return _power;
	}

private:
	
	void move();
	void shot();

	float _x, _y;
	int _counter;//帧计数器
	

	//mutable int _change;//方向判定
	mutable bool _slow; //方向
	mutable int _direction; //方向
	mutable int _changeCount; //方向改变计数器
	mutable int _shotCount = 5;	//射击计数器
	//int _image;
};

