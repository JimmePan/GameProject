#pragma once
#include "Task.h"
#include "Player.h"
#include <memory>
#include <list>
class Item :public Task
{
public:
	Item(float x, float y, float angle, int kind);		//angle ��ʼ�ƶ�����
	virtual ~Item() = default;
	bool update() override;		//����λ����Ϣ
	void draw() const override; //��
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
	mutable int _flag;		//����
	int _count;		//�ӵ��ƶ�����
	int _kind;		//����
	float _x, _y, _angle, _speed;//����

	const float _RANGE;

	bool isInside() const;		//�жϳ���
private:
	int get(unsigned int type)const;
	float shotatan2() { return atan2(Player::getY() - _y, Player::getX() - _x); }		//���Ի������ƶ���Ȩ��֮�ƣ�

};

