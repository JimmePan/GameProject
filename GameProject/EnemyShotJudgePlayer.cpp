#include "EnemyShotJudgePlayer.h"
#include "Define.h"
#include "CalcUtils.h"

EnemyShotJudgePlayer::EnemyShotJudgePlayer()
{
}

void EnemyShotJudgePlayer::Judge(std::shared_ptr<BulletManager>& bullets, std::shared_ptr<Player>& p)
{
	for (auto i = bullets->getListSmall()->begin(); i != bullets->getListSmall()->end();) {
		JudgeBullet(i,p);
		i++;
	}
	for (auto i = bullets->getListNormal()->begin(); i != bullets->getListNormal()->end();) {
		JudgeBullet(i, p);
		i++;
	}
	for (auto i = bullets->getListBig()->begin(); i != bullets->getListBig()->end();) {
		JudgeBullet(i, p);
		i++;
	}
}

void EnemyShotJudgePlayer::JudgeBullet(std::list<std::shared_ptr<Bullet>>::iterator & i, std::shared_ptr<Player>& p) {
	if ((*i)->getFlag() > 0) {
		if (p->getFlag() == 0) {				//普通状态下进行被弹判定
			switch ((*i)->getType())
			{
			case 0:case 2:case 5:case 6:case 7:case 8:case 10:case 11:case 14:case 15:	//圆形弹判定，星形，雨形暂列为圆形
				if (CalcUtils::out_judge_shot(i, &p)) {
					(*i)->setFlag(0);//销毁弹幕
									 /*决死处理（决个毛蛋死，咱就喜欢抱B撞）*/
					if (p->getFlag() == 0 && p->getMutekicnt() == 0) {	//状态为一般状态，且不是无敌状态下						
						p->setFlag(2);			//1：正在进行决死处理 2：已经被击毁且新的自机正在从下浮起来
						p->setCount_0();
						//se_flag[3] = 1;//击毁声
						//return;
					}
				}
				break;
			case 1:case 3:case 9:														//椭圆状弹判定

				break;
			case 4:case 12:case 13:														//矩形弹判定

				break;
			default:
				break;
			}
		}
	}
}

