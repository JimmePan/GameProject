#include "EnemyMover.h"
#include "Macro.h"
#include "Define.h"
#include "AbstractEnemy.h"
#include "EnemyManager.h"


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
	_movePattern.push_back(&EnemyMover::movePattern07);
	_movePattern.push_back(&EnemyMover::movePattern08);
	_movePattern.push_back(&EnemyMover::movePattern09);
	_movePattern.push_back(&EnemyMover::movePattern10);
	_movePattern.push_back(&EnemyMover::movePattern11);
	_movePattern.push_back(&EnemyMover::movePattern12);
	_movePattern.push_back(&EnemyMover::movePattern13);
	_movePattern.push_back(&EnemyMover::movePattern14);
	_movePattern.push_back(&EnemyMover::movePattern15);
	_movePattern.push_back(&EnemyMover::movePattern16);
	_movePattern.push_back(&EnemyMover::movePattern17);
	_movePattern.push_back(&EnemyMover::movePattern18);
	_movePattern.push_back(&EnemyMover::movePattern19);
	_movePattern.push_back(&EnemyMover::movePattern20);
	_movePattern.push_back(&EnemyMover::movePattern21);
	_movePattern.push_back(&EnemyMover::movePattern22);
	_movePattern.push_back(&EnemyMover::movePattern23);
	_movePattern.push_back(&EnemyMover::movePattern24);
	_movePattern.push_back(&EnemyMover::movePattern25);
	_movePattern.push_back(&EnemyMover::movePattern26);
	_movePattern.push_back(&EnemyMover::movePattern27);
	_movePattern.push_back(&EnemyMover::movePattern28);
	_movePattern.push_back(&EnemyMover::movePattern29);
	_movePattern.push_back(&EnemyMover::movePattern30);
	_movePattern.push_back(&EnemyMover::movePattern31);
	_movePattern.push_back(&EnemyMover::movePattern32);
	_movePattern.push_back(&EnemyMover::movePattern33);
}
/*不动*/
void EnemyMover::movePattern00(AbstractEnemy * enemy)
{
	//const int cnt = enemy->getCounter();
	//const int wait = 180;
	//if (0 == cnt) {
	//	enemy->setAngle(Define::PI / 2);
	//	enemy->setSpeed(3);
	//}
	//if (60 < cnt && cnt <= 90) {
	//	enemy->setSpeed(enemy->getSpeed() - 0.1f);
	//}
	//if (cnt >= 150) {
	//	enemy->setAngle(Define::PI / 2);
	//	enemy->setSpeed(0);
	//}
	///*if (90 + wait < cnt && cnt <= 90 + wait + 30) {
	//	enemy->setSpeed(enemy->getSpeed() + 0.1f);
	//}*/
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
		enemy->setAngle(3.587f);
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
	int r = (int)Define::PI*(rand() % 2);
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
/*道中0阶段妖精移动1，偏左*/
void EnemyMover::movePattern07(AbstractEnemy * enemy) {
	int cnt = enemy->getCount();
	if (cnt == 0)
	{
		enemy->setAngle(Define::PI / 2 + 0.15f);
		enemy->setSpeed(5.0f);
		return;
	}
	if (cnt >= 50 && cnt < 60) {
		enemy->setSpeed(enemy->getSpeed() - 0.5f);
		return;
	}
	if (cnt == 60) {
		enemy->setAngle(Define::PI / 2);
		enemy->setSpeed(0.f);
		return;
	}
	if (cnt >= 110 && cnt < 130) {
		enemy->setSpeed(enemy->getSpeed() + 0.2f);
		return;
	}
}
/*道中0阶段妖精移动2，偏右*/
void EnemyMover::movePattern08(AbstractEnemy * enemy) {
	int cnt = enemy->getCount();
	if (cnt == 0)
	{
		enemy->setAngle(Define::PI / 2 - 0.15f);
		enemy->setSpeed(5.0f);
		return;
	}
	if (cnt >= 50 && cnt < 60) {
		enemy->setSpeed(enemy->getSpeed() - 0.5f);
		return;
	}
	if (cnt == 60) {
		enemy->setAngle(Define::PI / 2);
		enemy->setSpeed(0.f);
		return;
	}
	if (cnt >= 110 && cnt < 130) {
		enemy->setSpeed(enemy->getSpeed() + 0.2f);
		return;
	}
}
/*道中0阶段大妖精，进场停止两侧退场*/
void EnemyMover::movePattern09(AbstractEnemy * enemy) {
	int cnt = enemy->getCount();
	if (cnt == 0)
	{
		enemy->setAngle(Define::PI / 2);
		enemy->setSpeed(4.0f);
		return;
	}
	if (cnt >= 60 && cnt < 80) {
		enemy->setSpeed(enemy->getSpeed() - 0.2f);
		return;
	}
	if (cnt == 80) {
		enemy->setSpeed(0.f);
		return;
	}
	if (cnt == 320) {
		if (enemy->getX() < Define::CENTER_X) {
			enemy->setSpeed(3.f);
			enemy->setAngle(Define::PI);
		}
		else
		{
			enemy->setSpeed(3.f);
			enemy->setAngle(0.f);
		}
	}
}
/*道中1阶段妖精移动01*/
void EnemyMover::movePattern10(AbstractEnemy * enemy) {
	int cnt = enemy->getCount();
	if (cnt == 0)
	{
		enemy->setAngle(Define::PI / 2);
		enemy->setSpeed(5.5f);
		return;
	}
	if (cnt >= 30 && cnt < 102) {
		enemy->setAngle(enemy->getAngle() + Define::PI / 144);
		return;
	}
	if (cnt == 102) {
		enemy->setAngle(Define::PI);
		enemy->setSpeed(5.5f);
	}
}
/*道中2阶段妖精移动01*/
void EnemyMover::movePattern11(AbstractEnemy * enemy) {
	int cnt = enemy->getCount();
	if (cnt == 0)
	{
		enemy->setAngle(3 * Define::PI / 2);
		enemy->setSpeed(5.2f);
		return;
	}
	if (cnt >= 120 && cnt < 240) {
		enemy->setAngle(enemy->getAngle() - Define::PI / 144);
		enemy->setSpeed(enemy->getSpeed() - (float)1 / 48);
		return;
	}
	if (cnt == 240) {
		enemy->setAngle(2 * Define::PI / 3);
		enemy->setSpeed(2.7f);
	}
}
/*道中2阶段妖精移动02*/
void EnemyMover::movePattern12(AbstractEnemy * enemy) {
	int cnt = enemy->getCount();
	if (cnt == 0)
	{
		enemy->setAngle(Define::PI*2.f);
		enemy->setSpeed(6.f);
		return;
	}
	if (cnt >= 60 && cnt < 160) {
		enemy->setAngle(enemy->getAngle() - Define::PI / 120);
		enemy->setSpeed(enemy->getSpeed() - (float)1 / 40);
		return;
	}
	if (cnt == 160) {
		enemy->setAngle(7 * Define::PI / 6);
		enemy->setSpeed(3.5f);
	}
}
/*道中2阶段妖精移动03*/
void EnemyMover::movePattern13(AbstractEnemy * enemy) {
	int cnt = enemy->getCount();
	if (cnt == 0)
	{
		enemy->setAngle(Define::PI / 2);
		enemy->setSpeed(4.5f);
		return;
	}
	if (cnt >= 20 && cnt < 90) {
		enemy->setAngle(enemy->getAngle() - Define::PI / 140);
		return;
	}
	if (cnt == 90) {
		enemy->setAngle(0.f);
	}
}
/*道中2阶段大妖精移动01*/
void EnemyMover::movePattern14(AbstractEnemy * enemy) {
	int cnt = enemy->getCount();
	if (cnt == 0)
	{
		enemy->setAngle(Define::PI / 2);
		enemy->setSpeed(5.0f);
		return;
	}
	if (cnt >= 40 && cnt < 60) {
		enemy->setSpeed(enemy->getSpeed() - 0.25f);
		return;
	}
	if (cnt == 60) {
		enemy->setSpeed(0.f);
		return;
	}
	if (cnt == 400) {
		if (enemy->getX() < Define::CENTER_X) {
			enemy->setAngle(3 * Define::PI / 2 - Define::PI / 16);
		}
		else
		{
			enemy->setAngle(3 * Define::PI / 2 + Define::PI / 16);
		}
		return;
	}
	if (cnt > 400 && cnt <= 420) {
		enemy->setSpeed(enemy->getSpeed() + 0.15f);
	}
}
/*道中3阶段妖精移动01*/
void EnemyMover::movePattern15(AbstractEnemy * enemy)
{
	int cnt = enemy->getCount();
	if (cnt == 0)
	{
		if (enemy->getY() > Define::CENTER_Y) {
			enemy->setSpeed(4.2f);
			enemy->setAngle(3 * Define::PI / 2);

		}
		else
		{
			enemy->setSpeed(4.0f);
			enemy->setAngle(Define::PI / 2);
		}
		return;
	}
}
/*道中3阶段妖精移动02*/
void EnemyMover::movePattern16(AbstractEnemy * enemy)
{
	int cnt = enemy->getCount();
	if (cnt == 0)
	{
		if (enemy->getX() > Define::CENTER_X) {
			enemy->setSpeed(3.5f);
			enemy->setAngle(Define::PI);

		}
		else
		{
			enemy->setSpeed(3.5f);
			enemy->setAngle(0.f);
		}
		return;
	}
}
/*道中3阶段妖精移动03*/
void EnemyMover::movePattern17(AbstractEnemy * enemy)
{
	int cnt = enemy->getCount();
	if (cnt == 0)
	{
		if (enemy->getX() > Define::CENTER_X) {
			enemy->setAngle(Define::PI);
		}
		else {
			enemy->setAngle(0.f);
		}
		enemy->setSpeed(6.f);
		return;
	}
	if (cnt >= 10 && cnt < 140) {
		if (enemy->getX() > Define::CENTER_X) {
			enemy->setAngle(enemy->getAngle() + Define::PI / 156);
		}
		else
		{
			enemy->setAngle(enemy->getAngle() - Define::PI / 156);
		}
		enemy->setSpeed(enemy->getSpeed() - 0.023f);
		return;
	}

}
/*道中3阶段大妖精移动01*/
void EnemyMover::movePattern18(AbstractEnemy * enemy)
{
	int cnt = enemy->getCount();
	if (cnt == 0)
	{
		enemy->setSpeed(6.0f);
		enemy->setAngle(Define::PI / 2);
		return;
	}
	if (cnt < 60) {
		enemy->setSpeed(6.0f - cnt * 0.1f);
	}
	if (cnt == 60) {
		enemy->setSpeed(0.f);
	}
	if (cnt == 390) {
		enemy->setSpeed(5.f);
	}
}
/*道中3阶段妖精移动04*/
void EnemyMover::movePattern19(AbstractEnemy * enemy)
{
	int cnt = enemy->getCount();
	if (cnt == 0)
	{
		enemy->setSpeed(12.f);
		enemy->setAngle(Define::PI / 8);
		return;
	}
	if (cnt >= 30 && cnt < 90) {
		enemy->setAngle(enemy->getAngle() + 7 * Define::PI / 480);
		if (cnt >= 60) {
			enemy->setSpeed(enemy->getSpeed() - 0.4f);
		}
		return;
	}
	if (cnt == 90) {
		enemy->setSpeed(0.0f);
		enemy->setAngle(Define::PI);
	}
	if (cnt > 90 && cnt <= 150) {
		enemy->setAngle(enemy->getAngle() + Define::PI / 80);
		if (cnt <= 120) {
			enemy->setSpeed(enemy->getSpeed() + 0.4f);
		}
	}
}
/*道中3阶段妖精移动05*/
void EnemyMover::movePattern20(AbstractEnemy * enemy)
{
	int cnt = enemy->getCount();
	if (cnt == 0)
	{
		enemy->setSpeed(12.0f);
		enemy->setAngle(7 * Define::PI / 8);
		return;
	}
	if (cnt >= 30 && cnt < 90) {
		enemy->setAngle(enemy->getAngle() - 7 * Define::PI / 480);
		if (cnt >= 60) {
			enemy->setSpeed(enemy->getSpeed() - 0.4f);
		}
		return;
	}
	if (cnt == 90) {
		enemy->setSpeed(0.0f);
		enemy->setAngle(0.f);
	}
	if (cnt > 90 && cnt <= 150) {
		enemy->setAngle(enemy->getAngle() - Define::PI / 80);
		if (cnt <= 120) {
			enemy->setSpeed(enemy->getSpeed() + 0.4f);
		}
	}
}
/*道中4阶段毛玉移动01*/
void EnemyMover::movePattern21(AbstractEnemy * enemy)
{
	int cnt = enemy->getCount();
	if (cnt == 60)
	{
		enemy->setSpeed(0.f);
		enemy->setAngle(atan2(430 - enemy->getY(), 380 - enemy->getX()) + Define::PI / 2);
		return;
	}
	if (cnt <= 240) {
		enemy->setSpeed(enemy->getSpeed() + 1.f / 30);
		enemy->setAngle(enemy->getAngle() - Define::PI / 180);
	}
	if (cnt == 240) {
		enemy->setSpeed(enemy->getSpeed() + 1.5f);
	}
	if (cnt > 240 && cnt < 300) {
		enemy->setAngle(enemy->getAngle() - Define::PI / 48);
	}

}
/*道中4阶段毛玉移动02*/
void EnemyMover::movePattern22(AbstractEnemy * enemy)
{
	int cnt = enemy->getCount();
	if (cnt == 60)
	{
		enemy->setSpeed(0.f);
		enemy->setAngle(atan2(430 - enemy->getY(), 380 - enemy->getX()) - Define::PI / 2);
		return;
	}
	if (cnt <= 240) {
		enemy->setSpeed(enemy->getSpeed() + 1.f / 30);
		enemy->setAngle(enemy->getAngle() + Define::PI / 180);
	}
	if (cnt == 240) {
		enemy->setSpeed(4.f);
	}
	if (cnt > 240 && cnt < 300) {
		enemy->setSpeed(enemy->getSpeed() + 1.0f / 30);
		enemy->setAngle(enemy->getAngle() + Define::PI / 52);
	}

}
/*道中5阶段妖精移动01*/
void EnemyMover::movePattern23(AbstractEnemy * enemy) {
	int cnt = enemy->getCount();
	if (cnt == 0)
	{
		enemy->setSpeed(5.f);
		enemy->setAngle(Define::PI / 2);
		return;
	}
	if (cnt >= 30 && cnt < 40) {
		enemy->setSpeed(enemy->getSpeed() - 0.5f);
	}
	if (cnt == 40) {
		enemy->setSpeed(0.f);
	}
	if (cnt == 80) {
		enemy->setAngle(0.f);
		enemy->setSpeed(2.f);
	}

}
/*道中5阶段妖精移动02*/
void EnemyMover::movePattern24(AbstractEnemy * enemy) {
	int cnt = enemy->getCount();
	if (cnt == 0)
	{
		enemy->setSpeed(5.f);
		enemy->setAngle(Define::PI / 2);
		return;
	}
	if (cnt >= 30 && cnt < 40) {
		enemy->setSpeed(enemy->getSpeed() - 0.5f);
	}
	if (cnt == 40) {
		enemy->setSpeed(0.f);
		return;
	}
	if (cnt == 80) {
		enemy->setAngle(Define::PI);
		enemy->setSpeed(2.f);
	}
}
/*道中5阶段妖精移动03*/
void EnemyMover::movePattern25(AbstractEnemy * enemy) {
	int cnt = enemy->getCount();
	if (cnt == 0)
	{
		enemy->setSpeed(4.f);
		enemy->setAngle(Define::PI / 2);
		return;
	}
	if (cnt >= 30 && cnt < 50) {
		enemy->setSpeed(enemy->getSpeed() - 0.2f);
	}
	if (cnt == 50) {
		enemy->setSpeed(0.f);
		return;
	}
	if (cnt == 80) {
		enemy->setSpeed(2.5f);
	}
}
/*道中5阶段妖精移动04*/
void EnemyMover::movePattern26(AbstractEnemy * enemy) {
	int cnt = enemy->getCount();
	if (cnt == 0)
	{
		enemy->setSpeed(6.f);
		enemy->setAngle(enemy->shotatan2());
		return;
	}
	if (cnt >= 80 && cnt < 100) {
		enemy->setSpeed(enemy->getSpeed() - 0.3f);
	}
	if (cnt == 100) {
		enemy->setSpeed(0.f);
		enemy->setAngle(-enemy->shotatan2());
	}
	if (cnt >= 120 && cnt < 140) {
		enemy->setSpeed(enemy->getSpeed() + 0.2f);
	}
}
/*道中6阶段阴阳玉移动01*/
void EnemyMover::movePattern27(AbstractEnemy * enemy) {
	int cnt = enemy->getCount();
	if (cnt == 0)
	{
		enemy->setSpeed(4.f);
		enemy->setAngle(Define::PI / 2);
		return;
	}
	if (cnt >= 80 && cnt < 140) {
		if (enemy->getX() > Define::CENTER_X) {
			enemy->setAngle(enemy->getAngle() + Define::PI / 80);
		}
		else
		{
			enemy->setAngle(enemy->getAngle() - Define::PI / 80);
		}
		enemy->setSpeed(6.f);
	}
	if (cnt == 140) {
		if (enemy->getX() > Define::CENTER_X) {
			enemy->setAngle(5 * Define::PI / 4);
		}
		else
		{
			enemy->setAngle(-Define::PI / 4);
		}
		enemy->setSpeed(8.f);
	}
}
/*道中6阶段阴阳玉移动02*/
void EnemyMover::movePattern28(AbstractEnemy * enemy) {
	int cnt = enemy->getCount();
	if (cnt == 0)
	{
		enemy->setSpeed(4.f);
		enemy->setAngle(Define::PI / 2);
		return;
	}
	if (cnt >= 60) {
		if (enemy->getX() > Define::CENTER_X) {
			enemy->setAngle(enemy->getAngle() - Define::PI / 128);
		}
		else
		{
			enemy->setAngle(enemy->getAngle() + Define::PI / 128);
		}
		enemy->setSpeed(enemy->getSpeed() + 0.08f);
	}
}
/*道中6阶段大妖精移动01*/
void EnemyMover::movePattern29(AbstractEnemy * enemy) {
	int cnt = enemy->getCount();
	if (cnt == 0)
	{
		enemy->setSpeed(4.f);
		enemy->setAngle(Define::PI / 2);
		return;
	}
	if (cnt >= 40 && cnt < 60) {
		enemy->setSpeed(enemy->getSpeed() - 0.2f);
	}
	if (cnt == 60) {
		enemy->setSpeed(0.f);
	}
}
/*小伞1非1符*/
void EnemyMover::movePattern30(AbstractEnemy * enemy) {
	int cnt = enemy->getBossCount();
	int c = enemy->getBossCount() % 120;
	int r = (int)Define::PI*(rand() % 2);
	if (cnt < 60) {
		enemy->setAngle(Define::PI / 2);
		enemy->setSpeed(0);
		return;
	}
	if (c == 60) {
		if (enemy->getX() < 200)
			r = 0;
		if (enemy->getX() > 700)
			r = 1;
		enemy->setAngle(Define::PI*r + (float)(rand() / double(RAND_MAX)*Define::PI / 8) - Define::PI / 16);
		enemy->setSpeed(3.f);
	}
	if (c > 60 && c <= 100) {

		enemy->setSpeed(enemy->getSpeed() - 0.075f);
	}
}
/*小伞2非2符*/
void EnemyMover::movePattern31(AbstractEnemy * enemy) {
	int cnt = enemy->getBossCount();
	int c = enemy->getBossCount() % 150;
	int r = (int)Define::PI*(rand() % 2);
	if (cnt < 40) {
		enemy->setAngle(Define::PI / 2);
		enemy->setSpeed(0);
		return;
	}
	if (c == 40) {
		if (enemy->getX() < 200)
			r = 0;
		if (enemy->getX() > 700)
			r = 1;
		enemy->setAngle(Define::PI*r + (float)(rand() / double(RAND_MAX)*Define::PI / 8) - Define::PI / 16);
		enemy->setSpeed(4.f);
	}
	if (c > 40 && c <= 120) {

		enemy->setSpeed(enemy->getSpeed() - 0.05f);
	}
}
/*小伞3符UFO*/
void EnemyMover::movePattern32(AbstractEnemy * enemy)
{
	float x = (*EnemyManager::getList()->begin())->getX();
	float y = (*EnemyManager::getList()->begin())->getY();	//圆心坐标

	enemy->setX(x + 75.f * cos(2 * Define::PI / 120 * (enemy->getCount() % 120) + enemy->getType()*Define::PI / 2));
	enemy->setY(y + 75.f * sin(2 * Define::PI / 120 * (enemy->getCount() % 120) + enemy->getType()*Define::PI / 2));
}
/*小伞3非*/
void EnemyMover::movePattern33(AbstractEnemy * enemy) {
	int cnt = enemy->getBossCount();
	if (cnt == 10)
	{
		enemy->setSpeed(4.5f);
		enemy->setAngle(Define::PI / 2);
		return;
	}
	if (cnt <= 60) {
		enemy->setSpeed(enemy->getSpeed() - 0.09f);
	}
	if (cnt == 60) {
		enemy->setSpeed(0.f);
	}
}