#include "PlayerShotJudgeEnemy.h"
#include "Define.h"
#include "CalcUtils.h"
#include "Sound.h"
#include "Global.h"

PlayerShotJudgeEnemy::PlayerShotJudgeEnemy()
{
}

void PlayerShotJudgeEnemy::Judge(std::shared_ptr<PlayerShotManager> &playShots, std::shared_ptr<EnemyManager> &enemys)
{

	for (auto i = playShots->getList()->begin(); i != playShots->getList()->end();) {
		if ((*i)->getFlag() > 0) {
			for (auto s = enemys->getList()->begin(); s != enemys->getList()->end();) {
				if ((*s)->getFlag() > 0) {
					if (CalcUtils::out_judge_shot<std::list<std::shared_ptr<PlayerShot>>::iterator,
						std::list<std::shared_ptr<AbstractEnemy>>::iterator>(i, s)) {		//如果击中						
						switch ((*i)->getKind())		//根据子弹类型确定击中类型特效
						{
						case 0:
							EffectManager::addShotEnemyEffect01((*i)->getX(), (*s)->getY() - (*s)->getRange() / 2);
							if ((*s)->getBoss() && (*s)->getHp() <= 2000) {
								PlaySoundMem(Sound::getIns()->getEnDamage01(), DX_PLAYTYPE_BACK);
							}
							else
							{
								PlaySoundMem(Sound::getIns()->getEnDamage00(), DX_PLAYTYPE_BACK);
							}
							break;
						case 1:
							EffectManager::addShotEnemyEffect02((*i)->getX(), (*s)->getY());
						default:
							break;
						}

						(*i)->setFlag(0);			//消除子弹
						Global::getIns()->setScore(10);		//增加分数
						(*s)->setHp((*i)->getPower());		//敌方减血
						enemy_death_judge(s);		//判定敌方是否死亡
					}
				}
				s++;
			}
		}
		i++;
	}
}


//bool PlayerShotJudgeEnemy::out_judge_shot(std::list<std::shared_ptr<PlayerShot>>::iterator & i,
//	std::list<std::shared_ptr<AbstractEnemy>>::iterator & s)
//{
//	int j;
//	if ((*i)->getCount() > 0) { //子弹已经射出，即已经产生轨迹
//		float x = (*i)->getX() - (*s)->getX();		//敌人和自机子弹距离
//		float y = (*i)->getY() - (*s)->getY();
//
//		float r = (*i)->getRange() + (*s)->getRange();	//敌人的碰撞判定和自机射击的子弹的碰撞判定的合计范围
//
//		if ((*i)->getSpeed() > r) {		//半径小于速度，计算轨迹
//			//1帧前的位置
//			float pre_x = (*i)->getX() + cos((*i)->getAngle() + Define::PI)*(*i)->getSpeed();
//			float pre_y = (*i)->getY() + sin((*i)->getAngle() + Define::PI)*(*i)->getSpeed();
//			float px, py;
//			for (j = 0; j < (*i)->getSpeed() / r; j++) {			//前进的分量/碰撞判定分量次循环
//				px = pre_x - (*s)->getX();
//				py = pre_y - (*s)->getY();
//				if (px*px + py * py < r*r)
//					return true;
//				pre_x += cos((*i)->getAngle())*r;
//				pre_y += sin((*i)->getAngle())*r;
//			}
//		}
//		if (x*x + y * y < r*r)//如果在碰撞判定范围内
//			return true;//碰撞
//
//	}
//	return false;
//}



void PlayerShotJudgeEnemy::enemy_death_judge(std::list<std::shared_ptr<AbstractEnemy>>::iterator & s)
{
	//int i;
	if ((*s)->getBoss()) {
		return;
	}
	if ((*s)->getHp() < 0) {
		EffectManager::addEnemyDelEffect((*s)->getX(), (*s)->getY(), (*s)->getType());
		EffectManager::addEnemyDelEffect2((*s)->getX(), (*s)->getY(), (*s)->getType());
		(*s)->setFlag(0);
		PlaySoundMem(Sound::getIns()->getEnBreak00(), DX_PLAYTYPE_BACK);
		//for (i = 0; i<SHOT_MAX; i++) {//敌人总数次循环
		//	if (shot[i].flag != 0) {//如果有没有登录的弹幕
		//		if (s == shot[i].num) {//且敌人有已经登录了的弹幕
		//			shot[i].flag = 2;//改变flag以表示弹幕不再继续
		//			break;
		//		}
		//	}
		//}
	}
}


