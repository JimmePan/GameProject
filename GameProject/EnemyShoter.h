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
	float _groupAngle00;	//组形自机狙，暂用角度
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

	/*interval 自机狙间隔角度，num自机狙个数*/
	void shotPlayerBullet(float x, float y, unsigned int type, unsigned int color, int state, float angle,
		float speed, float rate, float interval, int num);//单种类单颜色的自机相关狙，状态码为-1，不会发生变化，子弹方向即射击方向
};

