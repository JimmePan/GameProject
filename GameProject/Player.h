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
	static float pl_x, pl_y;		//Ϊ��ȡ�Ի�λ�õ�Ȩ��֮��
	float _bomRange;
	static bool _powerMax;		//��������ʾ

	int _counter;//֡������
	int _slowRange = 100;	//����ʱ���ӵ����а뾶

	//mutable int _change;//�����ж�
	mutable int _mutekicnt;		//�޵�״̬
	mutable int _flag;		//0����ͨ״̬ 1�����ڽ��о������� 2���Ѿ����������µ��Ի����ڴ��¸�����	3:�޵�״̬
	mutable bool _bomFlag;	//0.δboom 1.boom��
	mutable bool _slow; //�����ж�
	mutable int _direction; //����
	mutable int _changeCount; //����ı������
	mutable int _shotCount = 5;	//���������
};

