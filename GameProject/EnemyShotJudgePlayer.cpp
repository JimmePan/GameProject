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
		if (p->getFlag() == 0) {				//��ͨ״̬�½��б����ж�
			switch ((*i)->getType())
			{
			case 0:case 2:case 5:case 6:case 7:case 8:case 10:case 11:case 14:case 15:	//Բ�ε��ж������Σ���������ΪԲ��
				if (CalcUtils::out_judge_shot(i, &p)) {
					(*i)->setFlag(0);//���ٵ�Ļ
									 /*������������ë�������۾�ϲ����Bײ��*/
					if (p->getFlag() == 0 && p->getMutekicnt() == 0) {	//״̬Ϊһ��״̬���Ҳ����޵�״̬��						
						p->setFlag(2);			//1�����ڽ��о������� 2���Ѿ����������µ��Ի����ڴ��¸�����
						p->setCount_0();
						//se_flag[3] = 1;//������
						//return;
					}
				}
				break;
			case 1:case 3:case 9:														//��Բ״���ж�

				break;
			case 4:case 12:case 13:														//���ε��ж�

				break;
			default:
				break;
			}
		}
	}
}

