#include "EnemyMover.h"
#include "Macro.h"
#include "Define.h"
#include "AbstractEnemy.h"
#include "Boss.h"


EnemyMover::EnemyMover()
{
	setFunction();
}

void EnemyMover::move(AbstractEnemy * enemy)
{
	const unsigned int id = enemy->getMovePatternID();
	if (_movePattern.size() <= id) {
		//ERR("moveID出错");
	}
	(this->*_movePattern[id])(enemy);	//根据id移动
	if (id == 4) {						//朝目标进行的匀减速运动
		if (phy._flag > 0) {
			float t = (float)phy._count;
			float a = phy.prex - ((phy.v0x*t) - 0.5f*phy.ax*t*t);
			float b = phy.prey - ((phy.v0y*t) - 0.5f*phy.ay*t*t);
			enemy->setX(phy.prex - ((phy.v0x*t) - 0.5f*phy.ax*t*t));//计算当前应当所在的x坐标
			enemy->setY(phy.prey - ((phy.v0y*t) - 0.5f*phy.ay*t*t));//计算当前应当所在的y坐标
			phy._count++;
		}
		if (phy._count >= phy._setTime) {//如果超过附加移动的时间的话
			phy._flag = 0;// 设置移动为无效

			return;
		}
	}
	else {

		enemy->setX(enemy->getX() + cos(enemy->getAngle())*enemy->getSpeed());
		enemy->setY(enemy->getY() + sin(enemy->getAngle())*enemy->getSpeed());
	}
}

void EnemyMover::moveWithConstantAcceleration(AbstractEnemy * enemy, float x, float y, int t) {
	enemy->setAngle(Define::PI / 2);
	float ymax_x, ymax_y;
	if (t == 0)t = 1;
	phy._flag = 1;//登录有效
	phy._count = 0;//计数器初始化
	phy._setTime = t;//设置附加移动时间
	ymax_x = enemy->getX() - x;//想要移动的水平距离
	phy.v0x = 2 * ymax_x / t;//水平分量的初速度
	phy.ax = 2 * ymax_x / (t*t);//水平分量的加速度
	phy.prex = enemy->getX();//初始x坐标
	ymax_y = enemy->getY() - y;//想要移动的竖直距离
	phy.v0y = 2 * ymax_y / t;//竖直分量的初速度
	phy.ay = 2 * ymax_y / (t*t);//数值分量的加速度
	phy.prey = enemy->getY();//初始y坐标
}

/*
将函数指针设置为列表
*/
void EnemyMover::setFunction()
{
	_movePattern.push_back(&EnemyMover::movePattern00);
	_movePattern.push_back(&EnemyMover::movePattern01);
	_movePattern.push_back(&EnemyMover::movePattern02);
	_movePattern.push_back(&EnemyMover::movePattern03);
	_movePattern.push_back(&EnemyMover::movePattern04);
	_movePattern.push_back(&EnemyMover::movePattern05);
	_movePattern.push_back(&EnemyMover::movePattern06);
}
/*向下，停顿后，向下*/
void EnemyMover::movePattern00(AbstractEnemy * enemy)
{
	const int cnt = enemy->getCounter();
	const int wait = 180;
	if (0 == cnt) {
		enemy->setAngle(Define::PI / 2);
		enemy->setSpeed(3);
	}
	if (60 < cnt && cnt <= 90) {
		enemy->setSpeed(enemy->getSpeed() - 0.1f);
	}
	if (cnt >= 150) {
		enemy->setAngle(Define::PI / 2);
		enemy->setSpeed(0);
	}
	/*if (90 + wait < cnt && cnt <= 90 + wait + 30) {
		enemy->setSpeed(enemy->getSpeed() + 0.1f);
	}*/
}
//左下移动
void EnemyMover::movePattern01(AbstractEnemy * enemy)
{
	int cnt = enemy->getCounter();
	if (0 == cnt) {
		enemy->setAngle(Define::PI * 3 / 4);
		enemy->setSpeed(4);
	}
	if (60 == cnt) {
		enemy->setAngle(0);
		enemy->setSpeed(4);
	}
	if (120 == cnt) {
		enemy->setAngle(Define::PI);
		enemy->setSpeed(4);
	}
	if (180 == cnt) {
		enemy->setAngle(Define::PI * 2 / 4);
		enemy->setSpeed(4);
	}
}
/*琪露诺1非移动*/
void EnemyMover::movePattern02(AbstractEnemy * enemy)
{
	int c = enemy->getBossCount() % 600;
	if (c < 240) {
		enemy->setAngle(Define::PI / 2);
		enemy->setSpeed(0);
	}
	else if (c < 270)
	{
		enemy->setAngle(0);
		enemy->setSpeed(10.0f - (10.0f / 30.0f*(c - 240)));
	}
	else if (c < 310)
	{
		enemy->setAngle(Define::PI + Define::PI / 6);
		enemy->setSpeed(6.0f - (6.0f / 40.0f*(c - 270)));
	}
	else if (c < 370)
	{
		enemy->setAngle(Define::PI / 2);
		enemy->setSpeed(0);
	}
	else if (c < 430)
	{
		enemy->setAngle(Define::PI - Define::PI / 8);
		enemy->setSpeed(8.0f - (8.0f / 60.0f*(c - 370)));
	}
	else if (c < 460)
	{
		enemy->setAngle(Define::PI / 2);
		enemy->setSpeed(0);
	}
	else if (c < 520)
	{
		enemy->setAngle(0);
		enemy->setSpeed(8.0f - (8.0f / 60.0f*(c - 460)));
	}
	else if (c < 540)
	{
		//enemy->setAngle(Define::PI / 2);
		enemy->setSpeed(0);
	}
	else if (c < 600)
	{
		enemy->setAngle(3.587);
		enemy->setSpeed(2.4f - (2.4f / 60.0f*(c - 540)));
	}

}
/*向右，停顿，微向左下，停顿，微向右上停顿，向左，停顿*/		//琪露诺完美冻结
void EnemyMover::movePattern03(AbstractEnemy * enemy)
{
	int c = enemy->getBossCount() % 1300;
	if (c < 80) {
		enemy->setAngle(0.f);
		enemy->setSpeed(5.f - (0.0625f*c));
	}
	else if (c < 200)
	{
		enemy->setAngle(Define::PI / 2);
		enemy->setSpeed(0);
	}
	else if (c < 280)
	{
		enemy->setAngle(Define::PI - Define::PI / 8);
		enemy->setSpeed(5.4f - (0.0676f*(c - 200)));
	}
	else if (c < 650)
	{
		enemy->setAngle(Define::PI / 2);
		enemy->setSpeed(0);
	}
	else if (c < 730)
	{
		enemy->setAngle(Define::PI + Define::PI / 8);
		enemy->setSpeed(5.4f - (0.0676f*(c - 650)));
	}
	else if (c < 850)
	{
		enemy->setAngle(Define::PI / 2);
		enemy->setSpeed(0);
	}
	else if (c < 930)
	{
		enemy->setAngle(0);
		enemy->setSpeed(5.f - (0.0625f*(c - 850)));
	}
	else if (c < 1300)
	{
		enemy->setAngle(Define::PI / 2);
		enemy->setSpeed(0);
	}
}
/*boss回归中心点*/
void EnemyMover::movePattern04(AbstractEnemy * enemy)
{
	if (enemy->getMoveFlag()) {
		moveWithConstantAcceleration(enemy, (float)Define::CENTER_X, 250.f, 60);
		enemy->setMoveFlag(false);
	}
}
/*琪露诺2非符移动*/
void EnemyMover::movePattern05(AbstractEnemy * enemy)
{
	int cnt = enemy->getBossCount();
	int c = enemy->getBossCount() % 200;
	if (cnt <= 70) {
		enemy->setAngle(Define::PI / 2);
		enemy->setSpeed(0);
		return;
	}
	if (cnt % 200 == 0 && (cnt / 200) % 4 <= 1) {
		enemy->setAngle(0.f + (float)(rand() / double(RAND_MAX)*Define::PI / 8) - Define::PI / 16);
	}
	if (cnt % 200 == 0 && (cnt / 200) % 4 > 1) {
		enemy->setAngle(Define::PI + (float)(rand() / double(RAND_MAX)*Define::PI / 8) - Define::PI / 16);
	}
	if (c < 70 && cnt>70) {
		enemy->setSpeed(4.f - (0.057f*c));
	}
	if (c == 70) {
		enemy->setAngle(Define::PI / 2);
		enemy->setSpeed(0);
	}
}
/*琪露诺2符卡移动*/
void EnemyMover::movePattern06(AbstractEnemy * enemy) {
	int cnt = enemy->getBossCount();
	int c = enemy->getBossCount() % 100;
	int r = Define::PI*(rand() % 2);
	if (cnt < 100) {
		enemy->setAngle(Define::PI / 2);
		enemy->setSpeed(0);
		return;
	}
	if (c == 0) {
		if (enemy->getX() < 200)
			r = 0;
		if (enemy->getX() > 700)
			r = 1;
		enemy->setAngle(Define::PI*r + (float)(rand() / double(RAND_MAX)*Define::PI / 8) - Define::PI / 16);
		enemy->setSpeed(3.f);
	}
	if (c < 60) {
		enemy->setSpeed(3.f - 0.05f*c);
	}
}