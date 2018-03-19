#pragma once
#include "Task.h"

class Bullet : public Task
{
public:
	Bullet(float x, float y, unsigned int type, unsigned int color, int eff, float angle, float base_angle, float speed, float rate);
	//��Ļ�๹�췽�����ܻ����eff����������ֶ��
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
	void setType(int type) { _type = type; }	//�ӵ�Ч���������ӵ�����
	float getSpeed() { return _speed; }
	void setSpeed(float speed) { _speed = speed; }
	int getCount() { return _count; }
	void setCount(int count) { _count = count; }
	float getAngle() { return _angle; }
	void setAngle(float angle) { _angle = angle; }
	float getRange() { return _range; }
	void setRange(float range) { _range = range; }


private:
	unsigned int _type;		//�ӵ�����
	unsigned int _color;	//�ӵ���ɫ
	int _count;
	int _eff;	//Ч������	0.����ֱ���˶� 1.����һ��ʱ��ͣ�ͺ�ĳ�Ƕȼ����ƶ�
	int _w;
	int _h;
	//int _till;	//��֤����ʧ���ʱ�䣬�����굯Ļ�����������Ļ�Ϸ������£������Ҫ��̲���ʧʱ��
	int _sort;		//��Ļ��ʾ˳������

	float _x;
	float _y;
	float _angle;
	float _speed;
	float _rate;
	float _range;

	float _base_angle[1];	//�����Ƕ�
	float _rem_spd[1];		//˲������ٶ�
};

