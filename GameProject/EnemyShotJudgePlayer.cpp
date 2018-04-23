#include "EnemyShotJudgePlayer.h"
#include "Define.h"
#include "CalcUtils.h"
#include "ItemManger.h"
#include "Sound.h"
#include "Point.h"

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

	if (p->getFlag() == 2 && p->getCount() < 60) {
		CalcUtils::ClearBullet();
	}
}

void EnemyShotJudgePlayer::JudgeBullet(std::list<std::shared_ptr<Bullet>>::iterator & i, std::shared_ptr<Player>& p) {
	if ((*i)->getFlag() > 0) {
		if (p->getFlag() == 0) {				//��ͨ״̬�½��б����ж�
			switch ((*i)->getType())
			{
			case 0:case 1:case 2:case 3:case 5:case 6:case 7:case 8:case 9:case 10:case 11:case 14:case 15:case 16://Բ�ε��ж������Σ���������ΪԲ��
				if (CalcUtils::out_judge_shot(i, &p)) {
					miss(i,p);
				}
				break;
				//case 1:case 3:case 9:				//��Բ״���ж�	������ʵ��Э
				//	break;
			case 4:case 12:case 13:				//���ε��ж�
				if (CalcUtils::out_judge_shot_re(i, p)) {
					miss(i, p);
				}
				break;
			
			default:
				break;
			}
		}


		if (p->getBomFlag()) {					//boom�����ж�
			switch ((*i)->getType())
			{
			case 0:case 2:case 5:case 6:case 7:case 8:case 10:case 11:case 14:case 15:case 1:case 3:case 9:case 16:	//Բ�ε��ж������Σ���������ΪԲ��
			{
				float x = (*i)->getX() - p->getX();		//��Ļ��boom����
				float y = (*i)->getY() - p->getY();
				float r = (*i)->getRange() + p->getBomRange();	//��Ļ����ײ�ж���boom��ײ�ж��ĺϼƷ�Χ
				if ((p->getMutekicnt() % 5 == 0 && p->getMutekicnt() % 10 != 0) && (x*x + y * y < r*r) && ((*i)->getY() <= p->getY())) {	//��Բ�ж�����24�Σ�����̫��̫�ٶ�����Υ�͸У���Ȼ����Ҳ��
					(*i)->setFlag(0);
				}
			}
			break;
			//case 1:case 3:case 9:						//��Բ״���ж�

			//	break;
			case 4:case 12:case 13: {					//���ε��ж�
				Point a = CalcUtils::getApex(i, 0);	//(+,-)
				Point b = CalcUtils::getApex(i, 1);	//(+,+)
				Point c = CalcUtils::getApex(i, 2);	//(-,-)
				Point d = CalcUtils::getApex(i, 3);	//(-,+)
				float pl_y = p->getY();
				Point pl = Point(p->getX(), pl_y);
				float r = p->getBomRange();
				if ((p->getMutekicnt() % 5 == 0 && p->getMutekicnt() % 10 != 0)) {
					if (pl.distance(a) < r&&a.y <= pl_y) {
						(*i)->setFlag(0);
						return;
					}
					if (pl.distance(b) < r&&b.y <= pl_y) {
						(*i)->setFlag(0);
						return;
					}
					if (pl.distance(c) < r&&c.y <= pl_y) {
						(*i)->setFlag(0);
						return;
					}
					if (pl.distance(d) < r&&d.y <= pl_y) {
						(*i)->setFlag(0);
						return;
					}
				}
			}
				break;
			default:
				break;
			}
		}
	}
}

void EnemyShotJudgePlayer::miss(std::list<std::shared_ptr<Bullet>>::iterator & i, std::shared_ptr<Player>& p)
{
	(*i)->setFlag(0);//���ٵ�Ļ
					 /*������������ë�������۾�ϲ����Bײ��*/
	if (p->getFlag() == 0 && p->getMutekicnt() == 0) {	//״̬Ϊһ��״̬���Ҳ����޵�״̬��						
		p->setFlag(1);			//1�����ڽ��о������� 2���Ѿ����������µ��Ի����ڴ��¸�����
		p->setCount_0();
		PlaySoundMem(Sound::getIns()->getPlDead(), DX_PLAYTYPE_BACK);

	}
}
