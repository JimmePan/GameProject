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
	typedef void(EnemyShoter::*FUNC)(AbstractEnemy* enemy);
	std::vector<FUNC> _shotPattern;
	void setFunction();

	void shotPattern00(AbstractEnemy *enemy);
	void shotPattern01(AbstractEnemy *enemy);
	void shotPattern02(AbstractEnemy *enemy);
	void shotPattern03(AbstractEnemy *enemy);
	void shotPattern04(AbstractEnemy *enemy);
};

