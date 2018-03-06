#pragma once
#include "Task.h"
#include <memory>
#include <list>
class PlayerShot:public Task
{
public:
	PlayerShot(float x, float y, int kind);		//�Ƿ���kindΪ��ʾ����
	virtual ~PlayerShot() =default;
	bool update() override;		//����λ����Ϣ
	void draw() const override; //��
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
	mutable int _flag;		//����
	int _type;		//���ͣ�
	int _count;		//�ӵ��ƶ�����
	int _power;		//����
	int _kind;		//����
	float _x, _y, _angle, _speed;//����

	const int _RANGE;

	bool isInside() const;		//�жϳ���
private:
	int get(unsigned int type)const;
	
};

