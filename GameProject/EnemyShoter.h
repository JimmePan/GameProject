#pragma once

#include <vector>
#include <memory>

class AbstractEnemy;

class EnemyShoter
{
public:
	EnemyShoter();
	virtual ~EnemyShoter() = default;
	void shot(AbstractEnemy* enemy);
private:
	float _groupAngle00;	//�����Ի��ѣ����ýǶ�
	float _groupAngle01;


	typedef void(EnemyShoter::*FUNC)(AbstractEnemy* enemy);
	std::vector<FUNC> _shotPattern;
	void setFunction();

	void shotPattern00(AbstractEnemy *enemy);
	void shotPattern01(AbstractEnemy *enemy);
	void shotPattern02(AbstractEnemy *enemy);
	void shotPattern03(AbstractEnemy *enemy);
	void shotPattern04(AbstractEnemy *enemy);
	void shotPattern05(AbstractEnemy *enemy);
	void shotPattern06(AbstractEnemy *enemy);
	void shotPattern07(AbstractEnemy *enemy);
	void shotPattern08(AbstractEnemy *enemy);
	void shotPattern09(AbstractEnemy *enemy);
	void shotPattern10(AbstractEnemy *enemy);
	void shotPattern11(AbstractEnemy *enemy);
	void shotPattern12(AbstractEnemy *enemy);
	void shotPattern13(AbstractEnemy *enemy);
	void shotPattern14(AbstractEnemy *enemy);
	void shotPattern15(AbstractEnemy *enemy);

	/*interval �Ի��Ѽ���Ƕȣ�num�Ի��Ѹ���*/
	void shotPlayerBullet(float x, float y, unsigned int type, unsigned int color, int state, float angle,
		float speed, float rate, float interval, int num);//�����൥��ɫ���Ի���ؾѣ�״̬��Ϊ-1�����ᷢ���仯���ӵ������������
};

