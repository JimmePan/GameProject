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
			if (p->getFlag() == 0) {				//��ͨ״̬�½��������ж�
				if (CalcUtils::out_judge_shot(i, &p)) {
					/*������������ë�������۾�ϲ����Bײ��*/
					if (p->getFlag() == 1) {
						int x = 1;
					}
					if (p->getFlag() == 0 && p->getMutekicnt() == 0) {	//״̬Ϊһ��״̬���Ҳ����޵�״̬��						
						p->setFlag(1);			//1�����ڽ��о������� 2���Ѿ����������µ��Ի����ڴ��¸�����
						p->setCount_0();
						PlaySoundMem(Sound::getIns()->getPlDead(), DX_PLAYTYPE_BACK);
					}
				}
			}
			if (p->getFlag() == 2 && p->getCount() == 1) {
				EnemyHpDe(em);//ȫ�з���λ��Ѫ
			}
			if (p->getBomFlag()) {					//boom�˵��ж�
				float x = (*i)->getX() - p->getX();		//���˺�boom����
				float y = (*i)->getY() - p->getY();
				float r = (*i)->getRange() + p->getBomRange();	//���˵���ײ�ж���boom��ײ�ж��ĺϼƷ�Χ
				if ((x*x + y * y < r*r) && ((*i)->getY() <= p->getY())) {
					if (p->getMutekicnt() % 30 >= 13 && p->getMutekicnt() % 30 <= 17) {		//boom��ײ��Ч
						EffectManager::addBoomEffect02((*i)->getX(), (*i)->getY(), (*i)->shotatan2());
					}
					if (p->getMutekicnt() % 5 == 0) {
						(*i)->setHp(66);
						PlayerShotJudgeEnemy::enemy_death_judge(i);
					}
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
