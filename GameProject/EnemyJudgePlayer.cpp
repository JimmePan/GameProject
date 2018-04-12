#include "EnemyJudgePlayer.h"
#include "Define.h"
#include "CalcUtils.h"
#include "PlayerShotJudgeEnemy.h"

EnemyJudgePlayer::EnemyJudgePlayer()
{
}

void EnemyJudgePlayer::Judge(std::shared_ptr<EnemyManager>& em, std::shared_ptr<Player>& p)
{
	for (auto i = em->getList()->begin(); i != em->getList()->end();) {
		if ((*i)->getFlag() > 0) {
			if (p->getFlag() == 0) {				//普通状态下进行体术判定
				if (CalcUtils::out_judge_shot(i, &p)) {
					/*决死处理（决个毛蛋死，咱就喜欢抱B撞）*/
					if (p->getFlag() == 1) {
						int x = 1;
					}
					if (p->getFlag() == 0 && p->getMutekicnt() == 0) {	//状态为一般状态，且不是无敌状态下						
						p->setFlag(1);			//1：正在进行决死处理 2：已经被击毁且新的自机正在从下浮起来
						p->setCount_0();
						//se_flag[3] = 1;//击毁声
					}
				}
			}
			if (p->getFlag() == 2 && p->getCount() == 1) {
				EnemyHpDe(em);//全敌方单位减血
			}
			if (p->getBomFlag()) {					//boom伤敌判定
				float x = (*i)->getX() - p->getX();		//敌人和boom距离
				float y = (*i)->getY() - p->getY();
				float r = (*i)->getRange() + p->getBomRange();	//敌人的碰撞判定和boom碰撞判定的合计范围
				if ((x*x + y * y < r*r) && ((*i)->getY() <= p->getY()) && (p->getMutekicnt() % 5 == 0)) {
					/*if (p->getMutekicnt() % 100 == 0) {		//boom碰撞特效
						EffectManager::addBoomEffect02((*i)->getX(), (*i)->getY());
					}*/
					(*i)->setHp(66);
					PlayerShotJudgeEnemy::enemy_death_judge(i);
				}


			}
		}
		i++;
	}
}

void EnemyJudgePlayer::EnemyHpDe(std::shared_ptr<EnemyManager>& em)
{
	for (auto i = em->getList()->begin(); i != em->getList()->end();) {
		if ((*i)->getFlag() > 0) {
			(*i)->setHp(300);
			PlayerShotJudgeEnemy::enemy_death_judge(i);
		}
		i++;
	}
}
