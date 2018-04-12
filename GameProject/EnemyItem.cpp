#include "ItemManger.h"
#include "EnemyItem.h"
#include "Macro.h"
#include "Define.h"
#include "AbstractEnemy.h"


EnemyItem::EnemyItem()
{
	setFunction();
}

void EnemyItem::fall(AbstractEnemy * enemy)
{
	const unsigned int id = enemy->getItemPatternID();
	if (_itemPattern.size() <= id) {
		//ERR("fallID出错");
	}
	(this->*_itemPattern[id])(enemy);			//根据id移动
}

/*
将函数指针设置为列表
*/
void EnemyItem::setFunction()
{
	_itemPattern.push_back(&EnemyItem::itemPattern00);
	_itemPattern.push_back(&EnemyItem::itemPattern01);
	_itemPattern.push_back(&EnemyItem::itemPattern02);
	_itemPattern.push_back(&EnemyItem::itemPattern03);
	_itemPattern.push_back(&EnemyItem::itemPattern04);
}
/*无道具掉落*/
void EnemyItem::itemPattern00(AbstractEnemy * enemy)
{
}

//带有1p
void EnemyItem::itemPattern01(AbstractEnemy * enemy)
{

	const float x = enemy->getX();
	const float y = enemy->getY();
	addp(x, y);

}

//带有1蓝
void EnemyItem::itemPattern02(AbstractEnemy * enemy)
{

}

//带有3P
void EnemyItem::itemPattern03(AbstractEnemy * enemy)
{
	const float x = enemy->getX();
	const float y = enemy->getY();
	addP(x - 50 + rand() % 100, y - 30 + rand() % 80);
	addP(x - 50 + rand() % 100, y - 30 + rand() % 80);
	addP(x - 50 + rand() % 100, y - 30 + rand() % 80);
}

void EnemyItem::itemPattern04(AbstractEnemy * enemy)
{
	const float x = enemy->getX();
	const float y = enemy->getY();
	for (int i = 0; i < 5; i++) {
		addp(x + (rand() % 200 - 100), y + (rand() % 100 - 30));
	}
	for (int i = 0; i < 1; i++) {
		addP(x + (rand() % 200 - 10), y + (rand() % 100 - 30));
	}
	addup(x + (rand() % 200 - 100), y + (rand() % 100 - 30));
}



void EnemyItem::addp(float x, float y)
{
	if (Player::getPowerMax()) {
		ItemManger::add(x, y, -Define::PI / 2, 1);
	}
	else
	{
		ItemManger::add(x, y, -Define::PI / 2, 0);
	}
}

void EnemyItem::addP(float x, float y)
{
	if (Player::getPowerMax()) {
		ItemManger::add(x, y, -Define::PI / 2, 2);
	}
	else
	{
		ItemManger::add(x, y, -Define::PI / 2, 3);
	}
}
void EnemyItem::addup(float x, float y)
{
	ItemManger::add(x, y, -Define::PI / 2, 4);
}

