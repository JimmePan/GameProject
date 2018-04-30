#include "EnemyItem.h"
#include "ItemManger.h"
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
	_itemPattern.push_back(&EnemyItem::itemPattern05);
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
	const float x = enemy->getX();
	const float y = enemy->getY();
	addb(x, y);
}

//带有1P
void EnemyItem::itemPattern03(AbstractEnemy * enemy)
{
	const float x = enemy->getX();
	const float y = enemy->getY();
	addP(x, y);
}
//5p5P
void EnemyItem::itemPattern04(AbstractEnemy * enemy)
{
	const float x = enemy->getX();
	const float y = enemy->getY();
	for (int i = 0; i < 5; i++) {
		addp(x, y);
	}
	for (int i = 0; i < 1; i++) {
		addP(x, y);
	}
	addup(x, y);
}
//5b
void EnemyItem::itemPattern05(AbstractEnemy * enemy) {
	const float x = enemy->getX();
	const float y = enemy->getY();
	for (int i = 0; i < 5; i++) {
		addb(x, y);
	}
}

void EnemyItem::addp(float x, float y)
{
	if (Player::getPowerMax()) {
		ItemManger::add(x + (rand() % 200 - 100) + 20.f, y + (rand() % 100 - 30), -Define::PI / 2, 1);
	}
	else
	{
		ItemManger::add(x + (rand() % 200 - 100) + 20.f, y + (rand() % 100 - 30), -Define::PI / 2, 0);
	}
}

void EnemyItem::addP(float x, float y)
{
	if (Player::getPowerMax()) {
		ItemManger::add(x + (rand() % 200 - 100) + 20.f, y + (rand() % 100 - 30), -Define::PI / 2, 2);
	}
	else
	{
		ItemManger::add(x + (rand() % 200 - 100) + 20.f, y + (rand() % 100 - 30), -Define::PI / 2, 3);
	}
}

void EnemyItem::addb(float x, float y)
{
	ItemManger::add(x + (rand() % 200 - 100) + 20.f, y + (rand() % 100 - 30), -Define::PI / 2, 1);
}

void EnemyItem::addup(float x, float y)
{
	ItemManger::add(x + (rand() % 200 - 100) + 20.f, y + (rand() % 100 - 30), -Define::PI / 2, 4);
	PlaySoundMem(Sound::getIns()->getBonus2(), DX_PLAYTYPE_BACK);
}

void EnemyItem::addUP(float x, float y)
{
	ItemManger::add(x + (rand() % 200 - 100) + 20.f, y + (rand() % 100 - 30), -Define::PI / 2, 6);
	PlaySoundMem(Sound::getIns()->getBonus(), DX_PLAYTYPE_BACK);
}

