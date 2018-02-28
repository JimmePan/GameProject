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

	bool changeDirection() const; // ���ķ���

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
	void setHp(int hp) { _hp -= hp; }	//ֱ�Ӹ���Ѫ��
	int getType() { return _type; }
	void setType(int type) { _type = type; }

	int getMovePatternID() const { return _movePatternID; }


protected:
	virtual void setSize() = 0;
	bool isInside() const;

	EnemyMover _mover;

	mutable int _flag;
	float _x, _y;//����
	float _speed;//�ٶ�
	float _angle;//�Ƕ�

	float _RANGE;	//�ж���Χ
	int _hp;	//����ֵ

	int _counter;//֡������
	int _width;	//��
	int _height;//��

	int _movePatternID;	//�ƶ���ʽ

	int _type;

	mutable int _direction; //����
	mutable int _change;//�����ж�
	mutable int _changeCount; //����ı������
};

