#include "EnemyShotJudgePlayer.h"
#include "Define.h"
#include "CalcUtils.h"

EnemyShotJudgePlayer::EnemyShotJudgePlayer()
{
}

void EnemyShotJudgePlayer::Judge(std::shared_ptr<BulletManager>& bullets, std::shared_ptr<Player>& p)
{
	for (auto i = bullets->getListSmall()->begin(); i != bullets->getListSmall()->end();) {
		JudgeBullet(i, p);
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

	if (p->getFlag() == 2 && p->getCount() == 1) {
		ClearBullet(bullets);
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
						p->setFlag(1);			//1�����ڽ��о������� 2���Ѿ����������µ��Ի����ڴ��¸�����
						p->setCount_0();
						//se_flag[3] = 1;//������

					}
				}
				break;
			case 1:case 3:case 9:				//��Բ״���ж�

				break;
			case 4:case 12:case 13:				//���ε��ж�

				break;
			default:
				break;
			}
		}


		if (p->getBomFlag()) {					//boom�����ж�
			switch ((*i)->getType())
			{
			case 0:case 2:case 5:case 6:case 7:case 8:case 10:case 11:case 14:case 15:	//Բ�ε��ж������Σ���������ΪԲ��
			{
				float x = (*i)->getX() - p->getX();		//���˺�boom����
				float y = (*i)->getY() - p->getY();
				float r = (*i)->getRange() + p->getBomRange();	//���˵���ײ�ж���boom��ײ�ж��ĺϼƷ�Χ
				if ((x*x + y * y < r*r) && ((*i)->getY() <= p->getY()) && (p->getMutekicnt() % 5 == 0 && p->getMutekicnt() % 10 !=0)) {	//��Բ�ж�����24�Σ�����̫��̫�ٶ�����Υ�͸У���Ȼ����Ҳ��
					(*i)->setFlag(0);
				}
			}
			break;
			case 1:case 3:case 9:						//��Բ״���ж�

				break;
			case 4:case 12:case 13:						//���ε��ж�

				break;
			default:
				break;
			}
		}
	}
}

void EnemyShotJudgePlayer::ClearBullet(std::shared_ptr<BulletManager>& bullets)
{
	for (auto i = bullets->getListSmall()->begin(); i != bullets->getListSmall()->end();) {
		if ((*i)->getFlag() > 0) {
			(*i)->setFlag(0);
		}
		i++;
	}
	for (auto i = bullets->getListNormal()->begin(); i != bullets->getListNormal()->end();) {
		if ((*i)->getFlag() > 0) {
			(*i)->setFlag(0);
		}
		i++;
	}
	for (auto i = bullets->getListBig()->begin(); i != bullets->getListBig()->end();) {
		if ((*i)->getFlag() > 0) {
			(*i)->setFlag(0);
		}
		i++;
	}
}

