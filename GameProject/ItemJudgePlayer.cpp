#include "ItemJudgePlayer.h"
#include "Define.h"
#include "CalcUtils.h"

ItemJudgePlayer::ItemJudgePlayer()
{
}

void ItemJudgePlayer::Judge(std::shared_ptr<ItemManger>& im, std::shared_ptr<Player>& p)
{
	if (p->getY() < Define::ITEM_GET_LINE) {	//�����ռ���,�ı�����ƶ�״̬
		CollectStatus(im);
	}

	for (auto i = im->getList()->begin(); i != im->getList()->end();) {
		if ((*i)->getFlag() > 0) {
			if ((*i)->getFlag() == 1) {
				int rate = p->getSlow() ? 22 : 10;
				float x = (*i)->getX() - p->getX();
				float y = (*i)->getY() - p->getY();
				float r = (*i)->getRange() + p->getRange()*rate;
				if (x*x + y * y < r*r) {
					(*i)->setFlag(3);		//���Ի������ƶ�
				}

			}
			if (CalcUtils::out_judge_shot(i, &p)) {		//ʰȡ
				int kind = (*i)->getKind();
				switch (kind)
				{
				case 0:case 3:
				{
					float before = p->getPower();
					if (before < Define::POWER_MAX) {		//С����������ʰȡ
						before + Define::ITEM_POWER[kind] >= Define::POWER_MAX ? p->setPower(Define::POWER_MAX) : p->addPower(Define::ITEM_POWER[kind]);
						if ((int)before < (int)p->getPower()) {
							//��1����������upЧ��
						}
						if (p->getPower() > Define::POWER_MAX - 0.001f)
							p->setPowerMax(true);
					}

					(*i)->setFlag(0);
				}
				case 1:
					(*i)->setFlag(0);
					break;
				case 2:
					(*i)->setFlag(0);
					break;
				case 4:
					(*i)->setFlag(0);
					break;
				case 5:
					(*i)->setFlag(0);
					break;
				case 6:
					(*i)->setFlag(0);
					break;
				case 7:
					(*i)->setFlag(0);
					break;
				default:
					break;
				}
			}


		}
		i++;
	}

}

void ItemJudgePlayer::CollectStatus(std::shared_ptr<ItemManger>& im)
{
	for (auto i = im->getList()->begin(); i != im->getList()->end();) {
		if ((*i)->getFlag() > 0) {
			(*i)->setFlag(7);		//ͬʱ�����ƶ��ٶ�
		}
		i++;
	}
}



