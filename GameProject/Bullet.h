#pragma once
#include "Task.h"
#include "ImageBullet.h"
#include "Player.h"

class Bullet : public Task
{
public:
	Bullet(float x, float y, unsigned int type, unsigned int color, int state, float angle, float base_angle, float speed, float rate);
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
	int getGraze() { return _graze; }
	void setGraze() { _graze = false; }
	int getType() { return _type; }
	void setType(int type) { _type = type; _range = ImageBullet::getIns()->RANGE[type] * _rate; }	//�ӵ�Ч���������ӵ�����
	int getColor() { return _color; }
	void setColor(int color) { _color = color; }	//������ɫ
	float getSpeed() { return _speed; }
	void setSpeed(float speed) { _speed = speed; }
	int getCount() { return _count; }
	void setCount(int count) { _count = count; }
	float getAngle() { return _angle; }
	void setAngle(float angle) { _angle = angle; }
	float getBaseAngle() { return _base_angle; }
	void setBaseAngle(float baseAngle) { _base_angle = baseAngle; }
	int getState() { return _state; }
	void setState(int state) { _state = state; }
	float getRate() { return _rate; }
	void setRate(float rate) { _rate = rate; }
	float getRange() { return _range; }
	void setRange(float range) { _range = range; }

	float shotatan2() const { return atan2(Player::getY() - _y, Player::getX() - _x); }		//�ӵ��Ի��ѷ������(Ȩ��֮��)

private:
	unsigned int _type;		//�ӵ�����
	unsigned int _color;	//�ӵ���ɫ
	int _count;
	int _state;	//��Ļ��ʾ��
	int _w;
	int _h;
	int _sort;		//��Ļ��ʾ˳������
	bool _graze;	//�����ж�

	const int _till = 5;	//��֤����ʧ���ʱ�䣬�����굯Ļ�����������Ļ�Ϸ������£������Ҫ��̲���ʧʱ��

	float _x;
	float _y;
	float _angle;
	float _speed;
	float _rate;
	float _range;
	float _base_angle;	//��ת�Ƕ�

	float _rem_spd[1];		//˲������ٶ�

	void bulletChange();
};

