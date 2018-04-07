#pragma once

#include <vector>
#include <memory>

class AbstractEnemy;

class EnemyItem
{
public:
	EnemyItem();
	virtual ~EnemyItem() = default;
	void fall(AbstractEnemy* enemy);
private:
	typedef void(EnemyItem::*FUNC)(AbstractEnemy* enemy);
	std::vector<FUNC> _itemPattern;
	void setFunction();

	void itemPattern00(AbstractEnemy *enemy);
	void itemPattern01(AbstractEnemy *enemy);
	void itemPattern02(AbstractEnemy *enemy);
	void itemPattern03(AbstractEnemy *enemy);
	void itemPattern04(AbstractEnemy *enemy);

	void addp(float x,float y);
	void addP(float x, float y);
};