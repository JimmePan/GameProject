#include "ItemJudgePlayer.h"
#include "Define.h"
#include "CalcUtils.h"

ItemJudgePlayer::ItemJudgePlayer()
{
}

void ItemJudgePlayer::Judge(std::shared_ptr<ItemManger>& im, std::shared_ptr<Player>& p)
{
	if (p->getY() < Define::ITEM_GET_LINE) {	//道具收集线,改变道具移动状态
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
					(*i)->setFlag(3);		//向自机加速移动
				}

			}
			if (CalcUtils::out_judge_shot(i, &p)) {		//拾取
				int kind = (*i)->getKind();
				switch (kind)
				{
				case 0:case 3:
				{
					float before = p->getPower();
					if (before < Define::POWER_MAX) {		//小于满火力，拾取
						before + Define::ITEM_POWER[kind] >= Define::POWER_MAX ? p->setPower(Define::POWER_MAX) : p->addPower(Define::ITEM_POWER[kind]);
						if ((int)before < (int)p->getPower()) {
							//满1火力，火力up效果
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
			(*i)->setFlag(7);		//同时设置移动速度
		}
		i++;
	}
}



