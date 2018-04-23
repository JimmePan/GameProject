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
						std::list<std::shared_ptr<AbstractEnemy>>::iterator>(i, s)) {		//�������						
						switch ((*i)->getKind())		//�����ӵ�����ȷ������������Ч
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

						(*i)->setFlag(0);			//�����ӵ�
						Global::getIns()->setScore(10);		//���ӷ���
						(*s)->setHp((*i)->getPower());		//�з���Ѫ
						enemy_death_judge(s);		//�ж��з��Ƿ�����
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
//	if ((*i)->getCount() > 0) { //�ӵ��Ѿ���������Ѿ������켣
//		float x = (*i)->getX() - (*s)->getX();		//���˺��Ի��ӵ�����
//		float y = (*i)->getY() - (*s)->getY();
//
//		float r = (*i)->getRange() + (*s)->getRange();	//���˵���ײ�ж����Ի�������ӵ�����ײ�ж��ĺϼƷ�Χ
//
//		if ((*i)->getSpeed() > r) {		//�뾶С���ٶȣ�����켣
//			//1֡ǰ��λ��
//			float pre_x = (*i)->getX() + cos((*i)->getAngle() + Define::PI)*(*i)->getSpeed();
//			float pre_y = (*i)->getY() + sin((*i)->getAngle() + Define::PI)*(*i)->getSpeed();
//			float px, py;
//			for (j = 0; j < (*i)->getSpeed() / r; j++) {			//ǰ���ķ���/��ײ�ж�������ѭ��
//				px = pre_x - (*s)->getX();
//				py = pre_y - (*s)->getY();
//				if (px*px + py * py < r*r)
//					return true;
//				pre_x += cos((*i)->getAngle())*r;
//				pre_y += sin((*i)->getAngle())*r;
//			}
//		}
//		if (x*x + y * y < r*r)//�������ײ�ж���Χ��
//			return true;//��ײ
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
		//for (i = 0; i<SHOT_MAX; i++) {//����������ѭ��
		//	if (shot[i].flag != 0) {//�����û�е�¼�ĵ�Ļ
		//		if (s == shot[i].num) {//�ҵ������Ѿ���¼�˵ĵ�Ļ
		//			shot[i].flag = 2;//�ı�flag�Ա�ʾ��Ļ���ټ���
		//			break;
		//		}
		//	}
		//}
	}
}


