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
	int _counter;//֡������
	

	//mutable int _change;//�����ж�
	mutable bool _slow; //����
	mutable int _direction; //����
	mutable int _changeCount; //����ı������
	mutable int _shotCount = 5;	//���������
	//int _image;
};

